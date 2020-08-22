/**
 * 数値用標準入力
 *
 * @file readline_num.c
 * @author hinata
 * @date v1.0.0 新規作成
 */

#include <string.h>
#include "atonum.h"
#include "readline_num.h"

/*========================================================
* ユーザー型定義
==========================================================*/

/* 数値型種別定義 */
typedef enum
{
	NUM_INT32,
	NUM_INT64,
	NUM_FLOAT,
	NUM_DOUBLE
} NUM_TYPE_E;

/*========================================================
* プロトタイプ宣言
==========================================================*/
static bool readline(const char* title, NUM_TYPE_E type, void* value, int retryCount);


/**
 * 数値入力(符号なし4バイト)
 * 
 * @param タイトル表示文字列
 * @peram 数値格納先
 * @param 再入力回数
 * @return true:正常 false:異常（リトライオーバー)
 */
bool ReadLineInt32(const char* title, int32 *val, int retryCount)
{
	return readline(title, NUM_INT32, val, retryCount);
}

/**
 * 数値入力(符号なし8バイト)
 * 
  * @param タイトル表示文字列
* @peram 数値格納先
 * @param 再入力回数
 * @return true:正常 false:異常（リトライオーバー)
 */
bool ReadLineInt64(const char* title, int64* val, int retryCount)
{
	return readline(title, NUM_INT64, val, retryCount);
}

/**
 * 数値入力(float)
 * 
 * @param タイトル表示文字列
 * @peram 数値格納先
 * @param 再入力回数
 * @return true:正常 false:異常（リトライオーバー)
 */
bool ReadLineFloat(const char* title, float* val, int retryCount)
{
	return readline(title, NUM_FLOAT, val, retryCount);
}

/**
 * 数値入力(double)
 * 
 * @param タイトル表示文字列
 * @peram 数値格納先
 * @param 再入力回数
 * @return true:正常 false:異常（リトライオーバー)
 */
bool ReadLineDouble(const char* title, double* val, int retryCount)
{
	return readline(title, NUM_DOUBLE, val, retryCount);
}

/**
 * 1行標準入力
 * 
 * @param タイトル表示文字列
 * @param データ型
 * @param 数値格納先
 * @param 再入力回数
 * @return true:正常 false:異常（リトライオーバー)
 */
static bool readline(const char *title, NUM_TYPE_E type, void* value, int retryCount)
{
	char buffer[100];		/* 入力用文字列   */
	char* result;			/* 結果           */
	int  i;					/* ループカウンタ */
	bool ret = false;		/* 戻り値         */
	
	for (i = 0; !ret && i < retryCount; i++)
	{
		printf("%s", title);
		result = fgets(buffer, sizeof(buffer), stdin);
		if (result != NULL)
		{
			result = strchr(buffer, '\n');
			if (result != NULL)
			{
				*result = '\0';
			}
			switch (type)
			{
			case NUM_INT32:
				ret = conv_atol(buffer, value);
				break;
			case NUM_INT64:
				ret = conv_atoi64(buffer, value);
				break;
			case NUM_FLOAT:
				ret = conv_atof(buffer, value);
				break;
			case NUM_DOUBLE:
				ret = conv_atod(buffer, value);
				break;
			}
		}
		if (!ret)
		{
			rewind(stdin);
			printf("[ERR]再入力してください\n\n");
		}
	}
	if (!ret)
	{
		printf("[ERRリトライ回数をオーバーしました\n");
	}
	return ret;
}

