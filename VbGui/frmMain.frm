VERSION 5.00
Begin VB.Form frmMain 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Interop GUI"
   ClientHeight    =   2655
   ClientLeft      =   11400
   ClientTop       =   6255
   ClientWidth     =   3150
   LinkTopic       =   "frmMain"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2655
   ScaleWidth      =   3150
   Begin VB.CheckBox chkSaveCreds 
      Caption         =   "Save credentials"
      Enabled         =   0   'False
      Height          =   195
      Left            =   360
      TabIndex        =   5
      Top             =   1800
      Width           =   2415
   End
   Begin VB.CommandButton btnLogIn 
      Caption         =   "Sign In"
      Height          =   375
      Left            =   1080
      TabIndex        =   4
      Top             =   2160
      Width           =   975
   End
   Begin VB.TextBox txtPassword 
      BackColor       =   &H80000016&
      Enabled         =   0   'False
      Height          =   375
      IMEMode         =   3  'DISABLE
      Left            =   360
      PasswordChar    =   "*"
      TabIndex        =   3
      Top             =   1320
      Width           =   2415
   End
   Begin VB.TextBox txtUsername 
      BackColor       =   &H80000016&
      Enabled         =   0   'False
      Height          =   375
      Left            =   360
      TabIndex        =   1
      Top             =   600
      Width           =   2415
   End
   Begin VB.Label lblPassword 
      Caption         =   "Password:"
      Height          =   255
      Left            =   360
      TabIndex        =   2
      Top             =   1080
      Width           =   1455
   End
   Begin VB.Label lblLogin 
      Caption         =   "Username: "
      Height          =   255
      Left            =   360
      TabIndex        =   0
      Top             =   360
      Width           =   1575
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
    Private Declare Sub Encrypt Lib "InteropCryptCppDll" (ByVal szText As String)
    Private Declare Sub Decrypt Lib "InteropCryptCppDll" (ByVal szText As String)
    Dim g_strConnectionString As String
    Dim g_lProvType As Long
Private Function Registry_Read(Key_Path, Key_Name) As Variant

On Error Resume Next

Dim Registry As Object
Set Registry = CreateObject("WScript.Shell")
Registry_Read = Registry.RegRead(Key_Path & Key_Name)
End Function

Private Sub Registry_WriteString(Key_Path, Key_Name, Key_Value)

On Error Resume Next

Dim Registry As Object
Set Registry = CreateObject("WScript.Shell")
Registry.RegWrite Key_Path & Key_Name, Key_Value, "REG_SZ"
End Sub

Private Sub Registry_WriteDword(Key_Path, Key_Name, Key_Value)

On Error Resume Next

Dim Registry As Object
Set Registry = CreateObject("WScript.Shell")
Registry.RegWrite Key_Path & Key_Name, Key_Value, "REG_DWORD"
End Sub

Private Sub Registry_DeleteKey(Key_Path, Key_Name)

On Error Resume Next

Dim Registry As Object
Set Registry = CreateObject("WScript.Shell")
Registry.RegDelete Key_Path & Key_Name
End Sub


Private Sub btnLogIn_Click()
    Dim strAppTitle As String
    Dim strUsernameMiss As String
    Dim strPasswordMiss As String
    Dim strPassword As String
    Dim strConnStr As String
    Dim objCppConnect As New Connect
    Dim objCsConnect As New IConnectClass
    
   On Error GoTo btnLogIn_Click_Error

    strAppTitle = LoadResString(101)
    strUsernameMiss = LoadResString(102)
    strPasswordMiss = LoadResString(103)
    
    strConnStr = g_strConnectionString
    If (txtPassword.Enabled = True) Then
    
        If txtUsername.Text = "" Then
            MsgBox strUsernameMiss, vbOKOnly, strAppTitle
            Exit Sub
        End If
    
        If txtPassword.Text = "" Then
            MsgBox strPasswordMiss, vbOKOnly, strAppTitle
            Exit Sub
        End If
        
        strConnStr = strConnStr & "User Id=" & txtUsername.Text & ";" & "Password=" & txtPassword.Text & ";"
    Else
        strConnStr = strConnStr & "Integrated Security=SSPI;"
    End If
    
    If (g_lProvType = 0) Then
        strConnStr = strConnStr & "Provider=SQLOLEDB.1;"
        objCppConnect.Connect strConnStr
    Else
        objCsConnect.Connect strConnStr
    End If

   On Error GoTo 0
   Exit Sub

btnLogIn_Click_Error:

    MsgBox "Error " & Err.Number & " (" & Err.Description & ") in procedure btnLogIn_Click of Form frmMain"
    
End Sub


Private Sub Form_Load()
  
    Dim strRegPath As String
    Dim strConnStr As String
    Dim strPassword As String
    Dim lConnType As Long
    Dim lSaveCreds As Long
    Dim lProvType As Long
    
    On Error GoTo LABEL_ERROR
    GoTo LABEL_SUCCESS
    
LABEL_ERROR:

    MsgBox "Error: " & Err.Number & vbNewLine & "Description: " & Err.Description, vbCritical, LoadResString(101)
    Exit Sub
    
LABEL_SUCCESS:
    
    strRegPath = LoadResString(105)

    lSaveCreds = Registry_Read(strRegPath, "SaveCredentials")
    lConnType = Registry_Read(strRegPath, "ConnectionType")
    g_lProvType = Registry_Read(strRegPath, "ProviderType")
    g_strConnectionString = Registry_Read(strRegPath, "ConnectionString")
    
    If lConnType = 1 Then
        txtUsername.Enabled = True
        txtUsername.BackColor = &H80000005
        txtPassword.Enabled = True
        txtPassword.BackColor = &H80000005
        chkSaveCreds.Enabled = True
        
        If lSaveCreds = 1 Then
            chkSaveCreds.Value = lSaveCreds
            txtUsername.Text = Registry_Read(strRegPath, "Username")
            strPassword = Registry_Read(strRegPath, "Password")

            Decrypt strPassword
            txtPassword.Text = strPassword
        End If
    End If
    
End Sub

Private Sub Form_Unload(Cancel As Integer)

    Dim strPassword As String
    Dim strRegPath As String
    strRegPath = LoadResString(105)

    If chkSaveCreds.Value = 1 Then
        If txtUsername.Text <> "" And txtPassword.Text <> "" Then
            Registry_WriteString strRegPath, "Username", txtUsername.Text
            strPassword = txtPassword.Text
            Encrypt strPassword
            Registry_WriteString strRegPath, "Password", strPassword
            Registry_WriteDword strRegPath, "SaveCredentials", 1
            
        End If
    Else
        Registry_DeleteKey strRegPath, "Username"
        Registry_DeleteKey strRegPath, "Password"
        Registry_WriteDword strRegPath, "SaveCredentials", 0
    End If
End Sub
