/**
 * �����񁨐��l�ϊ��w�b�_
 *
 * @file atonum.h
 * @author hinata
 * @date v1.0.0 �V�K�쐬
 */
#if !defined(__atonum_h__)
#define __atonum_h__

 /*========================================================
  * INCLUDE�錾
 ==========================================================*/

#include "common.h"

 /*========================================================
 * �v���g�^�C�v�錾
 ==========================================================*/
#if defined(__cplusplus)
extern "C" {
#endif

	bool conv_atol(const char* str, long* value);
	bool conv_atoi64(const char* str, int64* value);
	bool conv_atof(const char* str, float* value);
	bool conv_atod(const char* str, double* value);

#if defined(__cplusplus)
}
#endif

#endif /* __atonum_h__ */
