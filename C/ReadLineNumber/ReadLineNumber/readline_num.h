/**
 * 数値用標準入力ヘッダ
 *
 * @file readline_num.h
 * @author hinata
 * @date v1.0.0 新規作成
 */
#if !defined(__readline_num_h__)
#define __readline_num_h__

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

	bool ReadLineInt32(const char* title, int32* val, int retryCount);
	bool ReadLineInt64(const char* title, int64* val, int retryCount);
	bool ReadLineFloat(const char* title, float* val, int retryCount);
	bool ReadLineDouble(const char* title, double* val, int retryCount);

#if defined(__cplusplus)
}
#endif

#endif /* __readline_num_h__ */
