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

/**
 * An NtmMat2d is an NtmMat3 except that the final three values of the matrix
 * are assumed to be 0.0f, 0.0f and 1.0f. As NtmMat2ds have three fewer
 * elements than NtmMat3s, operations on them are faster and they take up less
 * memory.
 */

#ifndef NTM_SRC_NTM_MAT2D_H_
#define NTM_SRC_NTM_MAT2D_H_

	#ifdef __cplusplus
		extern "C" {
	#endif

		#include "ntm_common.h"

		/**
		 * Set the values of `out` to the given floats.
		 */
		NtmMat2d *ntm_mat2d_set(NtmMat2d *out, float a, float b, float c, float d, float e, float f);
		
		/**
		 * Set `out` to the identity matrix.
		 */
		NtmMat2d *ntm_mat2d_identity(NtmMat2d *out);
		
		/**
		 * Copy the values of `a` into `out`.
		 */
		NtmMat2d *ntm_mat2d_copy(NtmMat2d *out, NtmMat2d *a);
		
		/**
		 * Calculate the inverse of `a` and store the result in `out`.
		 */
		NtmMat2d *ntm_mat2d_invert(NtmMat2d *out, NtmMat2d *a);
		
		/**
		 * Get the determinant of `a`.
		 */
		float ntm_mat2d_determinant(NtmMat2d *a);
		
		/**
		 * Transform `b` by `a` and store the result in `out`.
		 */
		NtmMat2d *ntm_mat2d_multiply(NtmMat2d *out, NtmMat2d *a, NtmMat2d *b);
		
		/**
		 * Rotate `a` by `rad` radians and store the result in `out`.
		 */
		NtmMat2d *ntm_mat2d_rotate(NtmMat2d *out, NtmMat2d *a, float rad);
		
		/**
		 * Scale `a` by `v` and store the result in `out`.
		 */
		NtmMat2d *ntm_mat2d_scale(NtmMat2d *out, NtmMat2d *a, NtmVec2 *v);
		
		/**
		 * Translate `a` by `v` and store the result in `out`.
		 */
		NtmMat2d *ntm_mat2d_translate(NtmMat2d *out, NtmMat2d *a, NtmVec2 *v);
		
		/**
		 * Create a rotation matrix from a rotation of `rad` radians and store
		 * the result in `out`.
		 */
		NtmMat2d *ntm_mat2d_fromRotation(NtmMat2d *out, float rad);
		
		/**
		 * Create a scaling matrix from a scale of `v` and store the result in
		 * `out`.
		 */
		NtmMat2d *ntm_mat2d_fromScaling(NtmMat2d *out, NtmVec2 *v);
		
		/**
		 * Create a translation matrix from `v` and store the result in `out`.
		 */
		NtmMat2d *ntm_mat2d_fromTranslation(NtmMat2d *out, NtmVec2 *v);
		
		/**
		 * Calculate the frobenius norm of `a`.
		 */
		float ntm_mat2d_frob(NtmMat2d *a);

	#ifdef __cplusplus
		}
	#endif

#endif /* NTM_SRC_NTM_MAT2D_H_ */
