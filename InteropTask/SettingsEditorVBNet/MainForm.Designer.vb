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
        Me.btnSave = New System.Windows.Forms.Button()
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
        Me.lblConnType.Location = New System.Drawing.Point(13, 57)
        Me.lblConnType.Name = "lblConnType"
        Me.lblConnType.Size = New System.Drawing.Size(87, 13)
        Me.lblConnType.TabIndex = 3
        Me.lblConnType.Text = "Connection type:"
        '
        'lblConnStr
        '
        Me.lblConnStr.AutoSize = True
        Me.lblConnStr.Location = New System.Drawing.Point(13, 97)
        Me.lblConnStr.Name = "lblConnStr"
        Me.lblConnStr.Size = New System.Drawing.Size(92, 13)
        Me.lblConnStr.TabIndex = 4
        Me.lblConnStr.Text = "Connection string:"
        '
        'txtConnStr
        '
        Me.txtConnStr.Location = New System.Drawing.Point(16, 113)
        Me.txtConnStr.Name = "txtConnStr"
        Me.txtConnStr.Size = New System.Drawing.Size(354, 20)
        Me.txtConnStr.TabIndex = 5
        '
        'btnSave
        '
        Me.btnSave.Location = New System.Drawing.Point(295, 139)
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
        Me.ClientSize = New System.Drawing.Size(382, 174)
        Me.Controls.Add(Me.btnSave)
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
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents lblDbProvType As System.Windows.Forms.Label
    Friend WithEvents cmbDbProvType As System.Windows.Forms.ComboBox
    Friend WithEvents cmbConnType As System.Windows.Forms.ComboBox
    Friend WithEvents lblConnType As System.Windows.Forms.Label
    Friend WithEvents lblConnStr As System.Windows.Forms.Label
    Friend WithEvents txtConnStr As System.Windows.Forms.TextBox
    Friend WithEvents btnSave As System.Windows.Forms.Button

End Class
