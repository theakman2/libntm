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

#include "ntm_mat4.h"

#include <stdlib.h>
#include <math.h>

#include "ntm_common.h"

NtmMat4 *ntm_mat4_identity(NtmMat4 *out) {
	out->data[0] = 1.0f;
	out->data[1] = 0.0f;
	out->data[2] = 0.0f;
	out->data[3] = 0.0f;
	out->data[4] = 0.0f;
	out->data[5] = 1.0f;
	out->data[6] = 0.0f;
	out->data[7] = 0.0f;
	out->data[8] = 0.0f;
	out->data[9] = 0.0f;
	out->data[10] = 1.0f;
	out->data[11] = 0.0f;
	out->data[12] = 0.0f;
	out->data[13] = 0.0f;
	out->data[14] = 0.0f;
	out->data[15] = 1.0f;
	return out;
}

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
) {
	float *d = out->data;
	d[0] = a00;		d[4] = a10;		d[8] = a20;		d[12] = a30;
	d[1] = a01;		d[5] = a11;		d[9] = a21;		d[13] = a31;
	d[2] = a02;		d[6] = a12;		d[10] = a22;	d[14] = a32;
	d[3] = a03;		d[7] = a13;		d[11] = a23;	d[15] = a33;
	return out;
}

NtmMat4 *ntm_mat4_copy(NtmMat4 *out, NtmMat4 *a) {
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
	o[9] = f[9];
	o[10] = f[10];
	o[11] = f[11];
	o[12] = f[12];
	o[13] = f[13];
	o[14] = f[14];
	o[15] = f[15];
	return out;
}

NtmMat4 *ntm_mat4_transpose(NtmMat4 *out, NtmMat4 *a) {
	if (out == a) {
		float a01 = a->data[1], a02 = a->data[2], a03 = a->data[3],
			a12 = a->data[6], a13 = a->data[7],
			a23 = a->data[11];

		out->data[1] = a->data[4];
		out->data[2] = a->data[8];
		out->data[3] = a->data[12];
		out->data[4] = a01;
		out->data[6] = a->data[9];
		out->data[7] = a->data[13];
		out->data[8] = a02;
		out->data[9] = a12;
		out->data[11] = a->data[14];
		out->data[12] = a03;
		out->data[13] = a13;
		out->data[14] = a23;
	} else {
		out->data[0] = a->data[0];
		out->data[1] = a->data[4];
		out->data[2] = a->data[8];
		out->data[3] = a->data[12];
		out->data[4] = a->data[1];
		out->data[5] = a->data[5];
		out->data[6] = a->data[9];
		out->data[7] = a->data[13];
		out->data[8] = a->data[2];
		out->data[9] = a->data[6];
		out->data[10] = a->data[10];
		out->data[11] = a->data[14];
		out->data[12] = a->data[3];
		out->data[13] = a->data[7];
		out->data[14] = a->data[11];
		out->data[15] = a->data[15];
	}
	return out;
}

NtmMat4 *ntm_mat4_invert(NtmMat4 *out, NtmMat4 *a) {
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

		invDet = 1.0f / (b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06);

	out->data[0] = (a11 * b11 - a12 * b10 + a13 * b09) * invDet;
	out->data[1] = (a02 * b10 - a01 * b11 - a03 * b09) * invDet;
	out->data[2] = (a31 * b05 - a32 * b04 + a33 * b03) * invDet;
	out->data[3] = (a22 * b04 - a21 * b05 - a23 * b03) * invDet;
	out->data[4] = (a12 * b08 - a10 * b11 - a13 * b07) * invDet;
	out->data[5] = (a00 * b11 - a02 * b08 + a03 * b07) * invDet;
	out->data[6] = (a32 * b02 - a30 * b05 - a33 * b01) * invDet;
	out->data[7] = (a20 * b05 - a22 * b02 + a23 * b01) * invDet;
	out->data[8] = (a10 * b10 - a11 * b08 + a13 * b06) * invDet;
	out->data[9] = (a01 * b08 - a00 * b10 - a03 * b06) * invDet;
	out->data[10] = (a30 * b04 - a31 * b02 + a33 * b00) * invDet;
	out->data[11] = (a21 * b02 - a20 * b04 - a23 * b00) * invDet;
	out->data[12] = (a11 * b07 - a10 * b09 - a12 * b06) * invDet;
	out->data[13] = (a00 * b09 - a01 * b07 + a02 * b06) * invDet;
	out->data[14] = (a31 * b01 - a30 * b03 - a32 * b00) * invDet;
	out->data[15] = (a20 * b03 - a21 * b01 + a22 * b00) * invDet;
	return out;
}

NtmMat4 *ntm_mat4_adjoint(NtmMat4 *out, NtmMat4 *a) {
	float a00 = a->data[0], a01 = a->data[1], a02 = a->data[2], a03 = a->data[3],
		a10 = a->data[4], a11 = a->data[5], a12 = a->data[6], a13 = a->data[7],
		a20 = a->data[8], a21 = a->data[9], a22 = a->data[10], a23 = a->data[11],
		a30 = a->data[12], a31 = a->data[13], a32 = a->data[14], a33 = a->data[15];

	out->data[0]  =  (a11 * (a22 * a33 - a23 * a32) - a21 * (a12 * a33 - a13 * a32) + a31 * (a12 * a23 - a13 * a22));
	out->data[1]  = -(a01 * (a22 * a33 - a23 * a32) - a21 * (a02 * a33 - a03 * a32) + a31 * (a02 * a23 - a03 * a22));
	out->data[2]  =  (a01 * (a12 * a33 - a13 * a32) - a11 * (a02 * a33 - a03 * a32) + a31 * (a02 * a13 - a03 * a12));
	out->data[3]  = -(a01 * (a12 * a23 - a13 * a22) - a11 * (a02 * a23 - a03 * a22) + a21 * (a02 * a13 - a03 * a12));
	out->data[4]  = -(a10 * (a22 * a33 - a23 * a32) - a20 * (a12 * a33 - a13 * a32) + a30 * (a12 * a23 - a13 * a22));
	out->data[5]  =  (a00 * (a22 * a33 - a23 * a32) - a20 * (a02 * a33 - a03 * a32) + a30 * (a02 * a23 - a03 * a22));
	out->data[6]  = -(a00 * (a12 * a33 - a13 * a32) - a10 * (a02 * a33 - a03 * a32) + a30 * (a02 * a13 - a03 * a12));
	out->data[7]  =  (a00 * (a12 * a23 - a13 * a22) - a10 * (a02 * a23 - a03 * a22) + a20 * (a02 * a13 - a03 * a12));
	out->data[8]  =  (a10 * (a21 * a33 - a23 * a31) - a20 * (a11 * a33 - a13 * a31) + a30 * (a11 * a23 - a13 * a21));
	out->data[9]  = -(a00 * (a21 * a33 - a23 * a31) - a20 * (a01 * a33 - a03 * a31) + a30 * (a01 * a23 - a03 * a21));
	out->data[10] =  (a00 * (a11 * a33 - a13 * a31) - a10 * (a01 * a33 - a03 * a31) + a30 * (a01 * a13 - a03 * a11));
	out->data[11] = -(a00 * (a11 * a23 - a13 * a21) - a10 * (a01 * a23 - a03 * a21) + a20 * (a01 * a13 - a03 * a11));
	out->data[12] = -(a10 * (a21 * a32 - a22 * a31) - a20 * (a11 * a32 - a12 * a31) + a30 * (a11 * a22 - a12 * a21));
	out->data[13] =  (a00 * (a21 * a32 - a22 * a31) - a20 * (a01 * a32 - a02 * a31) + a30 * (a01 * a22 - a02 * a21));
	out->data[14] = -(a00 * (a11 * a32 - a12 * a31) - a10 * (a01 * a32 - a02 * a31) + a30 * (a01 * a12 - a02 * a11));
	out->data[15] =  (a00 * (a11 * a22 - a12 * a21) - a10 * (a01 * a22 - a02 * a21) + a20 * (a01 * a12 - a02 * a11));
	return out;
}

float ntm_mat4_determinant(NtmMat4 *a) {
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
		b11 = a22 * a33 - a23 * a32;

	return b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06;
}

NtmMat4 *ntm_mat4_multiply(NtmMat4 *out, NtmMat4 *a, NtmMat4 *b) {
	float a00 = a->data[0], a01 = a->data[1], a02 = a->data[2], a03 = a->data[3],
		a10 = a->data[4], a11 = a->data[5], a12 = a->data[6], a13 = a->data[7],
		a20 = a->data[8], a21 = a->data[9], a22 = a->data[10], a23 = a->data[11],
		a30 = a->data[12], a31 = a->data[13], a32 = a->data[14], a33 = a->data[15];

	float b0  = b->data[0], b1 = b->data[1], b2 = b->data[2], b3 = b->data[3];
	out->data[0] = b0*a00 + b1*a10 + b2*a20 + b3*a30;
	out->data[1] = b0*a01 + b1*a11 + b2*a21 + b3*a31;
	out->data[2] = b0*a02 + b1*a12 + b2*a22 + b3*a32;
	out->data[3] = b0*a03 + b1*a13 + b2*a23 + b3*a33;

	b0 = b->data[4]; b1 = b->data[5]; b2 = b->data[6]; b3 = b->data[7];
	out->data[4] = b0*a00 + b1*a10 + b2*a20 + b3*a30;
	out->data[5] = b0*a01 + b1*a11 + b2*a21 + b3*a31;
	out->data[6] = b0*a02 + b1*a12 + b2*a22 + b3*a32;
	out->data[7] = b0*a03 + b1*a13 + b2*a23 + b3*a33;

	b0 = b->data[8]; b1 = b->data[9]; b2 = b->data[10]; b3 = b->data[11];
	out->data[8] = b0*a00 + b1*a10 + b2*a20 + b3*a30;
	out->data[9] = b0*a01 + b1*a11 + b2*a21 + b3*a31;
	out->data[10] = b0*a02 + b1*a12 + b2*a22 + b3*a32;
	out->data[11] = b0*a03 + b1*a13 + b2*a23 + b3*a33;

	b0 = b->data[12]; b1 = b->data[13]; b2 = b->data[14]; b3 = b->data[15];
	out->data[12] = b0*a00 + b1*a10 + b2*a20 + b3*a30;
	out->data[13] = b0*a01 + b1*a11 + b2*a21 + b3*a31;
	out->data[14] = b0*a02 + b1*a12 + b2*a22 + b3*a32;
	out->data[15] = b0*a03 + b1*a13 + b2*a23 + b3*a33;
	return out;
}

NtmMat4 *ntm_mat4_translate(NtmMat4 *out, NtmMat4 *a, NtmVec3 *v) {
	float x = v->data[0], y = v->data[1], z = v->data[2],
		a00, a01, a02, a03,
		a10, a11, a12, a13,
		a20, a21, a22, a23;

	if (a == out) {
		out->data[12] = a->data[0] * x + a->data[4] * y + a->data[8] * z + a->data[12];
		out->data[13] = a->data[1] * x + a->data[5] * y + a->data[9] * z + a->data[13];
		out->data[14] = a->data[2] * x + a->data[6] * y + a->data[10] * z + a->data[14];
		out->data[15] = a->data[3] * x + a->data[7] * y + a->data[11] * z + a->data[15];
	} else {
		a00 = a->data[0]; a01 = a->data[1]; a02 = a->data[2]; a03 = a->data[3];
		a10 = a->data[4]; a11 = a->data[5]; a12 = a->data[6]; a13 = a->data[7];
		a20 = a->data[8]; a21 = a->data[9]; a22 = a->data[10]; a23 = a->data[11];

		out->data[0] = a00; out->data[1] = a01; out->data[2] = a02; out->data[3] = a03;
		out->data[4] = a10; out->data[5] = a11; out->data[6] = a12; out->data[7] = a13;
		out->data[8] = a20; out->data[9] = a21; out->data[10] = a22; out->data[11] = a23;

		out->data[12] = a00 * x + a10 * y + a20 * z + a->data[12];
		out->data[13] = a01 * x + a11 * y + a21 * z + a->data[13];
		out->data[14] = a02 * x + a12 * y + a22 * z + a->data[14];
		out->data[15] = a03 * x + a13 * y + a23 * z + a->data[15];
	}
	return out;
}

NtmMat4 *ntm_mat4_scale(NtmMat4 *out, NtmMat4 *a, NtmVec3 *v) {
	float x = v->data[0], y = v->data[1], z = v->data[2];

	out->data[0] = a->data[0] * x;
	out->data[1] = a->data[1] * x;
	out->data[2] = a->data[2] * x;
	out->data[3] = a->data[3] * x;
	out->data[4] = a->data[4] * y;
	out->data[5] = a->data[5] * y;
	out->data[6] = a->data[6] * y;
	out->data[7] = a->data[7] * y;
	out->data[8] = a->data[8] * z;
	out->data[9] = a->data[9] * z;
	out->data[10] = a->data[10] * z;
	out->data[11] = a->data[11] * z;
	out->data[12] = a->data[12];
	out->data[13] = a->data[13];
	out->data[14] = a->data[14];
	out->data[15] = a->data[15];

	return out;
}

NtmMat4 *ntm_mat4_rotate(NtmMat4 *out, NtmMat4 *a, float rad, NtmVec3 *axis) {
	float x = axis->data[0];
	float y = axis->data[1];
	float z = axis->data[2];
	float invLen = 1.0f / (float)sqrt(x * x + y * y + z * z);
	float s, c, t, a00, a01, a02, a03,
		a10, a11, a12, a13,
		a20, a21, a22, a23,
		b00, b01, b02,
		b10, b11, b12,
		b20, b21, b22;

	s = (float)sin(rad);
	c = (float)cos(rad);
	t = 1.0f - c;

	x *= invLen;
	y *= invLen;
	z *= invLen;

	a00 = a->data[0]; a01 = a->data[1]; a02 = a->data[2]; a03 = a->data[3];
	a10 = a->data[4]; a11 = a->data[5]; a12 = a->data[6]; a13 = a->data[7];
	a20 = a->data[8]; a21 = a->data[9]; a22 = a->data[10]; a23 = a->data[11];

	b00 = x * x * t + c; b01 = y * x * t + z * s; b02 = z * x * t - y * s;
	b10 = x * y * t - z * s; b11 = y * y * t + c; b12 = z * y * t + x * s;
	b20 = x * z * t + y * s; b21 = y * z * t - x * s; b22 = z * z * t + c;

	out->data[0] = a00 * b00 + a10 * b01 + a20 * b02;
	out->data[1] = a01 * b00 + a11 * b01 + a21 * b02;
	out->data[2] = a02 * b00 + a12 * b01 + a22 * b02;
	out->data[3] = a03 * b00 + a13 * b01 + a23 * b02;
	out->data[4] = a00 * b10 + a10 * b11 + a20 * b12;
	out->data[5] = a01 * b10 + a11 * b11 + a21 * b12;
	out->data[6] = a02 * b10 + a12 * b11 + a22 * b12;
	out->data[7] = a03 * b10 + a13 * b11 + a23 * b12;
	out->data[8] = a00 * b20 + a10 * b21 + a20 * b22;
	out->data[9] = a01 * b20 + a11 * b21 + a21 * b22;
	out->data[10] = a02 * b20 + a12 * b21 + a22 * b22;
	out->data[11] = a03 * b20 + a13 * b21 + a23 * b22;

	if (a != out) {
		out->data[12] = a->data[12];
		out->data[13] = a->data[13];
		out->data[14] = a->data[14];
		out->data[15] = a->data[15];
	}

	return out;
}

NtmMat4 *ntm_mat4_rotateX(NtmMat4 *out, NtmMat4 *a, float rad) {
	float s = (float)sin(rad),
		c = (float)cos(rad),
		a10 = a->data[4],
		a11 = a->data[5],
		a12 = a->data[6],
		a13 = a->data[7],
		a20 = a->data[8],
		a21 = a->data[9],
		a22 = a->data[10],
		a23 = a->data[11];

	if (a != out) {
		out->data[0]  = a->data[0];
		out->data[1]  = a->data[1];
		out->data[2]  = a->data[2];
		out->data[3]  = a->data[3];
		out->data[12] = a->data[12];
		out->data[13] = a->data[13];
		out->data[14] = a->data[14];
		out->data[15] = a->data[15];
	}

	out->data[4] = a10 * c + a20 * s;
	out->data[5] = a11 * c + a21 * s;
	out->data[6] = a12 * c + a22 * s;
	out->data[7] = a13 * c + a23 * s;
	out->data[8] = a20 * c - a10 * s;
	out->data[9] = a21 * c - a11 * s;
	out->data[10] = a22 * c - a12 * s;
	out->data[11] = a23 * c - a13 * s;

	return out;
}

NtmMat4 *ntm_mat4_rotateY(NtmMat4 *out, NtmMat4 *a, float rad) {
	float s = (float)sin(rad),
		c = (float)cos(rad),
		a00 = a->data[0],
		a01 = a->data[1],
		a02 = a->data[2],
		a03 = a->data[3],
		a20 = a->data[8],
		a21 = a->data[9],
		a22 = a->data[10],
		a23 = a->data[11];

	if (a != out) {
		out->data[4]  = a->data[4];
		out->data[5]  = a->data[5];
		out->data[6]  = a->data[6];
		out->data[7]  = a->data[7];
		out->data[12] = a->data[12];
		out->data[13] = a->data[13];
		out->data[14] = a->data[14];
		out->data[15] = a->data[15];
	}

	out->data[0] = a00 * c - a20 * s;
	out->data[1] = a01 * c - a21 * s;
	out->data[2] = a02 * c - a22 * s;
	out->data[3] = a03 * c - a23 * s;
	out->data[8] = a00 * s + a20 * c;
	out->data[9] = a01 * s + a21 * c;
	out->data[10] = a02 * s + a22 * c;
	out->data[11] = a03 * s + a23 * c;

	return out;
}

NtmMat4 *ntm_mat4_rotateZ(NtmMat4 *out, NtmMat4 *a, float rad) {
	float s = (float)sin(rad),
		c = (float)cos(rad),
		a00 = a->data[0],
		a01 = a->data[1],
		a02 = a->data[2],
		a03 = a->data[3],
		a10 = a->data[4],
		a11 = a->data[5],
		a12 = a->data[6],
		a13 = a->data[7];

	if (a != out) {
		out->data[8]  = a->data[8];
		out->data[9]  = a->data[9];
		out->data[10] = a->data[10];
		out->data[11] = a->data[11];
		out->data[12] = a->data[12];
		out->data[13] = a->data[13];
		out->data[14] = a->data[14];
		out->data[15] = a->data[15];
	}

	out->data[0] = a00 * c + a10 * s;
	out->data[1] = a01 * c + a11 * s;
	out->data[2] = a02 * c + a12 * s;
	out->data[3] = a03 * c + a13 * s;
	out->data[4] = a10 * c - a00 * s;
	out->data[5] = a11 * c - a01 * s;
	out->data[6] = a12 * c - a02 * s;
	out->data[7] = a13 * c - a03 * s;

	return out;
}

NtmMat4 *ntm_mat4_fromTranslation(NtmMat4 *out, NtmVec3 *v) {
	out->data[0] = 1.0f;
	out->data[1] = 0.0f;
	out->data[2] = 0.0f;
	out->data[3] = 0.0f;
	out->data[4] = 0.0f;
	out->data[5] = 1.0f;
	out->data[6] = 0.0f;
	out->data[7] = 0.0f;
	out->data[8] = 0.0f;
	out->data[9] = 0.0f;
	out->data[10] = 1.0f;
	out->data[11] = 0.0f;
	out->data[12] = v->data[0];
	out->data[13] = v->data[1];
	out->data[14] = v->data[2];
	out->data[15] = 1.0f;
	return out;
}

NtmMat4 *ntm_mat4_fromScaling(NtmMat4 *out, NtmVec3 *v) {
	out->data[0] = v->data[0];
	out->data[1] = 0.0f;
	out->data[2] = 0.0f;
	out->data[3] = 0.0f;
	out->data[4] = 0.0f;
	out->data[5] = v->data[1];
	out->data[6] = 0.0f;
	out->data[7] = 0.0f;
	out->data[8] = 0.0f;
	out->data[9] = 0.0f;
	out->data[10] = v->data[2];
	out->data[11] = 0.0f;
	out->data[12] = 0.0f;
	out->data[13] = 0.0f;
	out->data[14] = 0.0f;
	out->data[15] = 1.0f;
	return out;
}

NtmMat4 *ntm_mat4_fromRotation(NtmMat4 *out, float rad, NtmVec3 *axis) {
	float x = axis->data[0], y = axis->data[1], z = axis->data[2];
	float invLen = 1.0f / (float)sqrt(x * x + y * y + z * z);
	float s, c, t;

	s = (float)sin(rad);
	c = (float)cos(rad);
	t = 1.0f - c;

	x *= invLen;
	y *= invLen;
	z *= invLen;

	out->data[0] = x * x * t + c;
	out->data[1] = y * x * t + z * s;
	out->data[2] = z * x * t - y * s;
	out->data[3] = 0.0f;
	out->data[4] = x * y * t - z * s;
	out->data[5] = y * y * t + c;
	out->data[6] = z * y * t + x * s;
	out->data[7] = 0.0f;
	out->data[8] = x * z * t + y * s;
	out->data[9] = y * z * t - x * s;
	out->data[10] = z * z * t + c;
	out->data[11] = 0.0f;
	out->data[12] = 0.0f;
	out->data[13] = 0.0f;
	out->data[14] = 0.0f;
	out->data[15] = 1.0f;

	return out;
}

NtmMat4 *ntm_mat4_fromXRotation(NtmMat4 *out, float rad) {
	float s = (float)sin(rad), c = (float)cos(rad);

	out->data[0]  = 1.0f;
	out->data[1]  = 0.0f;
	out->data[2]  = 0.0f;
	out->data[3]  = 0.0f;
	out->data[4] = 0.0f;
	out->data[5] = c;
	out->data[6] = s;
	out->data[7] = 0.0f;
	out->data[8] = 0.0f;
	out->data[9] = -s;
	out->data[10] = c;
	out->data[11] = 0.0f;
	out->data[12] = 0.0f;
	out->data[13] = 0.0f;
	out->data[14] = 0.0f;
	out->data[15] = 1.0f;
	return out;
}

NtmMat4 *ntm_mat4_fromYRotation(NtmMat4 *out, float rad) {
	float s = (float)sin(rad), c = (float)cos(rad);

	out->data[0]  = c;
	out->data[1]  = 0.0f;
	out->data[2]  = -s;
	out->data[3]  = 0.0f;
	out->data[4] = 0.0f;
	out->data[5] = 1.0f;
	out->data[6] = 0.0f;
	out->data[7] = 0.0f;
	out->data[8] = s;
	out->data[9] = 0.0f;
	out->data[10] = c;
	out->data[11] = 0.0f;
	out->data[12] = 0.0f;
	out->data[13] = 0.0f;
	out->data[14] = 0.0f;
	out->data[15] = 1.0f;
	return out;
}

NtmMat4 *ntm_mat4_fromZRotation(NtmMat4 *out, float rad) {
	float s = (float)sin(rad), c = (float)cos(rad);

	out->data[0]  = c;
	out->data[1]  = s;
	out->data[2]  = 0.0f;
	out->data[3]  = 0.0f;
	out->data[4] = -s;
	out->data[5] = c;
	out->data[6] = 0.0f;
	out->data[7] = 0.0f;
	out->data[8] = 0.0f;
	out->data[9] = 0.0f;
	out->data[10] = 1.0f;
	out->data[11] = 0.0f;
	out->data[12] = 0.0f;
	out->data[13] = 0.0f;
	out->data[14] = 0.0f;
	out->data[15] = 1.0f;
	return out;
}

NtmMat4 *ntm_mat4_fromRotationTranslation(NtmMat4 *out, NtmQuat *q, NtmVec3 *v) {
	float x = q->data[0], y = q->data[1], z = q->data[2], w = q->data[3],
		x2 = x + x,
		y2 = y + y,
		z2 = z + z,

		xx = x * x2,
		xy = x * y2,
		xz = x * z2,
		yy = y * y2,
		yz = y * z2,
		zz = z * z2,
		wx = w * x2,
		wy = w * y2,
		wz = w * z2;

	out->data[0] = 1.0f - (yy + zz);
	out->data[1] = xy + wz;
	out->data[2] = xz - wy;
	out->data[3] = 0.0f;
	out->data[4] = xy - wz;
	out->data[5] = 1.0f - (xx + zz);
	out->data[6] = yz + wx;
	out->data[7] = 0.0f;
	out->data[8] = xz + wy;
	out->data[9] = yz - wx;
	out->data[10] = 1.0f - (xx + yy);
	out->data[11] = 0.0f;
	out->data[12] = v->data[0];
	out->data[13] = v->data[1];
	out->data[14] = v->data[2];
	out->data[15] = 1.0f;

	return out;
}

NtmMat4 *ntm_mat4_fromQuat(NtmMat4 *out, NtmQuat *q) {
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
	out->data[1] = yx + wz;
	out->data[2] = zx - wy;
	out->data[3] = 0.0f;

	out->data[4] = yx - wz;
	out->data[5] = 1.0f - xx - zz;
	out->data[6] = zy + wx;
	out->data[7] = 0.0f;

	out->data[8] = zx + wy;
	out->data[9] = zy - wx;
	out->data[10] = 1.0f - xx - yy;
	out->data[11] = 0.0f;

	out->data[12] = 0.0f;
	out->data[13] = 0.0f;
	out->data[14] = 0.0f;
	out->data[15] = 1.0f;

	return out;
}

NtmMat4 *ntm_mat4_fromMat3(NtmMat4 *out, NtmMat3 *a) {
	out->data[0] = a->data[0];
	out->data[1] = a->data[1];
	out->data[2] = a->data[2];
	out->data[3] = 0.0f;
	
	out->data[4] = a->data[3];
	out->data[5] = a->data[4];
	out->data[6] = a->data[5];
	out->data[7] = 0.0f;
	
	out->data[8] = a->data[6];
	out->data[9] = a->data[7];
	out->data[10] = a->data[8];
	out->data[11] = 0.0f;
	
	out->data[12] = 0.0f;
	out->data[13] = 0.0f;
	out->data[14] = 0.0f;
	out->data[15] = 1.0f;
	return out;
}

NtmMat4 *ntm_mat4_frustum(
	NtmMat4 *out,
	float left,
	float right,
	float bottom,
	float top,
	float near,
	float far
) {
	float rl = 1.0f / (right - left),
		tb = 1.0f / (top - bottom),
		nf = 1.0f / (near - far);
	out->data[0] = (near * 2.0f) * rl;
	out->data[1] = 0.0f;
	out->data[2] = 0.0f;
	out->data[3] = 0.0f;
	out->data[4] = 0.0f;
	out->data[5] = (near * 2.0f) * tb;
	out->data[6] = 0.0f;
	out->data[7] = 0.0f;
	out->data[8] = (right + left) * rl;
	out->data[9] = (top + bottom) * tb;
	out->data[10] = (far + near) * nf;
	out->data[11] = -1.0f;
	out->data[12] = 0.0f;
	out->data[13] = 0.0f;
	out->data[14] = (far * near * 2.0f) * nf;
	out->data[15] = 0.0f;
	return out;
}

NtmMat4 *ntm_mat4_perspective(
	NtmMat4 *out,
	float fovy,
	float aspect,
	float near,
	float far
) {
	float f = 1.0f / (float)tan(fovy / 2.0f), nf = 1.0f / (near - far);
	out->data[0] = f / aspect;
	out->data[1] = 0.0f;
	out->data[2] = 0.0f;
	out->data[3] = 0.0f;
	out->data[4] = 0.0f;
	out->data[5] = f;
	out->data[6] = 0.0f;
	out->data[7] = 0.0f;
	out->data[8] = 0.0f;
	out->data[9] = 0.0f;
	out->data[10] = (far + near) * nf;
	out->data[11] = -1.0f;
	out->data[12] = 0.0f;
	out->data[13] = 0.0f;
	out->data[14] = (2 * far * near) * nf;
	out->data[15] = 0.0f;
	return out;
}

NtmMat4 *ntm_mat4_ortho(
	NtmMat4 *out,
	float left,
	float right,
	float bottom,
	float top,
	float near,
	float far
) {
	float lr = 1.0f / (left - right),
		bt = 1.0f / (bottom - top),
		nf = 1.0f / (near - far);
	out->data[0] = -2.0f * lr;
	out->data[1] = 0.0f;
	out->data[2] = 0.0f;
	out->data[3] = 0.0f;
	out->data[4] = 0.0f;
	out->data[5] = -2.0f * bt;
	out->data[6] = 0.0f;
	out->data[7] = 0.0f;
	out->data[8] = 0.0f;
	out->data[9] = 0.0f;
	out->data[10] = 2.0f * nf;
	out->data[11] = 0.0f;
	out->data[12] = (left + right) * lr;
	out->data[13] = (top + bottom) * bt;
	out->data[14] = (far + near) * nf;
	out->data[15] = 1.0f;
	return out;
}

NtmMat4 *ntm_mat4_lookAt(NtmMat4 *out, NtmVec3 *eye, NtmVec3 *center, NtmVec3 *up) {
	float x0, x1, x2, y0, y1, y2, z0, z1, z2, len,
		eyex = eye->data[0],
		eyey = eye->data[1],
		eyez = eye->data[2],
		upx = up->data[0],
		upy = up->data[1],
		upz = up->data[2],
		centerx = center->data[0],
		centery = center->data[1],
		centerz = center->data[2];

	if (
		fabs(eyex - centerx) < NTM_EPSILON
		&& fabs(eyey - centery) < NTM_EPSILON
		&& fabs(eyez - centerz) < NTM_EPSILON
	) {
		ntm_mat4_identity(out);
		return out;
	}

	z0 = eyex - centerx;
	z1 = eyey - centery;
	z2 = eyez - centerz;

	len = 1.0f / (float)sqrt(z0 * z0 + z1 * z1 + z2 * z2);
	z0 *= len;
	z1 *= len;
	z2 *= len;

	x0 = upy * z2 - upz * z1;
	x1 = upz * z0 - upx * z2;
	x2 = upx * z1 - upy * z0;
	len = (float)sqrt(x0 * x0 + x1 * x1 + x2 * x2);
	if (fabs(len) < NTM_EPSILON) {
		x0 = 0.0f;
		x1 = 0.0f;
		x2 = 0.0f;
	} else {
		len = 1.0f / len;
		x0 *= len;
		x1 *= len;
		x2 *= len;
	}

	y0 = z1 * x2 - z2 * x1;
	y1 = z2 * x0 - z0 * x2;
	y2 = z0 * x1 - z1 * x0;

	len = (float)sqrt(y0 * y0 + y1 * y1 + y2 * y2);
	if (fabs(len) < NTM_EPSILON) {
		y0 = 0.0f;
		y1 = 0.0f;
		y2 = 0.0f;
	} else {
		len = 1.0f / len;
		y0 *= len;
		y1 *= len;
		y2 *= len;
	}

	out->data[0] = x0;
	out->data[1] = y0;
	out->data[2] = z0;
	out->data[3] = 0.0f;
	out->data[4] = x1;
	out->data[5] = y1;
	out->data[6] = z1;
	out->data[7] = 0.0f;
	out->data[8] = x2;
	out->data[9] = y2;
	out->data[10] = z2;
	out->data[11] = 0.0f;
	out->data[12] = -(x0 * eyex + x1 * eyey + x2 * eyez);
	out->data[13] = -(y0 * eyex + y1 * eyey + y2 * eyez);
	out->data[14] = -(z0 * eyex + z1 * eyey + z2 * eyez);
	out->data[15] = 1.0f;

	return out;
}

float ntm_mat4_frob(NtmMat4 *a) {
	float a0 = a->data[0], a1 = a->data[1], a2 = a->data[2], a3 = a->data[3],
			a4 = a->data[4], a5 = a->data[5], a6 = a->data[6], a7 = a->data[7],
			a8 = a->data[8], a9 = a->data[9], a10 = a->data[10], a11 = a->data[11],
			a12 = a->data[12], a13 = a->data[13], a14 = a->data[14], a15 = a->data[15];
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
		+ a9*a9
		+ a10*a10
		+ a11*a11
		+ a12*a12
		+ a13*a13
		+ a14*a14
		+ a15*a15
	));
}
