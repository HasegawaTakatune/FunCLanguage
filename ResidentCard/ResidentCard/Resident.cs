using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ResidentCard
{
    public class Common
    {
        public static readonly string[] Prefectures = { "北海道", "青森県", "岩手県", "宮城県", "秋田県", "山形県", "福島県", "茨城県", "栃木県", "群馬県", "埼玉県", "千葉県", "東京都", "神奈川県", "新潟県", "富山県", "石川県", "福井県", "山梨県", "長野県", "岐阜県", "静岡県", "愛知県", "三重県", "滋賀県", "京都府", "大阪府", "兵庫県", "奈良県", "和歌山県", "鳥取県", "島根県", "岡山県", "広島県", "山口県", "徳島県", "香川県", "愛媛県", "高知県", "福岡県", "佐賀県", "長崎県", "熊本県", "大分県", "宮崎県", "鹿児島県", "沖縄県" };
        public static readonly string[] Languages = { "C", "C++", "C#", "Java", "JavaScript", "JQuery", "HTML", "PHP", "Ruby", "Objective-C", "Swift", "Python" };
    }

    public struct RESIDENT_DATA
    {
        public string name;
        public string birthday;
        public int prefectures;
        public string postalCode;
        public string address;
        public int gender;
        public List<int> languageList;
        public string note;
    }

    public class Resident
    {
        public const int Man = 0;
        public const int Woman = 1;
        public const int Other = 2;
        public const int GenderLength = 3;

        public string Name;
        public DateTime Birthday;
        public int Prefectures;
        public string PostalCode;
        public string Address;
        public int Gender;
        public List<int> LanguageList;
        public string Note;


        public bool SetResidentData(ref RESIDENT_DATA data, out string message)
        {
            message = string.Empty;

            if (string.IsNullOrWhiteSpace(data.name))
            {
                message = "名前が入力されていません。";
                return false;
            }

            if (DateTime.TryParse(data.birthday, out DateTime dataTime))
            {
                if (DateTime.Now < dataTime)
                {
                    message = "生年月日が正しくありません。";
                    return false;
                }
            }
            else
            {
                message = "生年月日が正しくありません。";
                return false;
            }

            string post = Regex.Replace(data.postalCode, @"[^0-9]", "");
            if (string.IsNullOrWhiteSpace(post))
            {
                message = "郵便番号が正しくありません。";
                return false;
            }

            if (string.IsNullOrWhiteSpace(data.address))
            {
                message = "住所が入力されていません。";
                return false;
            }

            if (data.gender < 0 || 2 < data.gender)
            {
                message = "性別が正しく選択されていません。";
                return false;
            }

            if (data.languageList.Count <= 0)
            {
                DialogResult result = MessageBox.Show("使用言語がありません、よろしいですか？", "注意", MessageBoxButtons.YesNo, MessageBoxIcon.Exclamation, MessageBoxDefaultButton.Button2);

                if (result == DialogResult.No)
                {
                    message = "使用言語を選択してください。";
                    return false;
                }
            }

            Name = data.name;
            Birthday = dataTime;
            Prefectures = data.prefectures;
            PostalCode = post;
            Address = data.address;
            Gender = data.gender;
            LanguageList = data.languageList;
            Note = data.note;

            return true;
        }

        public string GetLanguageListToNumber()
        {
            string value = string.Empty;
            for (int i = 0; i < LanguageList.Count; i++)
            {
                if (string.IsNullOrWhiteSpace(value))
                    value = LanguageList[i].ToString();
                else
                    value += "|" + LanguageList[i].ToString();
            }
            return value;
        }

        public string GetLanguageListToName()
        {
            string value = string.Empty;
            for (int i = 0; i < LanguageList.Count; i++)
            {
                if (string.IsNullOrWhiteSpace(value))
                    value = Common.Languages[LanguageList[i]];
                else
                    value += "," + Common.Languages[LanguageList[i]];
            }
            return value;
        }

        public string GetGender()
        {
            switch (Gender)
            {
                case Man: return "男";
                case Woman: return "女";
                case Other: return "どちらでもない";
                default: return "None.";
            }
        }
    }
}
