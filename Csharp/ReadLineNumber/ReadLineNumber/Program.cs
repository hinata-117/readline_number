using System;
using System.Reflection;

namespace ReadLineNumber
{
    /// <summary>
    /// プログラムクラス
    /// </summary>
    class Program
    {
        /// <summary>
        /// メイン関数
        /// </summary>
        /// <param name="args">引数配列</param>
        static void Main(string[] args)
        {
            Action funcTable = testInt32;
            funcTable += testDecimal;
            funcTable += TestOptionPrameter;

            funcTable();
        }
        /// <summary>
        /// Int32テスト
        /// </summary>
        static void testInt32()
        {
            try
            {
                Console.WriteLine($"[{MethodBase.GetCurrentMethod().Name}]");
                var val = Numeric.ReadLine<Int32>(Properties.Resources.EnterNumberMessage);
                Console.WriteLine($"[OK]{val}");
            }
            catch (NumericException numEx)
            {
                Console.WriteLine(numEx.Message);
            }
        }
        /// <summary>
        /// Decimalテスト
        /// </summary>
        static void testDecimal()
        {
            try
            {
                Console.WriteLine($"[{MethodBase.GetCurrentMethod().Name}]");
                var val = Numeric.ReadLine<decimal>(Properties.Resources.EnterNumberMessage);
                Console.WriteLine($"[OK]{val}");
            }
            catch (NumericException numEx)
            {
                Console.WriteLine(numEx.Message);
            }
        }
        /// <summary>
        /// オプションパラメータチェック
        /// </summary>
        static void TestOptionPrameter()
        {
            try
            {
                Console.WriteLine($"[{MethodBase.GetCurrentMethod().Name}]");
                var val = Numeric.ReadLine<UInt32>(Properties.Resources.EnterNumberMessage, 5, CheckValue);
                Console.WriteLine($"[OK]{val}");
            }
            catch (NumericException numEx)
            {
                Console.WriteLine(numEx.Message);
            }
        }
        /// <summary>
        /// 値チェック
        /// </summary>
        /// <param name="value">数値</param>
        /// <returns>true; 正常 false:異常</returns>
        static bool CheckValue(UInt32 value)
        {
            bool ret = false;

            if (value > 0)
            {
                ret = true;
            }
            else
            {
                Console.WriteLine(Properties.Resources.RangeOverError);
            }
            return ret;
        }
    }
}
