namespace ResidentCard
{
    partial class ResidentCardForm
    {
        /// <summary>
        /// 必要なデザイナー変数です。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 使用中のリソースをすべてクリーンアップします。
        /// </summary>
        /// <param name="disposing">マネージド リソースを破棄する場合は true を指定し、その他の場合は false を指定します。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows フォーム デザイナーで生成されたコード

        /// <summary>
        /// デザイナー サポートに必要なメソッドです。このメソッドの内容を
        /// コード エディターで変更しないでください。
        /// </summary>
        private void InitializeComponent()
        {
            this.ResidentGrid = new System.Windows.Forms.DataGridView();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.InfoPage = new System.Windows.Forms.TabPage();
            this.SavePage = new System.Windows.Forms.TabPage();
            this.AddressLabel = new System.Windows.Forms.Label();
            this.AddressText = new System.Windows.Forms.TextBox();
            this.LoadButton = new System.Windows.Forms.Button();
            this.SelectedFileButton = new System.Windows.Forms.Button();
            this.FilePathText = new System.Windows.Forms.TextBox();
            this.SaveButton = new System.Windows.Forms.Button();
            this.ClearButton = new System.Windows.Forms.Button();
            this.NoteLabel = new System.Windows.Forms.Label();
            this.NoteText = new System.Windows.Forms.RichTextBox();
            this.LanguageCheckedList = new System.Windows.Forms.CheckedListBox();
            this.LanguageLabel = new System.Windows.Forms.Label();
            this.GenderGroup = new System.Windows.Forms.GroupBox();
            this.OtherRadio = new System.Windows.Forms.RadioButton();
            this.ManRadio = new System.Windows.Forms.RadioButton();
            this.WomanRadio = new System.Windows.Forms.RadioButton();
            this.GenderLabel = new System.Windows.Forms.Label();
            this.PostalCodeText = new System.Windows.Forms.TextBox();
            this.PostalCodeLabel = new System.Windows.Forms.Label();
            this.PrefecturesLabel = new System.Windows.Forms.Label();
            this.PrefecturesCombo = new System.Windows.Forms.ComboBox();
            this.BirthdayLabel = new System.Windows.Forms.Label();
            this.BirthdayTimePicker = new System.Windows.Forms.DateTimePicker();
            this.NameLabel = new System.Windows.Forms.Label();
            this.NameText = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.ResidentGrid)).BeginInit();
            this.tabControl1.SuspendLayout();
            this.InfoPage.SuspendLayout();
            this.SavePage.SuspendLayout();
            this.GenderGroup.SuspendLayout();
            this.SuspendLayout();
            // 
            // ResidentGrid
            // 
            this.ResidentGrid.AllowUserToAddRows = false;
            this.ResidentGrid.AllowUserToDeleteRows = false;
            this.ResidentGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.ResidentGrid.Location = new System.Drawing.Point(8, 85);
            this.ResidentGrid.Name = "ResidentGrid";
            this.ResidentGrid.ReadOnly = true;
            this.ResidentGrid.RowTemplate.Height = 21;
            this.ResidentGrid.Size = new System.Drawing.Size(776, 332);
            this.ResidentGrid.TabIndex = 0;
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.InfoPage);
            this.tabControl1.Controls.Add(this.SavePage);
            this.tabControl1.Location = new System.Drawing.Point(0, -1);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(800, 453);
            this.tabControl1.TabIndex = 3;
            // 
            // InfoPage
            // 
            this.InfoPage.Controls.Add(this.ResidentGrid);
            this.InfoPage.Location = new System.Drawing.Point(4, 22);
            this.InfoPage.Name = "InfoPage";
            this.InfoPage.Padding = new System.Windows.Forms.Padding(3, 3, 3, 3);
            this.InfoPage.Size = new System.Drawing.Size(792, 427);
            this.InfoPage.TabIndex = 0;
            this.InfoPage.Text = "一覧";
            this.InfoPage.UseVisualStyleBackColor = true;
            // 
            // SavePage
            // 
            this.SavePage.Controls.Add(this.AddressLabel);
            this.SavePage.Controls.Add(this.AddressText);
            this.SavePage.Controls.Add(this.LoadButton);
            this.SavePage.Controls.Add(this.SelectedFileButton);
            this.SavePage.Controls.Add(this.FilePathText);
            this.SavePage.Controls.Add(this.SaveButton);
            this.SavePage.Controls.Add(this.ClearButton);
            this.SavePage.Controls.Add(this.NoteLabel);
            this.SavePage.Controls.Add(this.NoteText);
            this.SavePage.Controls.Add(this.LanguageCheckedList);
            this.SavePage.Controls.Add(this.LanguageLabel);
            this.SavePage.Controls.Add(this.GenderGroup);
            this.SavePage.Controls.Add(this.GenderLabel);
            this.SavePage.Controls.Add(this.PostalCodeText);
            this.SavePage.Controls.Add(this.PostalCodeLabel);
            this.SavePage.Controls.Add(this.PrefecturesLabel);
            this.SavePage.Controls.Add(this.PrefecturesCombo);
            this.SavePage.Controls.Add(this.BirthdayLabel);
            this.SavePage.Controls.Add(this.BirthdayTimePicker);
            this.SavePage.Controls.Add(this.NameLabel);
            this.SavePage.Controls.Add(this.NameText);
            this.SavePage.Location = new System.Drawing.Point(4, 22);
            this.SavePage.Name = "SavePage";
            this.SavePage.Padding = new System.Windows.Forms.Padding(3, 3, 3, 3);
            this.SavePage.Size = new System.Drawing.Size(792, 427);
            this.SavePage.TabIndex = 1;
            this.SavePage.Text = "登録";
            this.SavePage.UseVisualStyleBackColor = true;
            // 
            // AddressLabel
            // 
            this.AddressLabel.AutoSize = true;
            this.AddressLabel.Font = new System.Drawing.Font("MS UI Gothic", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.AddressLabel.Location = new System.Drawing.Point(24, 143);
            this.AddressLabel.Name = "AddressLabel";
            this.AddressLabel.Size = new System.Drawing.Size(37, 15);
            this.AddressLabel.TabIndex = 24;
            this.AddressLabel.Text = "住所";
            // 
            // AddressText
            // 
            this.AddressText.ImeMode = System.Windows.Forms.ImeMode.Hangul;
            this.AddressText.Location = new System.Drawing.Point(165, 139);
            this.AddressText.MaxLength = 40;
            this.AddressText.Name = "AddressText";
            this.AddressText.Size = new System.Drawing.Size(201, 19);
            this.AddressText.TabIndex = 22;
            // 
            // LoadButton
            // 
            this.LoadButton.Location = new System.Drawing.Point(709, 63);
            this.LoadButton.Name = "LoadButton";
            this.LoadButton.Size = new System.Drawing.Size(75, 23);
            this.LoadButton.TabIndex = 21;
            this.LoadButton.Text = "読込";
            this.LoadButton.UseVisualStyleBackColor = true;
            this.LoadButton.Click += new System.EventHandler(this.LoadButton_Click);
            // 
            // SelectedFileButton
            // 
            this.SelectedFileButton.Location = new System.Drawing.Point(628, 63);
            this.SelectedFileButton.Name = "SelectedFileButton";
            this.SelectedFileButton.Size = new System.Drawing.Size(75, 23);
            this.SelectedFileButton.TabIndex = 20;
            this.SelectedFileButton.Text = "ファイル選択";
            this.SelectedFileButton.UseVisualStyleBackColor = true;
            this.SelectedFileButton.Click += new System.EventHandler(this.SelectedFileButton_Click);
            // 
            // FilePathText
            // 
            this.FilePathText.Location = new System.Drawing.Point(373, 38);
            this.FilePathText.Name = "FilePathText";
            this.FilePathText.ReadOnly = true;
            this.FilePathText.Size = new System.Drawing.Size(411, 19);
            this.FilePathText.TabIndex = 19;
            // 
            // SaveButton
            // 
            this.SaveButton.Location = new System.Drawing.Point(709, 394);
            this.SaveButton.Name = "SaveButton";
            this.SaveButton.Size = new System.Drawing.Size(75, 23);
            this.SaveButton.TabIndex = 18;
            this.SaveButton.Text = "登録";
            this.SaveButton.UseVisualStyleBackColor = true;
            this.SaveButton.Click += new System.EventHandler(this.SaveButton_Click);
            // 
            // ClearButton
            // 
            this.ClearButton.Location = new System.Drawing.Point(628, 394);
            this.ClearButton.Name = "ClearButton";
            this.ClearButton.Size = new System.Drawing.Size(75, 23);
            this.ClearButton.TabIndex = 17;
            this.ClearButton.Text = "クリア";
            this.ClearButton.UseVisualStyleBackColor = true;
            this.ClearButton.Click += new System.EventHandler(this.ClearButton_Click);
            // 
            // NoteLabel
            // 
            this.NoteLabel.AutoSize = true;
            this.NoteLabel.Font = new System.Drawing.Font("MS UI Gothic", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.NoteLabel.Location = new System.Drawing.Point(24, 323);
            this.NoteLabel.Name = "NoteLabel";
            this.NoteLabel.Size = new System.Drawing.Size(37, 15);
            this.NoteLabel.TabIndex = 16;
            this.NoteLabel.Text = "備考";
            // 
            // NoteText
            // 
            this.NoteText.Location = new System.Drawing.Point(157, 320);
            this.NoteText.MaxLength = 500;
            this.NoteText.Name = "NoteText";
            this.NoteText.Size = new System.Drawing.Size(430, 94);
            this.NoteText.TabIndex = 15;
            this.NoteText.Text = "";
            // 
            // LanguageCheckedList
            // 
            this.LanguageCheckedList.FormattingEnabled = true;
            this.LanguageCheckedList.Location = new System.Drawing.Point(165, 229);
            this.LanguageCheckedList.Name = "LanguageCheckedList";
            this.LanguageCheckedList.Size = new System.Drawing.Size(201, 74);
            this.LanguageCheckedList.TabIndex = 14;
            // 
            // LanguageLabel
            // 
            this.LanguageLabel.AutoSize = true;
            this.LanguageLabel.Font = new System.Drawing.Font("MS UI Gothic", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.LanguageLabel.Location = new System.Drawing.Point(24, 229);
            this.LanguageLabel.Name = "LanguageLabel";
            this.LanguageLabel.Size = new System.Drawing.Size(67, 15);
            this.LanguageLabel.TabIndex = 13;
            this.LanguageLabel.Text = "使用言語";
            // 
            // GenderGroup
            // 
            this.GenderGroup.Controls.Add(this.OtherRadio);
            this.GenderGroup.Controls.Add(this.ManRadio);
            this.GenderGroup.Controls.Add(this.WomanRadio);
            this.GenderGroup.Location = new System.Drawing.Point(165, 189);
            this.GenderGroup.Name = "GenderGroup";
            this.GenderGroup.Size = new System.Drawing.Size(201, 34);
            this.GenderGroup.TabIndex = 12;
            this.GenderGroup.TabStop = false;
            // 
            // OtherRadio
            // 
            this.OtherRadio.AutoSize = true;
            this.OtherRadio.Location = new System.Drawing.Point(88, 12);
            this.OtherRadio.Name = "OtherRadio";
            this.OtherRadio.Size = new System.Drawing.Size(88, 16);
            this.OtherRadio.TabIndex = 11;
            this.OtherRadio.TabStop = true;
            this.OtherRadio.Text = "どちらでもない";
            this.OtherRadio.UseVisualStyleBackColor = true;
            // 
            // ManRadio
            // 
            this.ManRadio.AutoSize = true;
            this.ManRadio.Checked = true;
            this.ManRadio.Location = new System.Drawing.Point(6, 12);
            this.ManRadio.Name = "ManRadio";
            this.ManRadio.Size = new System.Drawing.Size(35, 16);
            this.ManRadio.TabIndex = 9;
            this.ManRadio.TabStop = true;
            this.ManRadio.Text = "男";
            this.ManRadio.UseVisualStyleBackColor = true;
            // 
            // WomanRadio
            // 
            this.WomanRadio.AutoSize = true;
            this.WomanRadio.Location = new System.Drawing.Point(47, 12);
            this.WomanRadio.Name = "WomanRadio";
            this.WomanRadio.Size = new System.Drawing.Size(35, 16);
            this.WomanRadio.TabIndex = 10;
            this.WomanRadio.TabStop = true;
            this.WomanRadio.Text = "女";
            this.WomanRadio.UseVisualStyleBackColor = true;
            // 
            // GenderLabel
            // 
            this.GenderLabel.AutoSize = true;
            this.GenderLabel.Font = new System.Drawing.Font("MS UI Gothic", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.GenderLabel.Location = new System.Drawing.Point(24, 201);
            this.GenderLabel.Name = "GenderLabel";
            this.GenderLabel.Size = new System.Drawing.Size(37, 15);
            this.GenderLabel.TabIndex = 8;
            this.GenderLabel.Text = "性別";
            // 
            // PostalCodeText
            // 
            this.PostalCodeText.ImeMode = System.Windows.Forms.ImeMode.Hangul;
            this.PostalCodeText.Location = new System.Drawing.Point(165, 114);
            this.PostalCodeText.MaxLength = 40;
            this.PostalCodeText.Name = "PostalCodeText";
            this.PostalCodeText.Size = new System.Drawing.Size(201, 19);
            this.PostalCodeText.TabIndex = 7;
            this.PostalCodeText.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.PostalCodeText_KeyPress);
            // 
            // PostalCodeLabel
            // 
            this.PostalCodeLabel.AutoSize = true;
            this.PostalCodeLabel.Font = new System.Drawing.Font("MS UI Gothic", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.PostalCodeLabel.Location = new System.Drawing.Point(24, 118);
            this.PostalCodeLabel.Name = "PostalCodeLabel";
            this.PostalCodeLabel.Size = new System.Drawing.Size(67, 15);
            this.PostalCodeLabel.TabIndex = 6;
            this.PostalCodeLabel.Text = "郵便番号";
            // 
            // PrefecturesLabel
            // 
            this.PrefecturesLabel.AutoSize = true;
            this.PrefecturesLabel.Font = new System.Drawing.Font("MS UI Gothic", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.PrefecturesLabel.Location = new System.Drawing.Point(24, 93);
            this.PrefecturesLabel.Name = "PrefecturesLabel";
            this.PrefecturesLabel.Size = new System.Drawing.Size(67, 15);
            this.PrefecturesLabel.TabIndex = 5;
            this.PrefecturesLabel.Text = "都道府県";
            // 
            // PrefecturesCombo
            // 
            this.PrefecturesCombo.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.PrefecturesCombo.FormattingEnabled = true;
            this.PrefecturesCombo.Location = new System.Drawing.Point(165, 88);
            this.PrefecturesCombo.Name = "PrefecturesCombo";
            this.PrefecturesCombo.Size = new System.Drawing.Size(201, 20);
            this.PrefecturesCombo.TabIndex = 4;
            // 
            // BirthdayLabel
            // 
            this.BirthdayLabel.AutoSize = true;
            this.BirthdayLabel.Font = new System.Drawing.Font("MS UI Gothic", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.BirthdayLabel.Location = new System.Drawing.Point(24, 67);
            this.BirthdayLabel.Name = "BirthdayLabel";
            this.BirthdayLabel.Size = new System.Drawing.Size(67, 15);
            this.BirthdayLabel.TabIndex = 3;
            this.BirthdayLabel.Text = "生年月日";
            // 
            // BirthdayTimePicker
            // 
            this.BirthdayTimePicker.Cursor = System.Windows.Forms.Cursors.PanNW;
            this.BirthdayTimePicker.Location = new System.Drawing.Point(166, 63);
            this.BirthdayTimePicker.Name = "BirthdayTimePicker";
            this.BirthdayTimePicker.Size = new System.Drawing.Size(200, 19);
            this.BirthdayTimePicker.TabIndex = 2;
            // 
            // NameLabel
            // 
            this.NameLabel.AutoSize = true;
            this.NameLabel.Font = new System.Drawing.Font("MS UI Gothic", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.NameLabel.Location = new System.Drawing.Point(24, 42);
            this.NameLabel.Name = "NameLabel";
            this.NameLabel.Size = new System.Drawing.Size(37, 15);
            this.NameLabel.TabIndex = 1;
            this.NameLabel.Text = "名前";
            // 
            // NameText
            // 
            this.NameText.Location = new System.Drawing.Point(165, 38);
            this.NameText.MaxLength = 40;
            this.NameText.Name = "NameText";
            this.NameText.Size = new System.Drawing.Size(201, 19);
            this.NameText.TabIndex = 0;
            // 
            // ResidentCardForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.tabControl1);
            this.Name = "ResidentCardForm";
            this.Text = "住所録";
            ((System.ComponentModel.ISupportInitialize)(this.ResidentGrid)).EndInit();
            this.tabControl1.ResumeLayout(false);
            this.InfoPage.ResumeLayout(false);
            this.SavePage.ResumeLayout(false);
            this.SavePage.PerformLayout();
            this.GenderGroup.ResumeLayout(false);
            this.GenderGroup.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView ResidentGrid;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage InfoPage;
        private System.Windows.Forms.TabPage SavePage;
        private System.Windows.Forms.DateTimePicker BirthdayTimePicker;
        private System.Windows.Forms.Label NameLabel;
        private System.Windows.Forms.TextBox NameText;
        private System.Windows.Forms.CheckedListBox LanguageCheckedList;
        private System.Windows.Forms.Label LanguageLabel;
        private System.Windows.Forms.GroupBox GenderGroup;
        private System.Windows.Forms.RadioButton OtherRadio;
        private System.Windows.Forms.RadioButton ManRadio;
        private System.Windows.Forms.RadioButton WomanRadio;
        private System.Windows.Forms.Label GenderLabel;
        private System.Windows.Forms.TextBox PostalCodeText;
        private System.Windows.Forms.Label PostalCodeLabel;
        private System.Windows.Forms.Label PrefecturesLabel;
        private System.Windows.Forms.ComboBox PrefecturesCombo;
        private System.Windows.Forms.Label BirthdayLabel;
        private System.Windows.Forms.RichTextBox NoteText;
        private System.Windows.Forms.Label NoteLabel;
        private System.Windows.Forms.Button SaveButton;
        private System.Windows.Forms.Button LoadButton;
        private System.Windows.Forms.Button SelectedFileButton;
        private System.Windows.Forms.TextBox FilePathText;
        private System.Windows.Forms.Button ClearButton;
        private System.Windows.Forms.TextBox AddressText;
        private System.Windows.Forms.Label AddressLabel;
    }
}

