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

#ifndef NTM_SRC_NTM_QUAT_H_
#define NTM_SRC_NTM_QUAT_H_

	#ifdef __cplusplus
		extern "C" {
	#endif

		#include "ntm_common.h"

		NtmQuat *ntm_quat_identity(NtmQuat *out);
		NtmQuat *ntm_quat_copy(NtmQuat *out, NtmQuat *a);
		NtmQuat *ntm_quat_set(NtmQuat *out, float x, float y, float z, float w);
		NtmQuat *ntm_quat_rotationTo(NtmQuat *out, NtmVec3 *a, NtmVec3 *b);
		NtmQuat *ntm_quat_setAxes(NtmQuat *out, NtmVec3 *view, NtmVec3 *right, NtmVec3 *up);
		NtmQuat *ntm_quat_setAxisAngle(NtmQuat *out, NtmVec3 *axis, float rad);
		NtmQuat *ntm_quat_setAxisAngleF(NtmQuat *out, float x, float y, float z, float rad);
		NtmQuat *ntm_quat_add(NtmQuat *out, NtmQuat *a, NtmQuat *b);
		NtmQuat *ntm_quat_multiply(NtmQuat *out, NtmQuat *a, NtmQuat *b);
		NtmQuat *ntm_quat_scale(NtmQuat *out, NtmQuat *a, float b);
		NtmQuat *ntm_quat_rotateX(NtmQuat *out, NtmQuat *a, float rad);
		NtmQuat *ntm_quat_rotateY(NtmQuat *out, NtmQuat *a, float rad);
		NtmQuat *ntm_quat_rotateZ(NtmQuat *out, NtmQuat *a, float rad);
		NtmQuat *ntm_quat_calculateW(NtmQuat *out, NtmQuat *a);
		float ntm_quat_dot(NtmQuat *a, NtmQuat *b);
		NtmQuat *ntm_quat_lerp(NtmQuat *out, NtmQuat *a, NtmQuat *b, float t);
		NtmQuat *ntm_quat_slerp(NtmQuat *out, NtmQuat *a, NtmQuat *b, float t);
		NtmQuat *ntm_quat_invert(NtmQuat *out, NtmQuat *a);
		NtmQuat *ntm_quat_conjugate(NtmQuat *out, NtmQuat *a);
		float ntm_quat_length(NtmQuat *a);
		float ntm_quat_squaredLength(NtmQuat *a);
		NtmQuat *ntm_quat_normalize(NtmQuat *out, NtmQuat *a);
		NtmQuat *ntm_quat_fromMat3(NtmQuat *out, NtmMat3 *m);

	#ifdef __cplusplus
		}
	#endif

#endif /* NTM_SRC_NTM_QUAT_H_ */
