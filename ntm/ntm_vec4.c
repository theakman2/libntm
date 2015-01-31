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

#include "ntm_vec4.h"

#include <stdlib.h>
#include <math.h>

#include "ntm_common.h"

NtmVec4 *ntm_vec4_copy(NtmVec4 *out, NtmVec4 *a) {
	out->data[0] = a->data[0];
	out->data[1] = a->data[1];
	out->data[2] = a->data[2];
	out->data[3] = a->data[3];
	return out;
}

NtmVec4 *ntm_vec4_set(NtmVec4 *out, float x, float y, float z, float w) {
	out->data[0] = x;
	out->data[1] = y;
	out->data[2] = z;
	out->data[3] = w;
	return out;
}

NtmVec4 *ntm_vec4_add(NtmVec4 *out, NtmVec4 *a, NtmVec4 *b) {
	out->data[0] = a->data[0] + b->data[0];
	out->data[1] = a->data[1] + b->data[1];
	out->data[2] = a->data[2] + b->data[2];
	out->data[3] = a->data[3] + b->data[3];
	return out;
}

NtmVec4 *ntm_vec4_subtract(NtmVec4 *out, NtmVec4 *a, NtmVec4 *b) {
	out->data[0] = a->data[0] - b->data[0];
	out->data[1] = a->data[1] - b->data[1];
	out->data[2] = a->data[2] - b->data[2];
	out->data[3] = a->data[3] - b->data[3];
	return out;
}

NtmVec4 *ntm_vec4_multiply(NtmVec4 *out, NtmVec4 *a, NtmVec4 *b) {
	out->data[0] = a->data[0] * b->data[0];
	out->data[1] = a->data[1] * b->data[1];
	out->data[2] = a->data[2] * b->data[2];
	out->data[3] = a->data[3] * b->data[3];
	return out;
}

NtmVec4 *ntm_vec4_divide(NtmVec4 *out, NtmVec4 *a, NtmVec4 *b) {
	out->data[0] = a->data[0] / b->data[0];
	out->data[1] = a->data[1] / b->data[1];
	out->data[2] = a->data[2] / b->data[2];
	out->data[3] = a->data[3] / b->data[3];
	return out;
}

NtmVec4 *ntm_vec4_min(NtmVec4 *out, NtmVec4 *a, NtmVec4 *b) {
	float a0 = a->data[0], a1 = a->data[1], a2 = a->data[2], a3 = a->data[3];
	float b0 = b->data[0], b1 = b->data[1], b2 = b->data[2], b3 = b->data[3];
	out->data[0] = a0 > b0 ? b0 : a0;
	out->data[1] = a1 > b1 ? b1 : a1;
	out->data[2] = a2 > b2 ? b2 : a2;
	out->data[3] = a3 > b3 ? b3 : a3;
	return out;
}

NtmVec4 *ntm_vec4_max(NtmVec4 *out, NtmVec4 *a, NtmVec4 *b) {
	float a0 = a->data[0], a1 = a->data[1], a2 = a->data[2], a3 = a->data[3];
	float b0 = b->data[0], b1 = b->data[1], b2 = b->data[2], b3 = b->data[3];
	out->data[0] = a0 < b0 ? b0 : a0;
	out->data[1] = a1 < b1 ? b1 : a1;
	out->data[2] = a2 < b2 ? b2 : a2;
	out->data[3] = a3 < b3 ? b3 : a3;
	return out;
}

NtmVec4 *ntm_vec4_scale(NtmVec4 *out, NtmVec4 *a, float b) {
	out->data[0] = a->data[0] * b;
	out->data[1] = a->data[1] * b;
	out->data[2] = a->data[2] * b;
	out->data[3] = a->data[3] * b;
	return out;
}

NtmVec4 *ntm_vec4_scaleAndAdd(NtmVec4 *out, NtmVec4 *a, NtmVec4 *b, float scale) {
	out->data[0] = a->data[0] + (b->data[0] * scale);
	out->data[1] = a->data[1] + (b->data[1] * scale);
	out->data[2] = a->data[2] + (b->data[2] * scale);
	out->data[3] = a->data[3] + (b->data[3] * scale);
	return out;
}

float ntm_vec4_distance(NtmVec4 *a, NtmVec4 *b) {
	float x = b->data[0] - a->data[0],
		y = b->data[1] - a->data[1],
		z = b->data[2] - a->data[2],
		w = b->data[3] - a->data[3];
	return (float)sqrt(x*x + y*y + z*z + w*w);
}

float ntm_vec4_squaredDistance(NtmVec4 *a, NtmVec4 *b) {
	float x = b->data[0] - a->data[0],
		y = b->data[1] - a->data[1],
		z = b->data[2] - a->data[2],
		w = b->data[3] - a->data[3];
	return x*x + y*y + z*z + w*w;
}

float ntm_vec4_length(NtmVec4 *a) {
	float x = a->data[0],
		y = a->data[1],
		z = a->data[2],
		w = a->data[3];
	return (float)sqrt(x*x + y*y + z*z + w*w);
}

float ntm_vec4_squaredLength(NtmVec4 *a) {
	float x = a->data[0],
		y = a->data[1],
		z = a->data[2],
		w = a->data[3];
	return x*x + y*y + z*z + w*w;
}

NtmVec4 *ntm_vec4_negate(NtmVec4 *out, NtmVec4 *a) {
	out->data[0] = -a->data[0];
	out->data[1] = -a->data[1];
	out->data[2] = -a->data[2];
	out->data[3] = -a->data[3];
	return out;
}

NtmVec4 *ntm_vec4_inverse(NtmVec4 *out, NtmVec4 *a) {
	if (
		(fabs(a->data[0]) < NTM_EPSILON)
		|| (fabs(a->data[1]) < NTM_EPSILON)
		|| (fabs(a->data[2]) < NTM_EPSILON)
		|| (fabs(a->data[3]) < NTM_EPSILON)
	) {
		return NULL;
	}
	out->data[0] = 1.0f / a->data[0];
	out->data[1] = 1.0f / a->data[1];
	out->data[2] = 1.0f / a->data[2];
	out->data[3] = 1.0f / a->data[3];
	return out;
}

NtmVec4 *ntm_vec4_normalize(NtmVec4 *out, NtmVec4 *a) {
	float x = a->data[0],
		y = a->data[1],
		z = a->data[2],
		w = a->data[3];
	float len = (float)sqrt(x*x + y*y + z*z + w*w);
	if (len < NTM_EPSILON) {
		return NULL;
	}
	len = 1.0f / len;
	out->data[0] = a->data[0] * len;
	out->data[1] = a->data[1] * len;
	out->data[2] = a->data[2] * len;
	out->data[3] = a->data[3] * len;
	return out;
}

float ntm_vec4_dot(NtmVec4 *a, NtmVec4 *b) {
	return	a->data[0] * b->data[0]
			+ a->data[1] * b->data[1]
			+ a->data[2] * b->data[2]
			+ a->data[3] * b->data[3];
}

NtmVec4 *ntm_vec4_lerp(NtmVec4 *out, NtmVec4 *a, NtmVec4 *b, float t) {
	float ax = a->data[0],
		ay = a->data[1],
		az = a->data[2],
		aw = a->data[3];
	out->data[0] = ax + t * (b->data[0] - ax);
	out->data[1] = ay + t * (b->data[1] - ay);
	out->data[2] = az + t * (b->data[2] - az);
	out->data[3] = aw + t * (b->data[3] - aw);
	return out;
}

NtmVec4 *ntm_vec4_random(NtmVec4 *out) {
	out->data[0] = ((float)rand() / (float)RAND_MAX) - 0.5f;
	out->data[1] = ((float)rand() / (float)RAND_MAX) - 0.5f;
	out->data[2] = ((float)rand() / (float)RAND_MAX) - 0.5f;
	out->data[3] = ((float)rand() / (float)RAND_MAX) - 0.5f;
	return out;
}

NtmVec4 *ntm_vec4_transformMat4(NtmVec4 *out, NtmVec4 *a, NtmMat4 *m) {
	float x = a->data[0], y = a->data[1], z = a->data[2], w = a->data[3];
	out->data[0] = m->data[0] * x + m->data[4] * y + m->data[8] * z + m->data[12] * w;
	out->data[1] = m->data[1] * x + m->data[5] * y + m->data[9] * z + m->data[13] * w;
	out->data[2] = m->data[2] * x + m->data[6] * y + m->data[10] * z + m->data[14] * w;
	out->data[3] = m->data[3] * x + m->data[7] * y + m->data[11] * z + m->data[15] * w;
	return out;
}

NtmVec4 *ntm_vec4_transformQuat(NtmVec4 *out, NtmVec4 *a, NtmQuat *q) {
	float x = a->data[0], y = a->data[1], z = a->data[2],
		qx = q->data[0], qy = q->data[1], qz = q->data[2], qw = q->data[3],

		ix = qw * x + qy * z - qz * y,
		iy = qw * y + qz * x - qx * z,
		iz = qw * z + qx * y - qy * x,
		iw = -qx * x - qy * y - qz * z;

	out->data[0] = ix * qw + iw * -qx + iy * -qz - iz * -qy;
	out->data[1] = iy * qw + iw * -qy + iz * -qx - ix * -qz;
	out->data[2] = iz * qw + iw * -qz + ix * -qy - iy * -qx;
	out->data[3] = a->data[3];
	return out;
}
