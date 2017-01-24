namespace InteropCsCom
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.dataPatientList = new System.Windows.Forms.DataGridView();
            this.clnId = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.clnFirstName = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.clnLastName = new System.Windows.Forms.DataGridViewTextBoxColumn();
            ((System.ComponentModel.ISupportInitialize)(this.dataPatientList)).BeginInit();
            this.SuspendLayout();
            // 
            // dataPatientList
            // 
            this.dataPatientList.AllowUserToAddRows = false;
            this.dataPatientList.AllowUserToDeleteRows = false;
            this.dataPatientList.BackgroundColor = System.Drawing.SystemColors.ButtonHighlight;
            this.dataPatientList.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataPatientList.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.clnId,
            this.clnFirstName,
            this.clnLastName});
            this.dataPatientList.GridColor = System.Drawing.SystemColors.ButtonShadow;
            this.dataPatientList.Location = new System.Drawing.Point(12, 12);
            this.dataPatientList.MultiSelect = false;
            this.dataPatientList.Name = "dataPatientList";
            this.dataPatientList.ReadOnly = true;
            this.dataPatientList.RowHeadersVisible = false;
            this.dataPatientList.Size = new System.Drawing.Size(518, 433);
            this.dataPatientList.TabIndex = 0;
            this.dataPatientList.DoubleClick += new System.EventHandler(this.dataPatientList_DoubleClick);
            // 
            // clnId
            // 
            this.clnId.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.ColumnHeader;
            this.clnId.HeaderText = "id";
            this.clnId.Name = "clnId";
            this.clnId.ReadOnly = true;
            this.clnId.Width = 40;
            // 
            // clnFirstName
            // 
            this.clnFirstName.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.clnFirstName.HeaderText = "FirstName";
            this.clnFirstName.Name = "clnFirstName";
            this.clnFirstName.ReadOnly = true;
            // 
            // clnLastName
            // 
            this.clnLastName.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.clnLastName.HeaderText = "LastName";
            this.clnLastName.Name = "clnLastName";
            this.clnLastName.ReadOnly = true;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(542, 457);
            this.Controls.Add(this.dataPatientList);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "MainForm";
            this.ShowIcon = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Managed Interop Form";
            this.Load += new System.EventHandler(this.frmMain_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataPatientList)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dataPatientList;
        private System.Windows.Forms.DataGridViewTextBoxColumn clnId;
        private System.Windows.Forms.DataGridViewTextBoxColumn clnFirstName;
        private System.Windows.Forms.DataGridViewTextBoxColumn clnLastName;
    }
}