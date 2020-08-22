using System;
using System.ComponentModel;

namespace ReadLineNumber
{
    /// <summary>
    /// 数値クラス
    /// </summary>
    public class Numeric
    {
        /// <summary>
        /// チェック関数デリゲート
        /// </summary>
        /// <param name="val"></param>
        /// <returns>true: 正常 false:異常</returns>
        public delegate bool CheckValue<T>(T val);

        /// <summary>
        /// 数値入力（入力エラー時のリトライ機能付き）
        /// </summary>
        /// <typeparam name = "T" > データ型 </ typeparam >
        /// < param name="title">タイトル</param>
        /// < param name="retryCount">入力エラー時のリトライ回数(デフォルト3回)</param>
        /// < param name="callback">チェック関数を指定(デフォルトはnull)</param>
        /// <returns>数値</returns>
        /// <exception cref="NumericException">数値入力例外</exception>
        public static T ReadLine<T>(string title, uint retryCount = 3, CheckValue<T> callback = null)
            where T : IComparable<T>
        {
            T val = default(T);
            bool isSuccess = false;

            if (retryCount == 0)
            {
                throw new NumericException(NumericException.Cause.RetryArgumentError, Properties.Resources.RetryArgumentError);
            }
            for (int i = 0; !isSuccess && i < retryCount; i++)
            {
                // 数値入力
                isSuccess = ReadLine<T>(title, out val);
                if (isSuccess && callback != null)
                {
                    // 数値範囲チェック
                    isSuccess = callback(val);
                }
            }
            if (!isSuccess)
            {
                // 入力回数オーバー
                throw new NumericException(NumericException.Cause.RetryOverError, Properties.Resources.RetryInputOverError);
            }
            return val;
        }
        /// <summary>
        /// 数値入力
        /// </summary>
        /// <param name="title">タイトル</param>
        /// <param name="val">入力された数値の格納先</param>
        /// <returns>true:正常 false:異常</returns>
        public static bool ReadLine<T>(string title, out T val)
        {
            val = default(T);
            bool ret = false;

            try
            {
                // 文字入力
                Console.Write(title);
                string str = Console.ReadLine();

                // 文字列→数値変換
                val = (T)TypeDescriptor.GetConverter(typeof(T)).ConvertFromString(str);

                ret = true;
            }
            catch(Exception ex)
            {
                Console.WriteLine($"[ERR]{ex.Message}");
                Console.WriteLine($"{Properties.Resources.ReEnterMessage}\n");
            }
            return ret;
        }
    }
}
