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

#ifndef NTM_SRC_NTM_MAT2_H_
#define NTM_SRC_NTM_MAT2_H_

	#ifdef __cplusplus
		extern "C" {
	#endif

		#include "ntm_common.h"
		
		/**
		 * Set the elements of `out` to the provided floats.
		 */
		NtmMat2 *ntm_mat2_set(NtmMat2 *out, float a, float b, float c, float d);
		
		/**
		 * Set `out` to the identity matrix.
		 */
		NtmMat2 *ntm_mat2_identity(NtmMat2 *out);
		
		/**
		 * Copy the values of `a` into `out`.
		 */
		NtmMat2 *ntm_mat2_copy(NtmMat2 *out, NtmMat2 *a);
		
		/**
		 * Transpose `a` and store the result in `out`.
		 */
		NtmMat2 *ntm_mat2_transpose(NtmMat2 *out, NtmMat2 *a);
		
		/**
		 * Invert `a` and store the result in `out`.
		 */
		NtmMat2 *ntm_mat2_invert(NtmMat2 *out, NtmMat2 *a);
		
		/**
		 * Calculate the adjoint of `a` and store the result in `out`.
		 */
		NtmMat2 *ntm_mat2_adjoint(NtmMat2 *out, NtmMat2 *a);
		
		/**
		 * Get the determinant of `a`.
		 */
		float ntm_mat2_determinant(NtmMat2 *a);
		
		/**
		 * Transform `b` by `a` and store the result in `out`.
		 */
		NtmMat2 *ntm_mat2_multiply(NtmMat2 *out, NtmMat2 *a, NtmMat2 *b);
		
		/**
		 * Rotate `a` by `rad` radians and store the result in `out`.
		 */
		NtmMat2 *ntm_mat2_rotate(NtmMat2 *out, NtmMat2 *a, float rad);
		
		/**
		 * Scale `a` by `v` and store the result in `out`.
		 */
		NtmMat2 *ntm_mat2_scale(NtmMat2 *out, NtmMat2 *a, NtmVec2 *v);
		
		/**
		 * Create a rotation matrix from a rotation of `rad` radians and store
		 * the result in `out`.
		 */
		NtmMat2 *ntm_mat2_fromRotation(NtmMat2 *out, float rad);
		
		/**
		 * Create a scaling matrix from `v` and store the result in `out`.
		 */
		NtmMat2 *ntm_mat2_fromScaling(NtmMat2 *out, NtmVec2 *v);
		
		/**
		 * Get the frobenius norm of `a`.
		 */
		float ntm_mat2_frob(NtmMat2 *a);

	#ifdef __cplusplus
		}
	#endif

#endif /* NTM_SRC_NTM_MAT2_H_ */
