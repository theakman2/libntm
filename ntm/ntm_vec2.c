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

#include "ntm_common.h"
#include "ntm_vec2.h"

#include <stdlib.h>
#include <math.h>

NtmVec2 *ntm_vec2_copy(NtmVec2 *out, NtmVec2 *a) {
	out->data[0] = a->data[0];
	out->data[1] = a->data[1];
	return out;
}

NtmVec2 *ntm_vec2_set(NtmVec2 *out, float x, float y) {
	out->data[0] = x;
	out->data[1] = y;
	return out;
}

NtmVec2 *ntm_vec2_add(NtmVec2 *out, NtmVec2 *a, NtmVec2 *b) {
	out->data[0] = a->data[0] + b->data[0];
	out->data[1] = a->data[1] + b->data[1];
	return out;
}

NtmVec2 *ntm_vec2_subtract(NtmVec2 *out, NtmVec2 *a, NtmVec2 *b) {
	out->data[0] = a->data[0] - b->data[0];
	out->data[1] = a->data[1] - b->data[1];
	return out;
}

NtmVec2 *ntm_vec2_multiply(NtmVec2 *out, NtmVec2 *a, NtmVec2 *b) {
	out->data[0] = a->data[0] * b->data[0];
	out->data[1] = a->data[1] * b->data[1];
	return out;
}

NtmVec2 *ntm_vec2_divide(NtmVec2 *out, NtmVec2 *a, NtmVec2 *b) {
	out->data[0] = a->data[0] / b->data[0];
	out->data[1] = a->data[1] / b->data[1];
	return out;
}

NtmVec2 *ntm_vec2_min(NtmVec2 *out, NtmVec2 *a, NtmVec2 *b) {
	float a0 = a->data[0], a1 = a->data[1];
	float b0 = b->data[0], b1 = b->data[1];
	out->data[0] = a0 > b0 ? b0 : a0;
	out->data[1] = a1 > b1 ? b1 : a1;
	return out;
}

NtmVec2 *ntm_vec2_max(NtmVec2 *out, NtmVec2 *a, NtmVec2 *b) {
	float a0 = a->data[0], a1 = a->data[1];
	float b0 = b->data[0], b1 = b->data[1];
	out->data[0] = a0 < b0 ? b0 : a0;
	out->data[1] = a1 < b1 ? b1 : a1;
	return out;
}

NtmVec2 *ntm_vec2_scale(NtmVec2 *out, NtmVec2 *a, float b) {
	out->data[0] = a->data[0] * b;
	out->data[1] = a->data[1] * b;
	return out;
}

NtmVec2 *ntm_vec2_scaleAndAdd(NtmVec2 *out, NtmVec2 *a, NtmVec2 *b, float scale) {
	out->data[0] = a->data[0] + (b->data[0] * scale);
	out->data[1] = a->data[1] + (b->data[1] * scale);
	return out;
}

float ntm_vec2_distance(NtmVec2 *a, NtmVec2 *b) {
	float x = b->data[0] - a->data[0],
		y = b->data[1] - a->data[1];
	return (float)sqrt(x*x + y*y);
}

float ntm_vec2_squaredDistance(NtmVec2 *a, NtmVec2 *b) {
	float x = b->data[0] - a->data[0],
		y = b->data[1] - a->data[1];
	return x*x + y*y;
}

float ntm_vec2_length(NtmVec2 *a) {
	float x = a->data[0],
		y = a->data[1];
	return (float)sqrt(x*x + y*y);
}

float ntm_vec2_squaredLength(NtmVec2 *a) {
	float x = a->data[0],
		y = a->data[1];
	return x*x + y*y;
}

NtmVec2 *ntm_vec2_negate(NtmVec2 *out, NtmVec2 *a) {
	out->data[0] = -a->data[0];
	out->data[1] = -a->data[1];
	return out;
}

NtmVec2 *ntm_vec2_inverse(NtmVec2 *out, NtmVec2 *a) {
	out->data[0] = 1.0f / a->data[0];
	out->data[1] = 1.0f / a->data[1];
	return out;
}

NtmVec2 *ntm_vec2_normalize(NtmVec2 *out, NtmVec2 *a) {
	float x = a->data[0], y = a->data[1];
	float invLen = 1.0f / (float)sqrt(x*x + y*y);
	out->data[0] = a->data[0] * invLen;
	out->data[1] = a->data[1] * invLen;
	return out;
}

float ntm_vec2_dot(NtmVec2 *a, NtmVec2 *b) {
	return a->data[0] * b->data[0] + a->data[1] * b->data[1];
}

NtmVec3 *ntm_vec2_cross(NtmVec3 *out, NtmVec2 *a, NtmVec2 *b) {
	float z = a->data[0] * b->data[1] - a->data[1] * b->data[0];
	out->data[0] = out->data[1] = 0.0f;
	out->data[2] = z;
	return out;
}

NtmVec2 *ntm_vec2_lerp(NtmVec2 *out, NtmVec2 *a, NtmVec2 *b, float t) {
	float ax = a->data[0],
		ay = a->data[1];
	out->data[0] = ax + t * (b->data[0] - ax);
	out->data[1] = ay + t * (b->data[1] - ay);
	return out;
}

NtmVec2 *ntm_vec2_random(NtmVec2 *out) {
	out->data[0] = ((float)rand() / (float)RAND_MAX) - 0.5f;
	out->data[1] = ((float)rand() / (float)RAND_MAX) - 0.5f;
	return out;
}

NtmVec2 *ntm_vec2_transformMat2(NtmVec2 *out, NtmVec2 *a, NtmMat2 *m) {
	float x = a->data[0],
		y = a->data[1];
	out->data[0] = m->data[0] * x + m->data[2] * y;
	out->data[1] = m->data[1] * x + m->data[3] * y;
	return out;
}

NtmVec2 *ntm_vec2_transformMat2d(NtmVec2 *out, NtmVec2 *a, NtmMat2d *m) {
	float x = a->data[0],
		y = a->data[1];
	out->data[0] = m->data[0] * x + m->data[2] * y + m->data[4];
	out->data[1] = m->data[1] * x + m->data[3] * y + m->data[5];
	return out;
}

NtmVec2 *ntm_vec2_transformMat3(NtmVec2 *out, NtmVec2 *a, NtmMat3 *m) {
	float x = a->data[0],
		y = a->data[1];
	out->data[0] = m->data[0] * x + m->data[3] * y + m->data[6];
	out->data[1] = m->data[1] * x + m->data[4] * y + m->data[7];
	return out;
}

NtmVec2 *ntm_vec2_transformMat4(NtmVec2 *out, NtmVec2 *a, NtmMat4 *m) {
	float x = a->data[0],
		y = a->data[1];
	out->data[0] = m->data[0] * x + m->data[4] * y + m->data[12];
	out->data[1] = m->data[1] * x + m->data[5] * y + m->data[13];
	return out;
}
