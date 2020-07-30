using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using ExcelDataReader;

namespace ResidentCard
{
    public partial class ResidentCardForm : Form
    {
        private const string SaveFilePath = @"c:\ResidentCard\SaveData.xlsx";

        public ResidentCardForm()
        {
            InitializeComponent();
            ClearForm();

            LanguageCheckedList.Items.AddRange(Common.Languages);
            PrefecturesCombo.Items.AddRange(Common.Prefectures);

            if (!File.Exists(SaveFilePath))
            {
                Microsoft.Office.Interop.Excel.Application ExcelApp = new Microsoft.Office.Interop.Excel.Application();
                ExcelApp.Visible = false;
                Microsoft.Office.Interop.Excel.Workbook workbook = ExcelApp.Workbooks.Add();
                Microsoft.Office.Interop.Excel.Worksheet worksheet = workbook.Sheets[1];
                worksheet.Select(Type.Missing);

                //workbook.SaveAs(SaveFilePath);
                workbook.Close(false);
                ExcelApp.Quit();
            }

            ResidentGrid.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;

            DataSet dataSet = ResidentCardSQL.GetResident();
            DataTable dataTable = new DataTable();
            dataTable.Columns.Add("Name", typeof(string));

            for (int i = 0; i < 4; i++)
            {
                DataRow row = dataTable.NewRow();
                row["Name"] = "名前";
                dataTable.Rows.Add(row);
            }
            dataSet.Tables.Add(dataTable);
            ResidentGrid.DataSource = dataTable;
        }

        private void SelectedFileButton_Click(object sender, EventArgs e)
        {
            OpenFileDialog open = new OpenFileDialog();

            open.InitialDirectory = @"C:\";
            open.Filter = "Excelファイル(*.xlsx;*.xls)|*.xlsx;*.xls";
            open.Title = "開くファイルを選択してください";

            if (open.ShowDialog() == DialogResult.OK)
            {
                FilePathText.Text = open.FileName;
            }
        }

        private void LoadButton_Click(object sender, EventArgs e)
        {


            string filePath = FilePathText.Text;

            if (!File.Exists(filePath))
            {
                MessageBox.Show("存在しないファイルを参照しています。", "警告", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            if (string.IsNullOrWhiteSpace(filePath))
            {
                MessageBox.Show("開くファイルが選択されていません。", "警告", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            if (!LoadExcelFile(filePath, out string[] list, out string message))
            {
                MessageBox.Show(message, "警告", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            // フォームに埋め込む
            ClearForm();

            if (list.Length < 2)
            {
                MessageBox.Show("データが存在しません。", "警告", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            string[] slice = list[1].Split('|');
            if (slice.Length < 6)
            {
                MessageBox.Show("データ個数が正しくありません。", "警告", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            NameText.Text = slice[0];

            if (!DateTime.TryParse(slice[1], out DateTime dateTime))
            {
                MessageBox.Show("生年月日が正しくありません。", "警告", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            BirthdayTimePicker.Value = dateTime;

            int index = 0;
            if (!int.TryParse(slice[2], out index))
            {
                index = Array.IndexOf(Common.Prefectures, slice[2]);
            }
            if (index < 0 || Common.Prefectures.Length < index)
            {
                MessageBox.Show("都道府県が正しくありません。", "警告", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            PrefecturesCombo.SelectedIndex = index;

            PostalCodeText.Text = slice[3];
            AddressText.Text = slice[4];

            int select = 0;
            if (!int.TryParse(slice[5], out select))
            {
                switch (slice[5])
                {
                    case "男": select = Resident.Man; break;
                    case "女": select = Resident.Woman; break;
                    case "どちらでもない": select = Resident.Other; break;
                    default: select = -1; break;
                }
            }
            if (index < 0 || Resident.GenderLength < select)
            {
                MessageBox.Show("性別が正しくありません。", "警告", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            switch (select)
            {
                case Resident.Man: ManRadio.Select(); break;
                case Resident.Woman: WomanRadio.Select(); break;
                case Resident.Other: OtherRadio.Select(); break;
                default: break;
            }

            NoteText.Text = slice[6];

        }

        private bool LoadExcelFile(string filePath, out string[] list, out string message)
        {
            int skipRows = 0;
            int skipCols = 0;

            message = string.Empty;

            List<string> lines = new List<string>();
            var file = new FileInfo(filePath);
            using (FileStream fileStream = file.Open(FileMode.Open))
            {
                IExcelDataReader reader;

                if (file.Extension.Equals(".xls"))
                {
                    reader = ExcelReaderFactory.CreateBinaryReader(fileStream);
                }
                else if (file.Extension.Equals(".xlsx"))
                {
                    reader = ExcelReaderFactory.CreateOpenXmlReader(fileStream);
                }
                else
                {
                    message = "拡張子が対応していません。";
                    list = new string[0];
                    return false;
                }

                var conf = new ExcelDataSetConfiguration
                {
                    ConfigureDataTable = _ => new ExcelDataTableConfiguration
                    {
                        UseHeaderRow = false
                    }
                };

                var dataSet = reader.AsDataSet(conf);
                var dataTable = dataSet.Tables[0];

                int rowsLen = dataTable.Rows.Count;
                int colsLen = dataTable.Columns.Count;

                for (int row = 0; row < rowsLen; row++)
                {
                    if (row < skipRows) continue;
                    List<string> line = new List<string>();
                    //StringBuilder builder = new StringBuilder();
                    //builder.Clear();

                    for (int col = 0; col < colsLen; col++)
                    {
                        if (col < skipCols) continue;
                        var data = dataTable.Rows[row][col];
                        line.Add(data.ToString());
                    }
                    string lineStr = string.Join("|", line.ToArray());
                    lines.Add(lineStr);
                }
                string[] linesArray = lines.ToArray();

                reader.Close();
                fileStream.Close();
                // linesArray;
                list = lines.ToArray();
            }
            return true;
        }

        private void SaveButton_Click(object sender, EventArgs e)
        {
            RESIDENT_DATA data = new RESIDENT_DATA();

            data.name = NameText.Text;
            data.birthday = BirthdayTimePicker.Text;
            data.prefectures = PrefecturesCombo.SelectedIndex;
            data.postalCode = PostalCodeText.Text;
            data.address = AddressText.Text;

            if (ManRadio.Checked)
                data.gender = Resident.Man;
            else if (WomanRadio.Checked)
                data.gender = Resident.Woman;
            else
                data.gender = Resident.Other;

            data.languageList = new List<int>();
            for (int i = 0; i < LanguageCheckedList.Items.Count; i++)
                if (LanguageCheckedList.GetItemChecked(i))
                    data.languageList.Add(i);

            data.note = NoteText.Text;

            Resident resident = new Resident();
            if (!resident.SetResidentData(ref data, out string message))
            {
                MessageBox.Show(message, "警告", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            ResidentCardSQL.SaveResident(resident);
            ClearForm();
        }

        private void ClearButton_Click(object sender, EventArgs e)
        {
            ClearForm();
        }

        private void ClearForm()
        {
            NameText.Text = string.Empty;
            BirthdayTimePicker.Text = string.Empty;
            PrefecturesCombo.SelectedValue = 0;
            AddressText.Text = string.Empty;
            ManRadio.Checked = false;
            WomanRadio.Checked = false;
            OtherRadio.Checked = false;
            LanguageCheckedList.ClearSelected();
            NoteText.Text = string.Empty;
            FilePathText.Text = string.Empty;
        }

        private void PostalCodeText_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar < '0' || '9' < e.KeyChar)
                e.Handled = true;
        }
    }
}
