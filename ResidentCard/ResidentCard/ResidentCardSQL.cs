

using System;
using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace ResidentCard
{
    public static class ResidentCardSQL
    {
        public static DataSet GetResident()
        {
            DataSet dataSet = new DataSet();

            using (SqlConnection connection = new SqlConnection(Properties.Settings.Default.AccessDebugDatabase))
            {
                connection.Open();

                SqlCommand command = connection.CreateCommand();

                command.Connection = connection;

                try
                {
                    command.CommandText += "SELECT * FROM Resident";

                    SqlDataAdapter adapter = new SqlDataAdapter();
                    adapter.SelectCommand = command;

                    adapter.Fill(dataSet);
                }
                catch
                {
                    MessageBox.Show("データの取得に失敗しました。", "警告", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            return dataSet;
        }

        public static void SaveResident(Resident data)
        {
            using (SqlConnection connection = new SqlConnection(Properties.Settings.Default.AccessDebugDatabase))
            {
                connection.Open();

                SqlCommand command = connection.CreateCommand();
                SqlTransaction transaction;

                transaction = connection.BeginTransaction();

                command.Connection = connection;
                command.Transaction = transaction;

                try
                {                    
                    command.CommandText = "INSERT INTO Resident VALUES(";
                    command.CommandText += "N'" + data.Name + "',";
                    command.CommandText += "N'" + data.Birthday + "',";
                    command.CommandText += data.Prefectures + ",";
                    command.CommandText += "N'" + data.PostalCode + "',";
                    command.CommandText += "N'" + data.Address + "',";
                    command.CommandText += data.Gender + ",";
                    command.CommandText += "N'" + data.GetLanguageListToNumber() + "',";
                    command.CommandText += "N'" + data.Note + "'";
                    command.CommandText += ")";

                    command.ExecuteNonQuery();

                    transaction.Commit();

                    MessageBox.Show("データを登録しました。", "", MessageBoxButtons.OK, MessageBoxIcon.None);
                }
                catch (Exception e)
                {
                    try { transaction.Rollback(); } catch { }
                    MessageBox.Show("データの保存に失敗しました。", "警告", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }





    }
}