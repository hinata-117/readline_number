/**
 * �����񁨐��l�ϊ�����
 * 
 * @file atonum.c
 * @author hinata
 * @date v1.0.0 �V�K�쐬
 */
#include "atonum.h"
#include <errno.h>
#include <float.h>
#include <math.h>

/**
 * �����񁨐��l�ϊ�
 *
 * @param str  ������
 * @param value �ϊ���̐��l�i�[��
 * @return true: ���� false: �ُ�
 */
bool conv_atol(const char* str, long* value)
{
	char* end;				/* �ϊ���̃|�C���^ */
	bool  ret = false;		/* �߂�l   */

	errno = 0;  /* errno���N���A���Ă��� */

	const long val = strtol(str, &end, 10);
	if (end == str) {
		fprintf(stderr, "[ERR]not a decimal number\n");
	}
	else if (*end != '\0') {
		fprintf(stderr, "[ERR]extra characters at end of input: %s\n", end);
	}
	else if ((LONG_MIN == val || LONG_MAX == val) && ERANGE == errno) {
		fprintf(stderr, "[ERR]out of range of type long\n");
	}
	else if (val > INT_MAX) {
		fprintf(stderr, "[ERR]out of range of type INT_MAX\n");
	}
	else if (val < INT_MIN) {
		fprintf(stderr, "[ERR]out of range of type INT_MIN\n");
	}
	else {
		*value = val;
		ret = true;
	}
	return ret;
}

/**
 * �����񁨐��l�ϊ�(64�r�b�g�Ή�)
 *
 * @param str  ������
 * @param value �ϊ���̐��l�i�[��
 * @return true: ���� false: �ُ�
 */
bool conv_atoi64(const char* str, int64* value)
{
	char* end;				/* �ϊ���̃|�C���^ */
	bool  ret = false;		/* �߂�l   */

	errno = 0;  /* errno���N���A���Ă��� */

	const int64 val = strtoll(str, &end, 10);
	if (end == str) {
		fprintf(stderr, "[ERR]not a decimal number\n");
	}
	else if (*end != '\0') {
		fprintf(stderr, "[ERR]extra characters at end of input: %s\n", end);
	}
	else if ((LLONG_MIN == val || LLONG_MAX == val) && ERANGE == errno) {
		fprintf(stderr, "[ERR]out of range of type I64\n");
	}
	else if (val > LLONG_MAX) {
		fprintf(stderr, "[ERR]out of range of type I64_MAX\n");
	}
	else if (val < LLONG_MIN) {
		fprintf(stderr, "[ERR]out of range of type I64_MIN\n");
	}
	else {
		*value = val;
		ret = true;
	}
	return ret;
}

/**
 * �����񁨐��l�ϊ�(float)
 *
 * @param str  ������
 * @param value �ϊ���̐��l�i�[��
 * @return true: ���� false: �ُ�
 */
bool conv_atof(const char* str, float* value)
{
	char* end;				/* �ϊ���̃|�C���^ */
	bool  ret = false;		/* �߂�l   */

	errno = 0;  /* errno���N���A���Ă��� */

	const float val = strtof(str, &end);
	if (end == str) {
		fprintf(stderr, "[ERR]not a decimal number\n");
	}
	else if (*end != '\0') {
		fprintf(stderr, "[ERR]extra characters at end of input: %s\n", end);
	}
	else if ((val == HUGE_VALF || val == -HUGE_VALF) && errno == ERANGE)
	{
		fprintf(stderr, "[ERR]out of range of type float\n");
	}
	else if (val == HUGE_VALF && errno == ERANGE)
	{
		fprintf(stderr, "[ERR]out of range of type HUGE_VALF\n");
	}
	else {
		*value = val;
		ret = true;
	}
	return ret;
}

/**
 * �����񁨐��l�ϊ�(double)
 *
 * @param str  ������
 * @param value �ϊ���̐��l�i�[��
 * @return true: ���� false: �ُ�
 */
bool conv_atod(const char* str, double* value)
{
	char* end;				/* �ϊ���̃|�C���^ */
	bool  ret = false;		/* �߂�l   */

	errno = 0;  /* errno���N���A���Ă��� */

	const double val = strtod(str, &end);
	if (end == str) {
		fprintf(stderr, "[ERR]not a decimal number\n");
	}
	else if (*end != '\0') {
		fprintf(stderr, "[ERR]extra characters at end of input: %s\n", end);
	}
	else if ((val == HUGE_VAL || val == -HUGE_VAL) && errno == ERANGE)
	{
		fprintf(stderr, "[ERR]out of range of type double\n");
	}
	else if (val == HUGE_VAL && errno == ERANGE)
	{
		fprintf(stderr, "[ERR]out of range of type HUGE_VAL\n");
	}
	else {
		*value = val;
		ret = true;
	}
	return ret;
}

