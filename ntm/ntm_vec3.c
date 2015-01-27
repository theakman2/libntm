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

#include "ntm_vec3.h"

#include <stdlib.h>
#include <math.h>

#include "ntm_common.h"

NtmVec3 *ntm_vec3_copy(NtmVec3 *out, NtmVec3 *a) {
	out->data[0] = a->data[0];
	out->data[1] = a->data[1];
	out->data[2] = a->data[2];
	return out;
}

NtmVec3 *ntm_vec3_set(NtmVec3 *out, float x, float y, float z) {
	out->data[0] = x;
	out->data[1] = y;
	out->data[2] = z;
	return out;
}

NtmVec3 *ntm_vec3_add(NtmVec3 *out, NtmVec3 *a, NtmVec3 *b) {
	out->data[0] = a->data[0] + b->data[0];
	out->data[1] = a->data[1] + b->data[1];
	out->data[2] = a->data[2] + b->data[2];
	return out;
}

NtmVec3 *ntm_vec3_subtract(NtmVec3 *out, NtmVec3 *a, NtmVec3 *b) {
	out->data[0] = a->data[0] - b->data[0];
	out->data[1] = a->data[1] - b->data[1];
	out->data[2] = a->data[2] - b->data[2];
	return out;
}

NtmVec3 *ntm_vec3_multiply(NtmVec3 *out, NtmVec3 *a, NtmVec3 *b) {
	out->data[0] = a->data[0] * b->data[0];
	out->data[1] = a->data[1] * b->data[1];
	out->data[2] = a->data[2] * b->data[2];
	return out;
}

NtmVec3 *ntm_vec3_divide(NtmVec3 *out, NtmVec3 *a, NtmVec3 *b) {
	out->data[0] = a->data[0] / b->data[0];
	out->data[1] = a->data[1] / b->data[1];
	out->data[2] = a->data[2] / b->data[2];
	return out;
}

NtmVec3 *ntm_vec3_min(NtmVec3 *out, NtmVec3 *a, NtmVec3 *b) {
	float a0 = a->data[0], a1 = a->data[1], a2 = a->data[2];
	float b0 = b->data[0], b1 = b->data[1], b2 = b->data[2];
	out->data[0] = a0 > b0 ? b0 : a0;
	out->data[1] = a1 > b1 ? b1 : a1;
	out->data[2] = a2 > b2 ? b2 : a2;
	return out;
}

NtmVec3 *ntm_vec3_max(NtmVec3 *out, NtmVec3 *a, NtmVec3 *b) {
	float a0 = a->data[0], a1 = a->data[1], a2 = a->data[2];
	float b0 = b->data[0], b1 = b->data[1], b2 = b->data[2];
	out->data[0] = a0 < b0 ? b0 : a0;
	out->data[1] = a1 < b1 ? b1 : a1;
	out->data[2] = a2 < b2 ? b2 : a2;
	return out;
}

NtmVec3 *ntm_vec3_scale(NtmVec3 *out, NtmVec3 *a, float b) {
	out->data[0] = a->data[0] * b;
	out->data[1] = a->data[1] * b;
	out->data[2] = a->data[2] * b;
	return out;
}

NtmVec3 *ntm_vec3_scaleAndAdd(NtmVec3 *out, NtmVec3 *a, NtmVec3 *b, float scale) {
	out->data[0] = a->data[0] + (b->data[0] * scale);
	out->data[1] = a->data[1] + (b->data[1] * scale);
	out->data[2] = a->data[2] + (b->data[2] * scale);
	return out;
}

float ntm_vec3_distance(NtmVec3 *a, NtmVec3 *b) {
	float x = b->data[0] - a->data[0],
		y = b->data[1] - a->data[1],
		z = b->data[2] - a->data[2];
	return (float)sqrt(x*x + y*y + z*z);
}

float ntm_vec3_squaredDistance(NtmVec3 *a, NtmVec3 *b) {
	float x = b->data[0] - a->data[0],
		y = b->data[1] - a->data[1],
		z = b->data[2] - a->data[2];
	return x*x + y*y + z*z;
}

float ntm_vec3_length(NtmVec3 *a) {
	float x = a->data[0],
		y = a->data[1],
		z = a->data[2];
	return (float)sqrt(x*x + y*y + z*z);
}

float ntm_vec3_squaredLength(NtmVec3 *a) {
	float x = a->data[0],
		y = a->data[1],
		z = a->data[2];
	return x*x + y*y + z*z;
}

NtmVec3 *ntm_vec3_negate(NtmVec3 *out, NtmVec3 *a) {
	out->data[0] = -a->data[0];
	out->data[1] = -a->data[1];
	out->data[2] = -a->data[2];
	return out;
}

NtmVec3 *ntm_vec3_inverse(NtmVec3 *out, NtmVec3 *a) {
	out->data[0] = 1.0f / a->data[0];
	out->data[1] = 1.0f / a->data[1];
	out->data[2] = 1.0f / a->data[2];
	return out;
}

NtmVec3 *ntm_vec3_normalize(NtmVec3 *out, NtmVec3 *a) {
	float x = a->data[0],
		y = a->data[1],
		z = a->data[2];
	float invLen = 1.0f / (float)sqrt(x*x + y*y + z*z);
	out->data[0] = a->data[0] * invLen;
	out->data[1] = a->data[1] * invLen;
	out->data[2] = a->data[2] * invLen;
	return out;
}

float ntm_vec3_dot(NtmVec3 *a, NtmVec3 *b) {
	return	a->data[0] * b->data[0]
			+ a->data[1] * b->data[1]
			+ a->data[2] * b->data[2];
}

NtmVec3 *ntm_vec3_cross(NtmVec3 *out, NtmVec3 *a, NtmVec3 *b) {
	float ax = a->data[0], ay = a->data[1], az = a->data[2],
		bx = b->data[0], by = b->data[1], bz = b->data[2];

	out->data[0] = ay * bz - az * by;
	out->data[1] = az * bx - ax * bz;
	out->data[2] = ax * by - ay * bx;

	return out;
}

NtmVec3 *ntm_vec3_lerp(NtmVec3 *out, NtmVec3 *a, NtmVec3 *b, float t) {
	float ax = a->data[0],
		ay = a->data[1],
		az = a->data[2];
	out->data[0] = ax + t * (b->data[0] - ax);
	out->data[1] = ay + t * (b->data[1] - ay);
	out->data[2] = az + t * (b->data[2] - az);
	return out;
}

NtmVec3 *ntm_vec3_random(NtmVec3 *out) {
	out->data[0] = ((float)rand() / (float)RAND_MAX) - 0.5f;
	out->data[1] = ((float)rand() / (float)RAND_MAX) - 0.5f;
	out->data[2] = ((float)rand() / (float)RAND_MAX) - 0.5f;
	return out;
}

NtmVec3 *ntm_vec3_transformMat4(NtmVec3 *out, NtmVec3 *a, NtmMat4 *m) {
	float x = a->data[0], y = a->data[1], z = a->data[2];
	out->data[0] = m->data[0] * x + m->data[4] * y + m->data[8] * z;
	out->data[1] = m->data[1] * x + m->data[5] * y + m->data[9] * z;
	out->data[2] = m->data[2] * x + m->data[6] * y + m->data[10] * z;
	return out;
}

NtmVec3 *ntm_vec3_transformMat3(NtmVec3 *out, NtmVec3 *a, NtmMat3 *m) {
	float x = a->data[0], y = a->data[1], z = a->data[2];
	out->data[0] = x * m->data[0] + y * m->data[3] + z * m->data[6];
	out->data[1] = x * m->data[1] + y * m->data[4] + z * m->data[7];
	out->data[2] = x * m->data[2] + y * m->data[5] + z * m->data[8];
	return out;
}

NtmVec3 *ntm_vec3_transformQuat(NtmVec3 *out, NtmVec3 *a, NtmQuat *q) {
	float x = a->data[0], y = a->data[1], z = a->data[2],
		qx = q->data[0], qy = q->data[1], qz = q->data[2], qw = q->data[3],

		ix = qw * x + qy * z - qz * y,
		iy = qw * y + qz * x - qx * z,
		iz = qw * z + qx * y - qy * x,
		iw = -qx * x - qy * y - qz * z;

	out->data[0] = ix * qw + iw * -qx + iy * -qz - iz * -qy;
	out->data[1] = iy * qw + iw * -qy + iz * -qx - ix * -qz;
	out->data[2] = iz * qw + iw * -qz + ix * -qy - iy * -qx;

	return out;
}

NtmVec3 *ntm_vec3_rotateX(NtmVec3 *out, NtmVec3 *a, float c) {
	float a1 = a->data[1];
	float a2 = a->data[2];

	out->data[0] = a->data[0];
	out->data[1] = a1*(float)cos(c) - a2*(float)sin(c);
	out->data[2] = a1*(float)sin(c) + a2*(float)cos(c);

	return out;
}

NtmVec3 *ntm_vec3_rotateY(NtmVec3 *out, NtmVec3 *a, float c) {
	float a0 = a->data[0];
	float a2 = a->data[2];

	out->data[0] = a2*(float)sin(c) + a0*(float)cos(c);
	out->data[1] = a->data[1];
	out->data[2] = a2*(float)cos(c) - a0*(float)sin(c);

	return out;
}

NtmVec3 *ntm_vec3_rotateZ(NtmVec3 *out, NtmVec3 *a, float c) {
	float a0 = a->data[0];
	float a1 = a->data[1];

	out->data[0] = a0*(float)cos(c) - a1*(float)sin(c);
	out->data[1] = a0*(float)sin(c) + a1*(float)cos(c);
	out->data[2] = a->data[2];

	return out;
}
