/**
 * ���l�p�W�����̓��C������
 *
 * @file main.c
 * @author hinata
 * @date v1.0.0 �V�K�쐬
 */

#include "common.h"
#include "readline_num.h"

/*===================================
 * �萔��` 
=====================================*/
#define ENTER_NUM_MESSAGE	"���l����͂��Ă��������F"
#define RETRY_COUNT			(3)		/* ���g���C�� */

/*===================================
* ���[�U�[�^��`
=====================================*/

/* �e�X�g�p�R�[���o�b�N�֐� */
typedef void (*TEST_CALLBACK)();

/* �e�X�g�֐��\���� */
typedef struct _TEST_FUNC
{
	const char* title;			/* �^�C�g���\�� */
	TEST_CALLBACK callback;		/* �R�[���o�b�N�֐� */
} TEST_FUNC, *PTEST_FUNC;


/*===================================
* �v���g�^�C�v�錾
====================================*/
static void test_ReadLineInt32();
static void test_ReadLineInt64();
static void test_ReadLineFloat();
static void test_ReadLineDouble();

/**
 * ���C���֐�
 * 
 * @param �Ȃ�
 * @return �Ȃ�
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
 * ReadLineInt32()�e�X�g�֐�
 * @param �Ȃ�
 * @return �Ȃ�
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
 * ReadLineInt64()�e�X�g�֐�
 * 
 * @param �Ȃ�
 * @return �Ȃ�
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
 * ReadLineFloat()�e�X�g�֐�
 * 
 * @param �Ȃ�
 * @return �Ȃ�
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
 * ReadLineDouble()�e�X�g�֐�
 * 
 * @param �Ȃ�
 * @return �Ȃ�
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

