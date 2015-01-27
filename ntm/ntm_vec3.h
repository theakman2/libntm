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

#ifndef NTM_SRC_NTM_VEC3_H_
#define NTM_SRC_NTM_VEC3_H_

	#ifdef __cplusplus
		extern "C" {
	#endif

		#include "ntm_common.h"

		NtmVec3 *ntm_vec3_copy(NtmVec3 *out, NtmVec3 *a);
		NtmVec3 *ntm_vec3_set(NtmVec3 *out, float x, float y, float z);
		NtmVec3 *ntm_vec3_add(NtmVec3 *out, NtmVec3 *a, NtmVec3 *b);
		NtmVec3 *ntm_vec3_subtract(NtmVec3 *out, NtmVec3 *a, NtmVec3 *b);
		NtmVec3 *ntm_vec3_multiply(NtmVec3 *out, NtmVec3 *a, NtmVec3 *b);
		NtmVec3 *ntm_vec3_divide(NtmVec3 *out, NtmVec3 *a, NtmVec3 *b);
		NtmVec3 *ntm_vec3_min(NtmVec3 *out, NtmVec3 *a, NtmVec3 *b);
		NtmVec3 *ntm_vec3_max(NtmVec3 *out, NtmVec3 *a, NtmVec3 *b);
		NtmVec3 *ntm_vec3_scale(NtmVec3 *out, NtmVec3 *a, float b);
		NtmVec3 *ntm_vec3_scaleAndAdd(NtmVec3 *out, NtmVec3 *a, NtmVec3 *b, float scale);
		float ntm_vec3_distance(NtmVec3 *a, NtmVec3 *b);
		float ntm_vec3_squaredDistance(NtmVec3 *a, NtmVec3 *b);
		float ntm_vec3_length(NtmVec3 *a);
		float ntm_vec3_squaredLength(NtmVec3 *a);
		NtmVec3 *ntm_vec3_negate(NtmVec3 *out, NtmVec3 *a);
		NtmVec3 *ntm_vec3_inverse(NtmVec3 *out, NtmVec3 *a);
		NtmVec3 *ntm_vec3_normalize(NtmVec3 *out, NtmVec3 *a);
		float ntm_vec3_dot(NtmVec3 *a, NtmVec3 *b);
		NtmVec3 *ntm_vec3_cross(NtmVec3 *out, NtmVec3 *a, NtmVec3 *b);
		NtmVec3 *ntm_vec3_lerp(NtmVec3 *out, NtmVec3 *a, NtmVec3 *b, float t);
		NtmVec3 *ntm_vec3_random(NtmVec3* out);
		NtmVec3 *ntm_vec3_transformMat4(NtmVec3 *out, NtmVec3 *a, NtmMat4 *m);
		NtmVec3 *ntm_vec3_transformMat3(NtmVec3 *out, NtmVec3 *a, NtmMat3 *m);
		NtmVec3 *ntm_vec3_transformQuat(NtmVec3 *out, NtmVec3 *a, NtmQuat *q);
		NtmVec3 *ntm_vec3_rotateX(NtmVec3 *out, NtmVec3 *a, float c);
		NtmVec3 *ntm_vec3_rotateY(NtmVec3 *out, NtmVec3 *a, float c);
		NtmVec3 *ntm_vec3_rotateZ(NtmVec3 *out, NtmVec3 *a, float c);


	#ifdef __cplusplus
		}
	#endif


#endif /* NTM_SRC_NTM_VEC3_H_ */
