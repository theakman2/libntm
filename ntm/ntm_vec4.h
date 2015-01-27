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

#ifndef NTM_SRC_NTM_VEC4_H_
#define NTM_SRC_NTM_VEC4_H_

	#ifdef __cplusplus
		extern "C" {
	#endif

		#include "ntm_common.h"

		NtmVec4 *ntm_vec4_copy(NtmVec4 *out, NtmVec4 *a);
		NtmVec4 *ntm_vec4_set(NtmVec4 *out, float x, float y, float z, float w);
		NtmVec4 *ntm_vec4_add(NtmVec4 *out, NtmVec4 *a, NtmVec4 *b);
		NtmVec4 *ntm_vec4_subtract(NtmVec4 *out, NtmVec4 *a, NtmVec4 *b);
		NtmVec4 *ntm_vec4_multiply(NtmVec4 *out, NtmVec4 *a, NtmVec4 *b);
		NtmVec4 *ntm_vec4_divide(NtmVec4 *out, NtmVec4 *a, NtmVec4 *b);
		NtmVec4 *ntm_vec4_min(NtmVec4 *out, NtmVec4 *a, NtmVec4 *b);
		NtmVec4 *ntm_vec4_max(NtmVec4 *out, NtmVec4 *a, NtmVec4 *b);
		NtmVec4 *ntm_vec4_scale(NtmVec4 *out, NtmVec4 *a, float b);
		NtmVec4 *ntm_vec4_scaleAndAdd(NtmVec4 *out, NtmVec4 *a, NtmVec4 *b, float scale);
		float ntm_vec4_distance(NtmVec4 *a, NtmVec4 *b);
		float ntm_vec4_squaredDistance(NtmVec4 *a, NtmVec4 *b);
		float ntm_vec4_length(NtmVec4 *a);
		float ntm_vec4_squaredLength(NtmVec4 *a);
		NtmVec4 *ntm_vec4_negate(NtmVec4 *out, NtmVec4 *a);
		NtmVec4 *ntm_vec4_inverse(NtmVec4 *out, NtmVec4 *a);
		NtmVec4 *ntm_vec4_normalize(NtmVec4 *out, NtmVec4 *a);
		float ntm_vec4_dot(NtmVec4 *a, NtmVec4 *b);
		NtmVec4 *ntm_vec4_lerp(NtmVec4 *out, NtmVec4 *a, NtmVec4 *b, float t);
		NtmVec4 *ntm_vec4_random(NtmVec4 *out);
		NtmVec4 *ntm_vec4_transformMat4(NtmVec4 *out, NtmVec4 *a, NtmMat4 *m);
		NtmVec4 *ntm_vec4_transformQuat(NtmVec4 *out, NtmVec4 *a, NtmQuat *q);

	#ifdef __cplusplus
		}
	#endif

#endif /* NTM_SRC_NTM_VEC4_H_ */
