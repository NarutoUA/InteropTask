using System;
using System.Runtime.InteropServices;

namespace InteropCsCom
{
    [Guid("FC43E652-5B2F-4E77-9279-3AE518F719D7")]
    public interface IConnect
    {
        int Connect(string strConnectionString);
    }

    [Guid("B17D13D3-0CAE-43B2-8677-C7EBAD3D138A"),
    InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
    public interface IConnectEvents
    {
    }

    [Guid("6DC1DC72-32D0-449D-A976-D08032A58B76"),
    ClassInterface(ClassInterfaceType.None),
    ComSourceInterfaces(typeof(IConnectEvents))]
    public class IConnectClass : IConnect
    {
        private bool m_bConnected = false;

        public int Connect(string strConnectionString)
        {
            if (m_bConnected == true)
            {
                return -1;
            }

            MainForm objForm = new MainForm();
            objForm.ConnectionString = strConnectionString;
            objForm.ShowDialog();
            m_bConnected = true;
            return 0;
        }
    }
}