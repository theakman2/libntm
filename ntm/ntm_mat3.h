/*
The MIT License (MIT)

Copyright (c) 2015 A Kazim, Brandon Jones, Colin MacKenzie IV.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef NTM_SRC_NTM_MAT3_H_
#define NTM_SRC_NTM_MAT3_H_

	#ifdef __cplusplus
		extern "C" {
	#endif

		#include "ntm_common.h"

		NtmMat3 *ntm_mat3_identity(NtmMat3 *out);
		NtmMat3 *ntm_mat3_set(
			NtmMat3 *out,
			float a00,
			float a01,
			float a02,
			float a10,
			float a11,
			float a12,
			float a20,
			float a21,
			float a22
		);
		NtmMat3 *ntm_mat3_copy(NtmMat3 *out, NtmMat3 *a);
		NtmMat3 *ntm_mat3_fromMat4(NtmMat3 *out, NtmMat4 *a);
		NtmMat3 *ntm_mat3_transpose(NtmMat3 *out, NtmMat3 *a);
		NtmMat3 *ntm_mat3_invert(NtmMat3 *out, NtmMat3 *a);
		NtmMat3 *ntm_mat3_adjoint(NtmMat3 *out, NtmMat3 *a);
		float ntm_mat3_determinant(NtmMat3 *a);
		NtmMat3 *ntm_mat3_multiply(NtmMat3 *out, NtmMat3 *a, NtmMat3 *b);
		NtmMat3 *ntm_mat3_translate(NtmMat3 *out, NtmMat3 *a, NtmVec2 *v);
		NtmMat3 *ntm_mat3_rotate(NtmMat3 *out, NtmMat3 *a, float rad);
		NtmMat3 *ntm_mat3_scale(NtmMat3 *out, NtmMat3 *a, NtmVec2 *v);
		NtmMat3 *ntm_mat3_fromTranslation(NtmMat3 *out, NtmVec2 *v);
		NtmMat3 *ntm_mat3_fromRotation(NtmMat3 *out, float rad);
		NtmMat3 *ntm_mat3_fromScaling(NtmMat3 *out, NtmVec2 *v);
		NtmMat3 *ntm_mat3_fromMat2d(NtmMat3 *out, NtmMat2d *a);
		NtmMat3 *ntm_mat3_fromQuat(NtmMat3 *out, NtmQuat *q);
		NtmMat3 *ntm_mat3_normalFromMat4(NtmMat3 *out, NtmMat4 *a);
		float ntm_mat3_frob(NtmMat3 *a);

	#ifdef __cplusplus
		}
	#endif

#endif /* NTM_SRC_NTM_MAT3_H_ */
