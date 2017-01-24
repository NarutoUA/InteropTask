using System;
using System.Data.SqlClient;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace InteropCsCom
{
    public partial class MainForm : Form
    {
        [DllImport("InteropDetailMfcDll.dll")]
        public static extern void ShowForm(int iPatientId, int iSkinId, string szSkinModel, string szSkinType, string szLocation, string szGender, string szPicPath);

        public string ConnectionString { get; set; }
        private SqlConnection m_objConnection = null;
        private SqlDataReader m_objDataReader = null;
        private readonly string m_strCmdSelectPatientList = "SELECT * FROM tblPatients";
        private readonly string m_strCmdSelectPatientDetails = "SELECT * FROM tblDetails WHERE id = {0}";

        private enum EColumnDetails
        {
            COLUMN_PATIENT_ID,
            COLUMN_SKIN_ID,
            COLUMN_SKIN_MODEL,
            COLUMN_SKIN_TYPE,
            COLUMN_LOCATION,
            COLUMN_GENDER,
            COLUMN_PICTURE_PATH
        }

        public MainForm()
        {
            InitializeComponent();
        }

        private void frmMain_Load(object sender, EventArgs e)
        {
            dataPatientList.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
            dataPatientList.AllowUserToResizeRows = false;

            try
            {
                m_objConnection = new SqlConnection(ConnectionString);
                m_objConnection.Open();

                SqlCommand objSqlCommand = new SqlCommand(m_strCmdSelectPatientList, m_objConnection);
                objSqlCommand.ExecuteNonQuery();
                m_objDataReader = objSqlCommand.ExecuteReader();

                while (m_objDataReader.Read() == true)
                {
                    int iRow = dataPatientList.Rows.Add();
                    for (int i = 0; i < 3; i++)
                    {
                        dataPatientList.Rows[iRow].Cells[i].Value = m_objDataReader.GetValue(i);
                    }
                }
                m_objDataReader.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Managed Interop GUI", MessageBoxButtons.OK);
                this.Close();
            }
        }

        private void dataPatientList_DoubleClick(object sender, EventArgs e)
        {
            string strCmd = String.Format(m_strCmdSelectPatientDetails, dataPatientList.SelectedRows[0].Cells[0].Value);
            SqlCommand objSqlCommand = new SqlCommand(strCmd, m_objConnection);
            objSqlCommand.ExecuteNonQuery();
            m_objDataReader = objSqlCommand.ExecuteReader();

            if (m_objDataReader.Read() == true)
            {
                int iPatientId = m_objDataReader.GetInt32((int)EColumnDetails.COLUMN_PATIENT_ID);
                int iSkinId = m_objDataReader.GetInt32((int)EColumnDetails.COLUMN_SKIN_ID);
                string szSkinModel = m_objDataReader.GetString((int)EColumnDetails.COLUMN_SKIN_MODEL);
                string szSkinType = m_objDataReader.GetString((int)EColumnDetails.COLUMN_SKIN_TYPE);
                string szLocation = m_objDataReader.GetString((int)EColumnDetails.COLUMN_LOCATION);
                string szGender = m_objDataReader.GetString((int)EColumnDetails.COLUMN_GENDER);
                string szPicPath = m_objDataReader.GetString((int)EColumnDetails.COLUMN_PICTURE_PATH);
                ShowForm(iPatientId, iSkinId, szSkinModel, szSkinType, szLocation, szGender, szPicPath);
            }
            m_objDataReader.Close();
        }
    }
}