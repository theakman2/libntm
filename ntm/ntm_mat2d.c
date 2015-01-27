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

#include "ntm_mat2d.h"

#include <stdlib.h>
#include <math.h>

#include "ntm_common.h"

NtmMat2d *ntm_mat2d_set(NtmMat2d *out, float a, float b, float c, float d, float e, float f) {
	out->data[0] = a;
	out->data[1] = b;
	out->data[2] = c;
	out->data[3] = d;
	out->data[4] = e;
	out->data[5] = f;
	return out;
}

NtmMat2d *ntm_mat2d_identity(NtmMat2d *out) {
	out->data[0] = 1.0f;
	out->data[1] = 0.0f;
	out->data[2] = 0.0f;
	out->data[3] = 1.0f;
	out->data[4] = 0.0f;
	out->data[5] = 0.0f;
	return out;
}

NtmMat2d *ntm_mat2d_copy(NtmMat2d *out, NtmMat2d *a) {
	out->data[0] = a->data[0];
	out->data[1] = a->data[1];
	out->data[2] = a->data[2];
	out->data[3] = a->data[3];
	out->data[4] = a->data[4];
	out->data[5] = a->data[5];
	return out;
}

NtmMat2d *ntm_mat2d_invert(NtmMat2d *out, NtmMat2d *a) {
	float aa = a->data[0], ab = a->data[1], ac = a->data[2], ad = a->data[3],
		atx = a->data[4], aty = a->data[5];

	float invDet = 1.0f / (aa * ad - ab * ac);

	out->data[0] = ad * invDet;
	out->data[1] = -ab * invDet;
	out->data[2] = -ac * invDet;
	out->data[3] = aa * invDet;
	out->data[4] = (ac * aty - ad * atx) * invDet;
	out->data[5] = (ab * atx - aa * aty) * invDet;
	return out;
}

float ntm_mat2d_determinant(NtmMat2d *a) {
	return a->data[0] * a->data[3] - a->data[1] * a->data[2];
}

NtmMat2d *ntm_mat2d_multiply(NtmMat2d *out, NtmMat2d *a, NtmMat2d *b) {
	float a0 = a->data[0], a1 = a->data[1], a2 = a->data[2],
			a3 = a->data[3], a4 = a->data[4], a5 = a->data[5];
	float b0 = b->data[0], b1 = b->data[1], b2 = b->data[2],
			b3 = b->data[3], b4 = b->data[4], b5 = b->data[5];
	out->data[0] = a0 * b0 + a2 * b1;
	out->data[1] = a1 * b0 + a3 * b1;
	out->data[2] = a0 * b2 + a2 * b3;
	out->data[3] = a1 * b2 + a3 * b3;
	out->data[4] = a0 * b4 + a2 * b5 + a4;
	out->data[5] = a1 * b4 + a3 * b5 + a5;
	return out;
}

NtmMat2d *ntm_mat2d_rotate(NtmMat2d *out, NtmMat2d *a, float rad) {
	float a0 = a->data[0], a1 = a->data[1], a2 = a->data[2],
			a3 = a->data[3], a4 = a->data[4], a5 = a->data[5],
			s = (float)sin(rad),
			c = (float)cos(rad);
	out->data[0] = a0 *  c + a2 * s;
	out->data[1] = a1 *  c + a3 * s;
	out->data[2] = a0 * -s + a2 * c;
	out->data[3] = a1 * -s + a3 * c;
	out->data[4] = a4;
	out->data[5] = a5;
	return out;
}

NtmMat2d *ntm_mat2d_scale(NtmMat2d *out, NtmMat2d *a, NtmVec2 *v) {
	float a0 = a->data[0], a1 = a->data[1], a2 = a->data[2],
			a3 = a->data[3], a4 = a->data[4], a5 = a->data[5],
			v0 = v->data[0], v1 = v->data[1];
	out->data[0] = a0 * v0;
	out->data[1] = a1 * v0;
	out->data[2] = a2 * v1;
	out->data[3] = a3 * v1;
	out->data[4] = a4;
	out->data[5] = a5;
	return out;
}

NtmMat2d *ntm_mat2d_translate(NtmMat2d *out, NtmMat2d *a, NtmVec2 *v) {
	float a0 = a->data[0], a1 = a->data[1], a2 = a->data[2],
			a3 = a->data[3], a4 = a->data[4], a5 = a->data[5],
			v0 = v->data[0], v1 = v->data[1];
	out->data[0] = a0;
	out->data[1] = a1;
	out->data[2] = a2;
	out->data[3] = a3;
	out->data[4] = a0 * v0 + a2 * v1 + a4;
	out->data[5] = a1 * v0 + a3 * v1 + a5;
	return out;
}

NtmMat2d *ntm_mat2d_fromRotation(NtmMat2d *out, float rad) {
	float s = (float)sin(rad), c = (float)cos(rad);
	out->data[0] = c;
	out->data[1] = s;
	out->data[2] = -s;
	out->data[3] = c;
	out->data[4] = 0.0f;
	out->data[5] = 0.0f;
	return out;
}

NtmMat2d *ntm_mat2d_fromScaling(NtmMat2d *out, NtmVec2 *v) {
	out->data[0] = v->data[0];
	out->data[1] = 0.0f;
	out->data[2] = 0.0f;
	out->data[3] = v->data[1];
	out->data[4] = 0.0f;
	out->data[5] = 0.0f;
	return out;
}

NtmMat2d *ntm_mat2d_fromTranslation(NtmMat2d *out, NtmVec2 *v) {
	out->data[0] = 1.0f;
	out->data[1] = 0.0f;
	out->data[2] = 0.0f;
	out->data[3] = 1.0f;
	out->data[4] = v->data[0];
	out->data[5] = v->data[1];
	return out;
}

float ntm_mat2d_frob(NtmMat2d *a) {
	float a0 = a->data[0], a1 = a->data[1], a2 = a->data[2],
			a3 = a->data[3], a4 = a->data[4], a5 = a->data[5];
	return((float)sqrt(
		a0*a0
		+ a1*a1
		+ a2*a2
		+ a3*a3
		+ a4*a4
		+ a5*a5
		+ 1.0f
	));
}
