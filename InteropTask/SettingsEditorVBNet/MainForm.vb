Imports Microsoft.Win32

Public Class frmMain
    Private Declare Sub Encrypt Lib "InteropCryptCppDll" (ByRef szText As String)
    Private Declare Sub Decrypt Lib "InteropCryptCppDll" (ByRef szText As String)
    Private Const m_strAppSubkey As String = "InteropTask\"
    Private Const m_strAppTitle As String = "Interop Settings Editor"

    Private Sub frmMain_Load(sender As Object, e As EventArgs) Handles MyBase.Load

        Dim objRegKey As RegistryKey
        Dim lProviderType As Long
        Dim lConnectionType As Long
        Dim lSaveCreds As Long
        Dim strConnStr As String
        Dim strPassword As String

        objRegKey = Registry.CurrentUser.OpenSubKey("Software\" & m_strAppSubkey, True)

        If objRegKey Is Nothing Then
            Dim tempKey As RegistryKey
            tempKey = Registry.CurrentUser.OpenSubKey("SOFTWARE", True)
            tempKey.CreateSubKey(m_strAppSubkey)
            tempKey.Close()
            objRegKey = Registry.CurrentUser.OpenSubKey(m_strAppSubkey, True)
        End If

        lProviderType = objRegKey.GetValue(My.Resources.Registry.regProvType, 0)
        lConnectionType = objRegKey.GetValue(My.Resources.Registry.regConnType, 0)
        lSaveCreds = objRegKey.GetValue(My.Resources.Registry.regSaveCreds, 0)
        strConnStr = objRegKey.GetValue(My.Resources.Registry.regConnStr, "")

        grbCreds.Enabled = lConnectionType

        If lSaveCreds <> 0 Then
            chkSaveCreds.Checked = True
            txtCredUser.Enabled = True
            txtCredPassword.Enabled = True
            txtCredUser.Text = objRegKey.GetValue(My.Resources.Registry.regUsername, "")
            strPassword = objRegKey.GetValue(My.Resources.Registry.regPassword, "")

            If strPassword <> "" Then
                Decrypt(strPassword)
                txtCredPassword.Text = strPassword
            End If
        End If

        cmbConnType.SelectedIndex = lConnectionType
        cmbDbProvType.SelectedIndex = lProviderType
        txtConnStr.Text = strConnStr

        objRegKey.Close()
    End Sub

    Private Sub btnSave_Click(sender As Object, e As EventArgs) Handles btnSave.Click

        Dim objRegKey As RegistryKey
        Dim strPassword As String

        If (txtConnStr.Text = "") Then
            MessageBox.Show("Unable to save settings: Connection string is empty", m_strAppTitle, MessageBoxButtons.OK)
            Exit Sub
        End If

        objRegKey = Registry.CurrentUser.OpenSubKey("Software\" & m_strAppSubkey, True)

        If objRegKey Is Nothing Then
            Dim tempKey As RegistryKey
            tempKey = Registry.CurrentUser.OpenSubKey("SOFTWARE", True)
            tempKey.CreateSubKey(m_strAppSubkey)
            tempKey.Close()
            objRegKey = Registry.CurrentUser.OpenSubKey(m_strAppSubkey, True)
        End If

        objRegKey.SetValue(My.Resources.Registry.regProvType, cmbDbProvType.SelectedIndex)
        objRegKey.SetValue(My.Resources.Registry.regConnType, cmbConnType.SelectedIndex)
        objRegKey.SetValue(My.Resources.Registry.regConnStr, txtConnStr.Text)
        objRegKey.SetValue(My.Resources.Registry.regSaveCreds, If(chkSaveCreds.Checked = True, 1, 0))

        If (chkSaveCreds.Checked = True) Then
            objRegKey.SetValue(My.Resources.Registry.regUsername, txtCredUser.Text)

            strPassword = txtCredPassword.Text
            If strPassword <> "" Then
                Encrypt(strPassword)
            End If

            objRegKey.SetValue(My.Resources.Registry.regPassword, strPassword)
        Else
            objRegKey.DeleteValue(My.Resources.Registry.regUsername, False)
            objRegKey.DeleteValue(My.Resources.Registry.regPassword, False)
        End If

        objRegKey.Close()

        MessageBox.Show("Configuration was saved successfully", m_strAppTitle, MessageBoxButtons.OK)

    End Sub

    Private Sub chkSaveCreds_CheckedChanged(sender As Object, e As EventArgs) Handles chkSaveCreds.CheckedChanged

        txtCredUser.Enabled = chkSaveCreds.Checked
        txtCredPassword.Enabled = chkSaveCreds.Checked

    End Sub

    Private Sub cmbConnType_SelectedIndexChanged(sender As Object, e As EventArgs) Handles cmbConnType.SelectedIndexChanged

        grbCreds.Enabled = cmbConnType.SelectedIndex

    End Sub
End Class