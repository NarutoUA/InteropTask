Imports Microsoft.Win32

Public Class frmMain
    Private Const m_strAppSubkey As String = "InteropTask\"
    Private Const m_strAppTitle As String = "Interop Settings Editor"

    Private Sub frmMain_Load(sender As Object, e As EventArgs) Handles MyBase.Load

        Dim objRegKey As RegistryKey
        Dim lProviderType As Long
        Dim lConnectionType As Long
        Dim strConnStr As String

        objRegKey = Registry.CurrentUser.OpenSubKey("SOFTWARE\" & m_strAppSubkey, True)

        If objRegKey Is Nothing Then
            Dim tempKey As RegistryKey
            tempKey = Registry.CurrentUser.OpenSubKey("SOFTWARE", True)
            tempKey.CreateSubKey(m_strAppSubkey)
            tempKey.Close()
            objRegKey = Registry.CurrentUser.OpenSubKey(m_strAppSubkey, True)
        End If

        lProviderType = objRegKey.GetValue(My.Resources.Registry.regProvType, 0)
        lConnectionType = objRegKey.GetValue(My.Resources.Registry.regConnType, 0)
        strConnStr = objRegKey.GetValue(My.Resources.Registry.regConnStr, "")

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

        objRegKey.Close()

        MessageBox.Show("Configuration was saved successfully", m_strAppTitle, MessageBoxButtons.OK)

    End Sub

End Class