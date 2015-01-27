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

#ifndef NTM_SRC_NTM_VEC2_H_
#define NTM_SRC_NTM_VEC2_H_

	#ifdef __cplusplus
		extern "C" {
	#endif

		#include "ntm_common.h"

		NtmVec2 *ntm_vec2_free(NtmVec2 *vec2);
		NtmVec2 *ntm_vec2_copy(NtmVec2 *out, NtmVec2 *a);
		NtmVec2 *ntm_vec2_set(NtmVec2 *out, float x, float y);
		NtmVec2 *ntm_vec2_add(NtmVec2 *out, NtmVec2 *a, NtmVec2 *b);
		NtmVec2 *ntm_vec2_subtract(NtmVec2 *out, NtmVec2 *a, NtmVec2 *b);
		NtmVec2 *ntm_vec2_multiply(NtmVec2 *out, NtmVec2 *a, NtmVec2 *b);
		NtmVec2 *ntm_vec2_divide(NtmVec2 *out, NtmVec2 *a, NtmVec2 *b);
		NtmVec2 *ntm_vec2_min(NtmVec2 *out, NtmVec2 *a, NtmVec2 *b);
		NtmVec2 *ntm_vec2_max(NtmVec2 *out, NtmVec2 *a, NtmVec2 *b);
		NtmVec2 *ntm_vec2_scale(NtmVec2 *out, NtmVec2 *a, float b);
		NtmVec2 *ntm_vec2_scaleAndAdd(
			NtmVec2 *out,
			NtmVec2 *a,
			NtmVec2 *b,
			float scale
		);
		float ntm_vec2_distance(NtmVec2 *a, NtmVec2 *b);
		float ntm_vec2_squaredDistance(NtmVec2 *a, NtmVec2 *b);
		float ntm_vec2_length(NtmVec2 *a);
		float ntm_vec2_squaredLength(NtmVec2 *a);
		NtmVec2 *ntm_vec2_negate(NtmVec2 *out, NtmVec2 *a);
		NtmVec2 *ntm_vec2_inverse(NtmVec2 *out, NtmVec2 *a);
		NtmVec2 *ntm_vec2_normalize(NtmVec2 *out, NtmVec2 *a);
		float ntm_vec2_dot(NtmVec2 *a, NtmVec2 *b);
		NtmVec3 *ntm_vec2_cross(NtmVec3 *out, NtmVec2 *a, NtmVec2 *b);
		NtmVec2 *ntm_vec2_lerp(NtmVec2 *out, NtmVec2 *a, NtmVec2 *b, float t);
		NtmVec2 *ntm_vec2_random(NtmVec2 *out);
		NtmVec2 *ntm_vec2_transformMat2(NtmVec2 *out, NtmVec2 *a, NtmMat2 *m);
		NtmVec2 *ntm_vec2_transformMat2d(NtmVec2 *out, NtmVec2 *a, NtmMat2d *m);
		NtmVec2 *ntm_vec2_transformMat3(NtmVec2 *out, NtmVec2 *a, NtmMat3 *m);
		NtmVec2 *ntm_vec2_transformMat4(NtmVec2 *out, NtmVec2 *a, NtmMat4 *m);

	#ifdef __cplusplus
		}
	#endif

#endif /* NTM_SRC_NTM_VEC2_H_ */
