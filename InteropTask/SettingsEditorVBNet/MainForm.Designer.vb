<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmMain
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.lblDbProvType = New System.Windows.Forms.Label()
        Me.cmbDbProvType = New System.Windows.Forms.ComboBox()
        Me.cmbConnType = New System.Windows.Forms.ComboBox()
        Me.lblConnType = New System.Windows.Forms.Label()
        Me.lblConnStr = New System.Windows.Forms.Label()
        Me.txtConnStr = New System.Windows.Forms.TextBox()
        Me.grbCreds = New System.Windows.Forms.GroupBox()
        Me.txtCredPassword = New System.Windows.Forms.TextBox()
        Me.txtCredUser = New System.Windows.Forms.TextBox()
        Me.lblCredPassword = New System.Windows.Forms.Label()
        Me.lblCredUsername = New System.Windows.Forms.Label()
        Me.chkSaveCreds = New System.Windows.Forms.CheckBox()
        Me.btnSave = New System.Windows.Forms.Button()
        Me.grbCreds.SuspendLayout()
        Me.SuspendLayout()
        '
        'lblDbProvType
        '
        Me.lblDbProvType.AutoSize = True
        Me.lblDbProvType.Location = New System.Drawing.Point(13, 13)
        Me.lblDbProvType.Name = "lblDbProvType"
        Me.lblDbProvType.Size = New System.Drawing.Size(120, 13)
        Me.lblDbProvType.TabIndex = 0
        Me.lblDbProvType.Text = "Database provider type:"
        '
        'cmbDbProvType
        '
        Me.cmbDbProvType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cmbDbProvType.FormattingEnabled = True
        Me.cmbDbProvType.Items.AddRange(New Object() {"C++", "C#"})
        Me.cmbDbProvType.Location = New System.Drawing.Point(16, 29)
        Me.cmbDbProvType.Name = "cmbDbProvType"
        Me.cmbDbProvType.Size = New System.Drawing.Size(161, 21)
        Me.cmbDbProvType.TabIndex = 1
        '
        'cmbConnType
        '
        Me.cmbConnType.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cmbConnType.FormattingEnabled = True
        Me.cmbConnType.Items.AddRange(New Object() {"Windows Authentication", "SQL Server Authentication"})
        Me.cmbConnType.Location = New System.Drawing.Point(16, 73)
        Me.cmbConnType.Name = "cmbConnType"
        Me.cmbConnType.Size = New System.Drawing.Size(161, 21)
        Me.cmbConnType.TabIndex = 2
        '
        'lblConnType
        '
        Me.lblConnType.AutoSize = True
        Me.lblConnType.Location = New System.Drawing.Point(16, 57)
        Me.lblConnType.Name = "lblConnType"
        Me.lblConnType.Size = New System.Drawing.Size(87, 13)
        Me.lblConnType.TabIndex = 3
        Me.lblConnType.Text = "Connection type:"
        '
        'lblConnStr
        '
        Me.lblConnStr.AutoSize = True
        Me.lblConnStr.Location = New System.Drawing.Point(16, 230)
        Me.lblConnStr.Name = "lblConnStr"
        Me.lblConnStr.Size = New System.Drawing.Size(92, 13)
        Me.lblConnStr.TabIndex = 4
        Me.lblConnStr.Text = "Connection string:"
        '
        'txtConnStr
        '
        Me.txtConnStr.Location = New System.Drawing.Point(12, 246)
        Me.txtConnStr.Name = "txtConnStr"
        Me.txtConnStr.Size = New System.Drawing.Size(354, 20)
        Me.txtConnStr.TabIndex = 5
        '
        'grbCreds
        '
        Me.grbCreds.Controls.Add(Me.txtCredPassword)
        Me.grbCreds.Controls.Add(Me.txtCredUser)
        Me.grbCreds.Controls.Add(Me.lblCredPassword)
        Me.grbCreds.Controls.Add(Me.lblCredUsername)
        Me.grbCreds.Controls.Add(Me.chkSaveCreds)
        Me.grbCreds.Enabled = False
        Me.grbCreds.Location = New System.Drawing.Point(19, 105)
        Me.grbCreds.Name = "grbCreds"
        Me.grbCreds.Size = New System.Drawing.Size(354, 122)
        Me.grbCreds.TabIndex = 6
        Me.grbCreds.TabStop = False
        Me.grbCreds.Text = "Credentials:"
        '
        'txtCredPassword
        '
        Me.txtCredPassword.Enabled = False
        Me.txtCredPassword.Location = New System.Drawing.Point(9, 71)
        Me.txtCredPassword.Name = "txtCredPassword"
        Me.txtCredPassword.PasswordChar = Global.Microsoft.VisualBasic.ChrW(42)
        Me.txtCredPassword.Size = New System.Drawing.Size(152, 20)
        Me.txtCredPassword.TabIndex = 4
        '
        'txtCredUser
        '
        Me.txtCredUser.Enabled = False
        Me.txtCredUser.Location = New System.Drawing.Point(9, 32)
        Me.txtCredUser.Name = "txtCredUser"
        Me.txtCredUser.Size = New System.Drawing.Size(154, 20)
        Me.txtCredUser.TabIndex = 3
        '
        'lblCredPassword
        '
        Me.lblCredPassword.AutoSize = True
        Me.lblCredPassword.Location = New System.Drawing.Point(6, 55)
        Me.lblCredPassword.Name = "lblCredPassword"
        Me.lblCredPassword.Size = New System.Drawing.Size(56, 13)
        Me.lblCredPassword.TabIndex = 2
        Me.lblCredPassword.Text = "Password:"
        '
        'lblCredUsername
        '
        Me.lblCredUsername.AutoSize = True
        Me.lblCredUsername.Location = New System.Drawing.Point(6, 16)
        Me.lblCredUsername.Name = "lblCredUsername"
        Me.lblCredUsername.Size = New System.Drawing.Size(58, 13)
        Me.lblCredUsername.TabIndex = 1
        Me.lblCredUsername.Text = "Username:"
        '
        'chkSaveCreds
        '
        Me.chkSaveCreds.AutoSize = True
        Me.chkSaveCreds.Location = New System.Drawing.Point(9, 97)
        Me.chkSaveCreds.Name = "chkSaveCreds"
        Me.chkSaveCreds.Size = New System.Drawing.Size(105, 17)
        Me.chkSaveCreds.TabIndex = 0
        Me.chkSaveCreds.Text = "Save credentials"
        Me.chkSaveCreds.UseVisualStyleBackColor = True
        '
        'btnSave
        '
        Me.btnSave.Location = New System.Drawing.Point(295, 272)
        Me.btnSave.Name = "btnSave"
        Me.btnSave.Size = New System.Drawing.Size(75, 23)
        Me.btnSave.TabIndex = 7
        Me.btnSave.Text = "Save"
        Me.btnSave.UseVisualStyleBackColor = True
        '
        'frmMain
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(382, 303)
        Me.Controls.Add(Me.btnSave)
        Me.Controls.Add(Me.grbCreds)
        Me.Controls.Add(Me.txtConnStr)
        Me.Controls.Add(Me.lblConnStr)
        Me.Controls.Add(Me.lblConnType)
        Me.Controls.Add(Me.cmbConnType)
        Me.Controls.Add(Me.cmbDbProvType)
        Me.Controls.Add(Me.lblDbProvType)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle
        Me.MaximizeBox = False
        Me.Name = "frmMain"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "InteropTask Settings Editor"
        Me.grbCreds.ResumeLayout(False)
        Me.grbCreds.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents lblDbProvType As System.Windows.Forms.Label
    Friend WithEvents cmbDbProvType As System.Windows.Forms.ComboBox
    Friend WithEvents cmbConnType As System.Windows.Forms.ComboBox
    Friend WithEvents lblConnType As System.Windows.Forms.Label
    Friend WithEvents lblConnStr As System.Windows.Forms.Label
    Friend WithEvents txtConnStr As System.Windows.Forms.TextBox
    Friend WithEvents grbCreds As System.Windows.Forms.GroupBox
    Friend WithEvents txtCredPassword As System.Windows.Forms.TextBox
    Friend WithEvents txtCredUser As System.Windows.Forms.TextBox
    Friend WithEvents lblCredPassword As System.Windows.Forms.Label
    Friend WithEvents lblCredUsername As System.Windows.Forms.Label
    Friend WithEvents chkSaveCreds As System.Windows.Forms.CheckBox
    Friend WithEvents btnSave As System.Windows.Forms.Button

End Class
