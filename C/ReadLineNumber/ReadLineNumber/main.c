/**
 * 数値用標準入力メイン処理
 *
 * @file main.c
 * @author hinata
 * @date v1.0.0 新規作成
 */

#include "common.h"
#include "readline_num.h"

/*===================================
 * 定数定義 
=====================================*/
#define ENTER_NUM_MESSAGE	"数値を入力してください："
#define RETRY_COUNT			(3)		/* リトライ回数 */

/*===================================
* ユーザー型定義
=====================================*/

/* テスト用コールバック関数 */
typedef void (*TEST_CALLBACK)();

/* テスト関数構造体 */
typedef struct _TEST_FUNC
{
	const char* title;			/* タイトル表示 */
	TEST_CALLBACK callback;		/* コールバック関数 */
} TEST_FUNC, *PTEST_FUNC;


/*===================================
* プロトタイプ宣言
====================================*/
static void test_ReadLineInt32();
static void test_ReadLineInt64();
static void test_ReadLineFloat();
static void test_ReadLineDouble();

/**
 * メイン関数
 * 
 * @param なし
 * @return なし
 */
void main()
{
	TEST_FUNC funcTable[] =
	{
		{"ReadLineInt32", test_ReadLineInt32},
		{"ReadLineInt64", test_ReadLineInt64},
		{"test_ReadLineFloat", test_ReadLineFloat},
		{"test_ReadLineDouble", test_ReadLineDouble}
	};
	int i;
	int loopMax = sizeof(funcTable) / sizeof(TEST_FUNC);

	for (i = 0; i < loopMax; i++)
	{
		printf("[%s]\n", funcTable[i].title);
		funcTable[i].callback();
	}
}

/**
 * ReadLineInt32()テスト関数
 * @param なし
 * @return なし
 */
static void test_ReadLineInt32()
{
	int32 val;
	bool  ret;

	ret = ReadLineInt32(ENTER_NUM_MESSAGE, &val, RETRY_COUNT);
	if (ret)
	{
		printf("[OK] val = %d\n\n", val);
	}
}

/**
 * ReadLineInt64()テスト関数
 * 
 * @param なし
 * @return なし
 */
static void test_ReadLineInt64()
{
	int64 val;
	bool  ret;

	ret = ReadLineInt64(ENTER_NUM_MESSAGE, &val, RETRY_COUNT);
	if (ret)
	{
		printf("[OK] val = %lld\n\n", val);
	}
}

/**
 * ReadLineFloat()テスト関数
 * 
 * @param なし
 * @return なし
 */
static void test_ReadLineFloat()
{
	float val;
	bool  ret;

	ret = ReadLineFloat(ENTER_NUM_MESSAGE, &val, RETRY_COUNT);
	if (ret)
	{
		printf("[OK] val = %f\n\n", val);
	}
}

/**
 * ReadLineDouble()テスト関数
 * 
 * @param なし
 * @return なし
 */
static void test_ReadLineDouble()
{
	double val;
	bool  ret;

	ret = ReadLineDouble(ENTER_NUM_MESSAGE, &val, RETRY_COUNT);
	if (ret)
	{
		printf("[OK] val = %lf\n\n", val);
	}
}

