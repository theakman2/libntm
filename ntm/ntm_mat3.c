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

#include "ntm_mat3.h"

#include <stdlib.h>
#include <math.h>

#include "ntm_common.h"

NtmMat3 *ntm_mat3_identity(NtmMat3 *out) {
	float *o = out->data;
	o[0] = 1.0f;
	o[1] = 0.0f;
	o[2] = 0.0f;
	o[3] = 0.0f;
	o[4] = 1.0f;
	o[5] = 0.0f;
	o[6] = 0.0f;
	o[7] = 0.0f;
	o[8] = 1.0f;
	return out;
}

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
) {
	float *d = out->data;
	d[0] = a00;		d[3] = a10;		d[6] = a20;
	d[1] = a01;		d[4] = a11;		d[7] = a21;
	d[2] = a02;		d[5] = a12;		d[8] = a22;
	return out;
}

NtmMat3 *ntm_mat3_copy(NtmMat3 *out, NtmMat3 *a) {
	float *o = out->data;
	float *f = a->data;
	o[0] = f[0];
	o[1] = f[1];
	o[2] = f[2];
	o[3] = f[3];
	o[4] = f[4];
	o[5] = f[5];
	o[6] = f[6];
	o[7] = f[7];
	o[8] = f[8];
	return out;
}

NtmMat3 *ntm_mat3_fromMat4(NtmMat3 *out, NtmMat4 *a) {
	float *o = out->data;
	float *f = a->data;
	o[0] = f[0];
	o[1] = f[1];
	o[2] = f[2];
	o[3] = f[4];
	o[4] = f[5];
	o[5] = f[6];
	o[6] = f[8];
	o[7] = f[9];
	o[8] = f[10];
	return out;
}

NtmMat3 *ntm_mat3_transpose(NtmMat3 *out, NtmMat3 *a) {
	/* If we are transposing ourselves we can skip a few steps but have to cache some values */
	if (out == a) {
		float a01 = a->data[1], a02 = a->data[2], a12 = a->data[5];
		out->data[1] = a->data[3];
		out->data[2] = a->data[6];
		out->data[3] = a01;
		out->data[5] = a->data[7];
		out->data[6] = a02;
		out->data[7] = a12;
	} else {
		out->data[0] = a->data[0];
		out->data[1] = a->data[3];
		out->data[2] = a->data[6];
		out->data[3] = a->data[1];
		out->data[4] = a->data[4];
		out->data[5] = a->data[7];
		out->data[6] = a->data[2];
		out->data[7] = a->data[5];
		out->data[8] = a->data[8];
	}

	return out;
}

NtmMat3 *ntm_mat3_invert(NtmMat3 *out, NtmMat3 *a) {
	float a00 = a->data[0], a01 = a->data[1], a02 = a->data[2],
		a10 = a->data[3], a11 = a->data[4], a12 = a->data[5],
		a20 = a->data[6], a21 = a->data[7], a22 = a->data[8],

		b01 = a22 * a11 - a12 * a21,
		b11 = -a22 * a10 + a12 * a20,
		b21 = a21 * a10 - a11 * a20,

		/* Calculate the determinant */
		invDet = 1.0f / (a00 * b01 + a01 * b11 + a02 * b21);

	out->data[0] = b01 * invDet;
	out->data[1] = (-a22 * a01 + a02 * a21) * invDet;
	out->data[2] = (a12 * a01 - a02 * a11) * invDet;
	out->data[3] = b11 * invDet;
	out->data[4] = (a22 * a00 - a02 * a20) * invDet;
	out->data[5] = (-a12 * a00 + a02 * a10) * invDet;
	out->data[6] = b21 * invDet;
	out->data[7] = (-a21 * a00 + a01 * a20) * invDet;
	out->data[8] = (a11 * a00 - a01 * a10) * invDet;
	return out;
}

NtmMat3 *ntm_mat3_adjoint(NtmMat3 *out, NtmMat3 *a) {
	float a00 = a->data[0], a01 = a->data[1], a02 = a->data[2],
		a10 = a->data[3], a11 = a->data[4], a12 = a->data[5],
		a20 = a->data[6], a21 = a->data[7], a22 = a->data[8];

	out->data[0] = (a11 * a22 - a12 * a21);
	out->data[1] = (a02 * a21 - a01 * a22);
	out->data[2] = (a01 * a12 - a02 * a11);
	out->data[3] = (a12 * a20 - a10 * a22);
	out->data[4] = (a00 * a22 - a02 * a20);
	out->data[5] = (a02 * a10 - a00 * a12);
	out->data[6] = (a10 * a21 - a11 * a20);
	out->data[7] = (a01 * a20 - a00 * a21);
	out->data[8] = (a00 * a11 - a01 * a10);
	return out;
}

float ntm_mat3_determinant(NtmMat3 *a) {
	float a00 = a->data[0], a01 = a->data[1], a02 = a->data[2],
		a10 = a->data[3], a11 = a->data[4], a12 = a->data[5],
		a20 = a->data[6], a21 = a->data[7], a22 = a->data[8];

	return a00 * (a22 * a11 - a12 * a21) + a01 * (-a22 * a10 + a12 * a20) + a02 * (a21 * a10 - a11 * a20);
}

NtmMat3 *ntm_mat3_multiply(NtmMat3 *out, NtmMat3 *a, NtmMat3 *b) {
	float a00 = a->data[0], a01 = a->data[1], a02 = a->data[2],
		a10 = a->data[3], a11 = a->data[4], a12 = a->data[5],
		a20 = a->data[6], a21 = a->data[7], a22 = a->data[8],

		b00 = b->data[0], b01 = b->data[1], b02 = b->data[2],
		b10 = b->data[3], b11 = b->data[4], b12 = b->data[5],
		b20 = b->data[6], b21 = b->data[7], b22 = b->data[8];

	out->data[0] = b00 * a00 + b01 * a10 + b02 * a20;
	out->data[1] = b00 * a01 + b01 * a11 + b02 * a21;
	out->data[2] = b00 * a02 + b01 * a12 + b02 * a22;

	out->data[3] = b10 * a00 + b11 * a10 + b12 * a20;
	out->data[4] = b10 * a01 + b11 * a11 + b12 * a21;
	out->data[5] = b10 * a02 + b11 * a12 + b12 * a22;

	out->data[6] = b20 * a00 + b21 * a10 + b22 * a20;
	out->data[7] = b20 * a01 + b21 * a11 + b22 * a21;
	out->data[8] = b20 * a02 + b21 * a12 + b22 * a22;
	return out;
}

NtmMat3 *ntm_mat3_translate(NtmMat3 *out, NtmMat3 *a, NtmVec2 *v) {
	float a00 = a->data[0], a01 = a->data[1], a02 = a->data[2],
		a10 = a->data[3], a11 = a->data[4], a12 = a->data[5],
		a20 = a->data[6], a21 = a->data[7], a22 = a->data[8],
		x = v->data[0], y = v->data[1];

	out->data[0] = a00;
	out->data[1] = a01;
	out->data[2] = a02;

	out->data[3] = a10;
	out->data[4] = a11;
	out->data[5] = a12;

	out->data[6] = x * a00 + y * a10 + a20;
	out->data[7] = x * a01 + y * a11 + a21;
	out->data[8] = x * a02 + y * a12 + a22;
	return out;
}

NtmMat3 *ntm_mat3_rotate(NtmMat3 *out, NtmMat3 *a, float rad) {
	float a00 = a->data[0], a01 = a->data[1], a02 = a->data[2],
		a10 = a->data[3], a11 = a->data[4], a12 = a->data[5],
		a20 = a->data[6], a21 = a->data[7], a22 = a->data[8],

		s = (float)sin(rad),
		c = (float)cos(rad);

	out->data[0] = c * a00 + s * a10;
	out->data[1] = c * a01 + s * a11;
	out->data[2] = c * a02 + s * a12;

	out->data[3] = c * a10 - s * a00;
	out->data[4] = c * a11 - s * a01;
	out->data[5] = c * a12 - s * a02;

	out->data[6] = a20;
	out->data[7] = a21;
	out->data[8] = a22;
	return out;
}

NtmMat3 *ntm_mat3_scale(NtmMat3 *out, NtmMat3 *a, NtmVec2 *v) {
	float x = v->data[0], y = v->data[1];

	out->data[0] = x * a->data[0];
	out->data[1] = x * a->data[1];
	out->data[2] = x * a->data[2];

	out->data[3] = y * a->data[3];
	out->data[4] = y * a->data[4];
	out->data[5] = y * a->data[5];

	out->data[6] = a->data[6];
	out->data[7] = a->data[7];
	out->data[8] = a->data[8];
	return out;
}

NtmMat3 *ntm_mat3_fromTranslation(NtmMat3 *out, NtmVec2 *v) {
	out->data[0] = 1.0f;
	out->data[1] = 0.0f;
	out->data[2] = 0.0f;
	out->data[3] = 0.0f;
	out->data[4] = 1.0f;
	out->data[5] = 0.0f;
	out->data[6] = v->data[0];
	out->data[7] = v->data[1];
	out->data[8] = 1.0f;
	return out;
}

NtmMat3 *ntm_mat3_fromRotation(NtmMat3 *out, float rad) {
	float s = (float)sin(rad), c = (float)cos(rad);

	out->data[0] = c;
	out->data[1] = s;
	out->data[2] = 0;

	out->data[3] = -s;
	out->data[4] = c;
	out->data[5] = 0.0f;

	out->data[6] = 0.0f;
	out->data[7] = 0.0f;
	out->data[8] = 1.0f;
	return out;
}

NtmMat3 *ntm_mat3_fromScaling(NtmMat3 *out, NtmVec2 *v) {
	out->data[0] = v->data[0];
	out->data[1] = 0.0f;
	out->data[2] = 0.0f;

	out->data[3] = 0.0f;
	out->data[4] = v->data[1];
	out->data[5] = 0.0f;

	out->data[6] = 0.0f;
	out->data[7] = 0.0f;
	out->data[8] = 1.0f;
	return out;
}

NtmMat3 *ntm_mat3_fromMat2d(NtmMat3 *out, NtmMat2d *a) {
	out->data[0] = a->data[0];
	out->data[1] = a->data[1];
	out->data[2] = 0.0f;

	out->data[3] = a->data[2];
	out->data[4] = a->data[3];
	out->data[5] = 0.0f;

	out->data[6] = a->data[4];
	out->data[7] = a->data[5];
	out->data[8] = 1.0f;
	return out;
}

NtmMat3 *ntm_mat3_fromQuat(NtmMat3 *out, NtmQuat *q) {
	float x = q->data[0], y = q->data[1], z = q->data[2], w = q->data[3],
		x2 = x + x,
		y2 = y + y,
		z2 = z + z,

		xx = x * x2,
		yx = y * x2,
		yy = y * y2,
		zx = z * x2,
		zy = z * y2,
		zz = z * z2,
		wx = w * x2,
		wy = w * y2,
		wz = w * z2;

	out->data[0] = 1.0f - yy - zz;
	out->data[3] = yx - wz;
	out->data[6] = zx + wy;

	out->data[1] = yx + wz;
	out->data[4] = 1.0f - xx - zz;
	out->data[7] = zy - wx;

	out->data[2] = zx - wy;
	out->data[5] = zy + wx;
	out->data[8] = 1.0f - xx - yy;

	return out;
}

NtmMat3 *ntm_mat3_normalFromMat4(NtmMat3 *out, NtmMat4 *a) {
	float a00 = a->data[0], a01 = a->data[1], a02 = a->data[2], a03 = a->data[3],
		a10 = a->data[4], a11 = a->data[5], a12 = a->data[6], a13 = a->data[7],
		a20 = a->data[8], a21 = a->data[9], a22 = a->data[10], a23 = a->data[11],
		a30 = a->data[12], a31 = a->data[13], a32 = a->data[14], a33 = a->data[15],

		b00 = a00 * a11 - a01 * a10,
		b01 = a00 * a12 - a02 * a10,
		b02 = a00 * a13 - a03 * a10,
		b03 = a01 * a12 - a02 * a11,
		b04 = a01 * a13 - a03 * a11,
		b05 = a02 * a13 - a03 * a12,
		b06 = a20 * a31 - a21 * a30,
		b07 = a20 * a32 - a22 * a30,
		b08 = a20 * a33 - a23 * a30,
		b09 = a21 * a32 - a22 * a31,
		b10 = a21 * a33 - a23 * a31,
		b11 = a22 * a33 - a23 * a32,

		/* Calculate the determinant */
		invDet = 1.0f / (b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06);

	out->data[0] = (a11 * b11 - a12 * b10 + a13 * b09) * invDet;
	out->data[1] = (a12 * b08 - a10 * b11 - a13 * b07) * invDet;
	out->data[2] = (a10 * b10 - a11 * b08 + a13 * b06) * invDet;

	out->data[3] = (a02 * b10 - a01 * b11 - a03 * b09) * invDet;
	out->data[4] = (a00 * b11 - a02 * b08 + a03 * b07) * invDet;
	out->data[5] = (a01 * b08 - a00 * b10 - a03 * b06) * invDet;

	out->data[6] = (a31 * b05 - a32 * b04 + a33 * b03) * invDet;
	out->data[7] = (a32 * b02 - a30 * b05 - a33 * b01) * invDet;
	out->data[8] = (a30 * b04 - a31 * b02 + a33 * b00) * invDet;

	return out;
}

float ntm_mat3_frob(NtmMat3 *a) {
	float a0 = a->data[0], a1 = a->data[1], a2 = a->data[2],
			a3 = a->data[3], a4 = a->data[4], a5 = a->data[5],
			a6 = a->data[6], a7 = a->data[7], a8 = a->data[8];
	return (float)(sqrt(
		a0*a0
		+ a1*a1
		+ a2*a2
		+ a3*a3
		+ a4*a4
		+ a5*a5
		+ a6*a6
		+ a7*a7
		+ a8*a8
	));
}
