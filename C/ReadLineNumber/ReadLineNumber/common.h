/**
 * 共通ヘッダ
 *
 * @file common.h
 * @author hinata
 * @date v1.0.0 新規作成
 */
#if !defined(__common_h__)
#define __common_h__

#include <stdlib.h>
#include <stdio.h>

 /*========================================================
 * ユーザー型定義
 ==========================================================*/
typedef int 	  int32;		/**< 符号あり4バイト型 */
typedef long long int64;		/**< 符号あり8バイト型 */

/**
 * bool型
 */
typedef enum
{
	false = 0,  /**< 偽  */
	true        /**< 真  */
} bool;

#endif /* __common_h__ */
