/**
 * ���l�p�W������
 *
 * @file readline_num.c
 * @author hinata
 * @date v1.0.0 �V�K�쐬
 */

#include <string.h>
#include "atonum.h"
#include "readline_num.h"

/*========================================================
* ���[�U�[�^��`
==========================================================*/

/* ���l�^��ʒ�` */
typedef enum
{
	NUM_INT32,
	NUM_INT64,
	NUM_FLOAT,
	NUM_DOUBLE
} NUM_TYPE_E;

/*========================================================
* �v���g�^�C�v�錾
==========================================================*/
static bool readline(const char* title, NUM_TYPE_E type, void* value, int retryCount);


/**
 * ���l����(�����Ȃ�4�o�C�g)
 * 
 * @param �^�C�g���\��������
 * @peram ���l�i�[��
 * @param �ē��͉�
 * @return true:���� false:�ُ�i���g���C�I�[�o�[)
 */
bool ReadLineInt32(const char* title, int32 *val, int retryCount)
{
	return readline(title, NUM_INT32, val, retryCount);
}

/**
 * ���l����(�����Ȃ�8�o�C�g)
 * 
  * @param �^�C�g���\��������
* @peram ���l�i�[��
 * @param �ē��͉�
 * @return true:���� false:�ُ�i���g���C�I�[�o�[)
 */
bool ReadLineInt64(const char* title, int64* val, int retryCount)
{
	return readline(title, NUM_INT64, val, retryCount);
}

/**
 * ���l����(float)
 * 
 * @param �^�C�g���\��������
 * @peram ���l�i�[��
 * @param �ē��͉�
 * @return true:���� false:�ُ�i���g���C�I�[�o�[)
 */
bool ReadLineFloat(const char* title, float* val, int retryCount)
{
	return readline(title, NUM_FLOAT, val, retryCount);
}

/**
 * ���l����(double)
 * 
 * @param �^�C�g���\��������
 * @peram ���l�i�[��
 * @param �ē��͉�
 * @return true:���� false:�ُ�i���g���C�I�[�o�[)
 */
bool ReadLineDouble(const char* title, double* val, int retryCount)
{
	return readline(title, NUM_DOUBLE, val, retryCount);
}

/**
 * 1�s�W������
 * 
 * @param �^�C�g���\��������
 * @param �f�[�^�^
 * @param ���l�i�[��
 * @param �ē��͉�
 * @return true:���� false:�ُ�i���g���C�I�[�o�[)
 */
static bool readline(const char *title, NUM_TYPE_E type, void* value, int retryCount)
{
	char buffer[100];		/* ���͗p������   */
	char* result;			/* ����           */
	int  i;					/* ���[�v�J�E���^ */
	bool ret = false;		/* �߂�l         */
	
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
			printf("[ERR]�ē��͂��Ă�������\n\n");
		}
	}
	if (!ret)
	{
		printf("[ERR���g���C�񐔂��I�[�o�[���܂���\n");
	}
	return ret;
}

