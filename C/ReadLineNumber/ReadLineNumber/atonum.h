/**
 * 文字列→数値変換ヘッダ
 *
 * @file atonum.h
 * @author hinata
 * @date v1.0.0 新規作成
 */
#if !defined(__atonum_h__)
#define __atonum_h__

 /*========================================================
  * INCLUDE宣言
 ==========================================================*/

#include "common.h"

 /*========================================================
 * プロトタイプ宣言
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
