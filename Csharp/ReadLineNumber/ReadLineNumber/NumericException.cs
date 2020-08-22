using System;
using System.Runtime.Serialization;

namespace ReadLineNumber
{
    /// <summary>
    /// 数値例外クラス
    /// </summary>
    [Serializable()]
    class NumericException : Exception
    {
        /// <summary>
        /// 例外要因定義
        /// </summary>
        public enum Cause
        {
            /// <summary>
            /// フォーマットエラー
            /// </summary>
            FormatError = 1,

            /// <summary>
            /// リトライ回数不正
            /// </summary>
            RetryArgumentError,

            /// <summary>
            /// リトライ回数オーバー
            /// </summary>
            RetryOverError,

            /// <summary>
            /// 不明なエラー
            /// </summary>
            UnKnownError,
        }
        /// <summary>
        /// 例外要因
        /// </summary>
        public Cause ErrCause { get; } = Cause.UnKnownError;

        /// <summary>
        /// コンストラクタ
        /// </summary>
        /// <param name="cause">例外要因</param>
        public NumericException(Cause cause)
        : base()
        {
            this.ErrCause = cause;
        }

        /// <summary>
        /// コンストラクタ
        /// </summary>
        /// <param name="cause">例外要因</param>
        /// <param name="message">エラーメッセージ</param>
        public NumericException(Cause cause, string message)
            : base(message)
        {
            this.ErrCause = cause;
        }

        /// <summary>
        /// コンストラクタ
        /// </summary>
        /// <param name="cause">例外要因</param>
        /// <param name="message">エラーメッセージ</param>
        /// <param name="innerException">内包する例外情報</param>
        public NumericException(Cause cause, string message, Exception innerException)
            : base(message, innerException)
        {
            this.ErrCause = cause;
        }
        /// <summary>
        /// シリアル化されたデータを使用して、NumericException クラスの新しいインスタンスを初期化
        /// </summary>
        /// <param name="info">スローされた例外に関する、シリアル化されたオブジェクト データを保持するSerializationInfo</param>
        /// <param name="context">転送元または転送先についてのコンテキスト情報を含む StreamingContext</param>
        protected NumericException(SerializationInfo info, StreamingContext context)
            : base(info, context)
        {
        }
    }
}

