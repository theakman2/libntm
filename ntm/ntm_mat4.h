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

#ifndef NTM_SRC_NTM_MAT4_H_
#define NTM_SRC_NTM_MAT4_H_

	#ifdef __cplusplus
		extern "C" {
	#endif

		#include "ntm_common.h"

		NtmMat4 *ntm_mat4_identity(NtmMat4 *out);
		NtmMat4 *ntm_mat4_set(
			NtmMat4 *out,
			float a00,
			float a01,
			float a02,
			float a03,
			float a10,
			float a11,
			float a12,
			float a13,
			float a20,
			float a21,
			float a22,
			float a23,
			float a30,
			float a31,
			float a32,
			float a33
		);
		NtmMat4 *ntm_mat4_copy(NtmMat4 *out, NtmMat4 *a);
		NtmMat4 *ntm_mat4_transpose(NtmMat4 *out, NtmMat4 *a);
		NtmMat4 *ntm_mat4_invert(NtmMat4 *out, NtmMat4 *a);
		NtmMat4 *ntm_mat4_adjoint(NtmMat4 *out, NtmMat4 *a);
		float ntm_mat4_determinant(NtmMat4 *a);
		NtmMat4 *ntm_mat4_multiply(NtmMat4 *out, NtmMat4 *a, NtmMat4 *b);
		NtmMat4 *ntm_mat4_translate(NtmMat4 *out, NtmMat4 *a, NtmVec3 *v);
		NtmMat4 *ntm_mat4_scale(NtmMat4 *out, NtmMat4 *a, NtmVec3 *v);
		NtmMat4 *ntm_mat4_rotate(NtmMat4 *out, NtmMat4 *a, float rad, NtmVec3 *axis);
		NtmMat4 *ntm_mat4_rotateX(NtmMat4 *out, NtmMat4 *a, float rad);
		NtmMat4 *ntm_mat4_rotateY(NtmMat4 *out, NtmMat4 *a, float rad);
		NtmMat4 *ntm_mat4_rotateZ(NtmMat4 *out, NtmMat4 *a, float rad);
		NtmMat4 *ntm_mat4_fromTranslation(NtmMat4 *out, NtmVec3 *v);
		NtmMat4 *ntm_mat4_fromScaling(NtmMat4 *out, NtmVec3 *v);
		NtmMat4 *ntm_mat4_fromRotation(NtmMat4 *out, float rad, NtmVec3 *axis);
		NtmMat4 *ntm_mat4_fromXRotation(NtmMat4 *out, float rad);
		NtmMat4 *ntm_mat4_fromYRotation(NtmMat4 *out, float rad);
		NtmMat4 *ntm_mat4_fromZRotation(NtmMat4 *out, float rad);
		NtmMat4 *ntm_mat4_fromRotationTranslation(NtmMat4 *out, NtmQuat *q, NtmVec3 *v);
		NtmMat4 *ntm_mat4_fromQuat(NtmMat4 *out, NtmQuat *q);
		NtmMat4 *ntm_mat4_fromMat3(NtmMat4 *out, NtmMat3 *a);
		NtmMat4 *ntm_mat4_frustum(
			NtmMat4 *out,
			float left,
			float right,
			float bottom,
			float top,
			float near,
			float far
		);
		NtmMat4 *ntm_mat4_perspective(
			NtmMat4 *out,
			float fovy,
			float aspect,
			float near,
			float far
		);
		NtmMat4 *ntm_mat4_ortho(
			NtmMat4 *out,
			float left,
			float right,
			float bottom,
			float top,
			float near,
			float far
		);
		NtmMat4 *ntm_mat4_lookAt(NtmMat4 *out, NtmVec3 *eye, NtmVec3 *center, NtmVec3 *up);
		float ntm_mat4_frob(NtmMat4 *a);

	#ifdef __cplusplus
		}
	#endif

#endif /* NTM_SRC_NTM_MAT4_H_ */
