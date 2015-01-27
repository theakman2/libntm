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

#include "ntm_mat2.h"

#include <stdlib.h>
#include <math.h>

#include "ntm_common.h"

NtmMat2 *ntm_mat2_set(NtmMat2 *out, float a, float b, float c, float d) {
	out->data[0] = a;
	out->data[1] = b;
	out->data[2] = c;
	out->data[3] = d;
	return out;
}

NtmMat2 *ntm_mat2_identity(NtmMat2 *out) {
	float *d = out->data;
	d[0] = 1.0f;
	d[1] = 0.0f;
	d[2] = 0.0f;
	d[3] = 1.0f;
	return out;
}

NtmMat2 *ntm_mat2_copy(NtmMat2 *out, NtmMat2 *a) {
	float *o = out->data;
	float *f = a->data;
	o[0] = f[0];
	o[1] = f[1];
	o[2] = f[2];
	o[3] = f[3];
	return out;
}

NtmMat2 *ntm_mat2_transpose(NtmMat2 *out, NtmMat2 *a) {
	/* If we are transposing ourselves we can skip a few steps but have to cache some values */
	if (out == a) {
		float a1 = a->data[1];
		out->data[1] = a->data[2];
		out->data[2] = a1;
	} else {
		out->data[0] = a->data[0];
		out->data[1] = a->data[2];
		out->data[2] = a->data[1];
		out->data[3] = a->data[3];
	}

	return out;
}

NtmMat2 *ntm_mat2_invert(NtmMat2 *out, NtmMat2 *a) {
	float a0 = a->data[0], a1 = a->data[1], a2 = a->data[2], a3 = a->data[3],

		/* Calculate the determinant */
		invDet = 1.0f / (a0 * a3 - a2 * a1);

	out->data[0] =  a3 * invDet;
	out->data[1] = -a1 * invDet;
	out->data[2] = -a2 * invDet;
	out->data[3] =  a0 * invDet;

	return out;
}

NtmMat2 *ntm_mat2_adjoint(NtmMat2 *out, NtmMat2 *a) {
	/* Caching this value is necessary if out == a */
	float a0 = a->data[0];
	out->data[0] =  a->data[3];
	out->data[1] = -a->data[1];
	out->data[2] = -a->data[2];
	out->data[3] =  a0;

	return out;
}

float ntm_mat2_determinant(NtmMat2 *a) {
	return a->data[0] * a->data[3] - a->data[2] * a->data[1];
}

NtmMat2 *ntm_mat2_multiply(NtmMat2 *out, NtmMat2 *a, NtmMat2 *b) {
	float a0 = a->data[0], a1 = a->data[1], a2 = a->data[2], a3 = a->data[3];
	float b0 = b->data[0], b1 = b->data[1], b2 = b->data[2], b3 = b->data[3];
	out->data[0] = a0 * b0 + a2 * b1;
	out->data[1] = a1 * b0 + a3 * b1;
	out->data[2] = a0 * b2 + a2 * b3;
	out->data[3] = a1 * b2 + a3 * b3;
	return out;
}

NtmMat2 *ntm_mat2_rotate(NtmMat2 *out, NtmMat2 *a, float rad) {
	float a0 = a->data[0], a1 = a->data[1], a2 = a->data[2], a3 = a->data[3],
		s = (float)sin(rad),
		c = (float)cos(rad);
	out->data[0] = a0 *  c + a2 * s;
	out->data[1] = a1 *  c + a3 * s;
	out->data[2] = a0 * -s + a2 * c;
	out->data[3] = a1 * -s + a3 * c;
	return out;
}

NtmMat2 *ntm_mat2_scale(NtmMat2 *out, NtmMat2 *a, NtmVec2 *v) {
	float a0 = a->data[0], a1 = a->data[1], a2 = a->data[2], a3 = a->data[3],
		v0 = v->data[0], v1 = v->data[1];
	out->data[0] = a0 * v0;
	out->data[1] = a1 * v0;
	out->data[2] = a2 * v1;
	out->data[3] = a3 * v1;
	return out;
}

NtmMat2 *ntm_mat2_fromRotation(NtmMat2 *out, float rad) {
	float s = (float)sin(rad),
		c = (float)cos(rad);
	out->data[0] = c;
	out->data[1] = s;
	out->data[2] = -s;
	out->data[3] = c;
	return out;
}

NtmMat2 *ntm_mat2_fromScaling(NtmMat2 *out, NtmVec2 *v) {
	out->data[0] = v->data[0];
	out->data[1] = 0;
	out->data[2] = 0;
	out->data[3] = v->data[1];
	return out;
}

float ntm_mat2_frob(NtmMat2 *a) {
	float a0 = a->data[0], a1 = a->data[1], a2 = a->data[2], a3 = a->data[3];
	return((float)sqrt(
		a0*a0
		+ a1*a1
		+ a2*a2
		+ a3*a3
	));
}
