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

#include "ntm_quat.h"

#include <stdlib.h>
#include <math.h>

#include "ntm_mat3.h"
#include "ntm_common.h"
#include "ntm_vec3.h"

NtmQuat *ntm_quat_identity(NtmQuat *out) {
	out->data[0] = 0.0f;
	out->data[1] = 0.0f;
	out->data[2] = 0.0f;
	out->data[3] = 1.0f;
	return out;
}

NtmQuat *ntm_quat_copy(NtmQuat *out, NtmQuat *a) {
	out->data[0] = a->data[0];
	out->data[1] = a->data[1];
	out->data[2] = a->data[2];
	out->data[3] = a->data[3];
	return out;
}

NtmQuat *ntm_quat_set(NtmQuat *out, float x, float y, float z, float w) {
	out->data[0] = x;
	out->data[1] = y;
	out->data[2] = z;
	out->data[3] = w;
	return out;
}

NtmQuat *ntm_quat_rotationTo(NtmQuat *out, NtmVec3 *a, NtmVec3 *b) {
	NtmVec3 tmpvec3, xUnitVec3, yUnitVec3;
	float dot = ntm_vec3_dot(a, b);
	ntm_vec3_set(&xUnitVec3, 1.0f, 0.0f, 0.0f);
	ntm_vec3_set(&yUnitVec3, 0.0f, 1.0f ,0.0f);
	if (dot < -0.999999f) {
		ntm_vec3_cross(&tmpvec3, &xUnitVec3, a);
		if (ntm_vec3_length(&tmpvec3) < NTM_EPSILON) {
			ntm_vec3_cross(&tmpvec3, &yUnitVec3, a);
		}
		ntm_vec3_normalize(&tmpvec3, &tmpvec3);
		ntm_quat_setAxisAngle(out, &tmpvec3, NTM_PI);
	} else if (dot > 0.999999f) {
		out->data[0] = 0.0f;
		out->data[1] = 0.0f;
		out->data[2] = 0.0f;
		out->data[3] = 1.0f;
	} else {
		ntm_vec3_cross(&tmpvec3, a, b);
		out->data[0] = tmpvec3.data[0];
		out->data[1] = tmpvec3.data[1];
		out->data[2] = tmpvec3.data[2];
		out->data[3] = 1.0f + dot;
		ntm_quat_normalize(out, out);
	}
	return out;
}

NtmQuat *ntm_quat_setAxes(NtmQuat *out, NtmVec3 *view, NtmVec3 *right, NtmVec3 *up) {
	NtmMat3 matr;
	NtmQuat q;
	matr.data[0] = right->data[0];
	matr.data[3] = right->data[1];
	matr.data[6] = right->data[2];

	matr.data[1] = up->data[0];
	matr.data[4] = up->data[1];
	matr.data[7] = up->data[2];

	matr.data[2] = -view->data[0];
	matr.data[5] = -view->data[1];
	matr.data[8] = -view->data[2];

	ntm_quat_fromMat3(&q,&matr);
	ntm_quat_normalize(out, &q);

	return out;
}

NtmQuat *ntm_quat_setAxisAngle(NtmQuat *out, NtmVec3 *axis, float rad) {
	return ntm_quat_setAxisAngleF(
		out,
		axis->data[0],
		axis->data[1],
		axis->data[2],
		rad
	);
}

NtmQuat *ntm_quat_setAxisAngleF(NtmQuat *out, float x, float y, float z, float rad) {
	float s;
	rad *= 0.5f;
	s = (float)sin(rad);
	out->data[0] = s * x;
	out->data[1] = s * y;
	out->data[2] = s * z;
	out->data[3] = (float)cos(rad);
	return out;
}

NtmQuat *ntm_quat_add(NtmQuat *out, NtmQuat *a, NtmQuat *b) {
	out->data[0] = a->data[0] + b->data[0];
	out->data[1] = a->data[1] + b->data[1];
	out->data[2] = a->data[2] + b->data[2];
	out->data[3] = a->data[3] + b->data[3];
	return out;
}

NtmQuat *ntm_quat_multiply(NtmQuat *out, NtmQuat *a, NtmQuat *b) {
	float ax = a->data[0], ay = a->data[1], az = a->data[2], aw = a->data[3],
		bx = b->data[0], by = b->data[1], bz = b->data[2], bw = b->data[3];

	out->data[0] = ax * bw + aw * bx + ay * bz - az * by;
	out->data[1] = ay * bw + aw * by + az * bx - ax * bz;
	out->data[2] = az * bw + aw * bz + ax * by - ay * bx;
	out->data[3] = aw * bw - ax * bx - ay * by - az * bz;
	return out;
}

NtmQuat *ntm_quat_scale(NtmQuat *out, NtmQuat *a, float b) {
	out->data[0] = a->data[0] * b;
	out->data[1] = a->data[1] * b;
	out->data[2] = a->data[2] * b;
	out->data[3] = a->data[3] * b;
	return out;
}

NtmQuat *ntm_quat_rotateX(NtmQuat *out, NtmQuat *a, float rad) {
	float ax, ay, az, aw, bx, bw;
	rad *= 0.5f;

	ax = a->data[0];
	ay = a->data[1];
	az = a->data[2];
	aw = a->data[3];
	bx = (float)sin(rad);
	bw = (float)cos(rad);

	out->data[0] = ax * bw + aw * bx;
	out->data[1] = ay * bw + az * bx;
	out->data[2] = az * bw - ay * bx;
	out->data[3] = aw * bw - ax * bx;
	return out;
}

NtmQuat *ntm_quat_rotateY(NtmQuat *out, NtmQuat *a, float rad) {
	float ax, ay, az, aw, by, bw;
	rad *= 0.5f;

	ax = a->data[0];
	ay = a->data[1];
	az = a->data[2];
	aw = a->data[3];
	by = (float)sin(rad);
	bw = (float)cos(rad);

	out->data[0] = ax * bw - az * by;
	out->data[1] = ay * bw + aw * by;
	out->data[2] = az * bw + ax * by;
	out->data[3] = aw * bw - ay * by;
	return out;
}

NtmQuat *ntm_quat_rotateZ(NtmQuat *out, NtmQuat *a, float rad) {
	float ax, ay, az, aw, bz, bw;
	rad *= 0.5f;

	ax = a->data[0];
	ay = a->data[1];
	az = a->data[2];
	aw = a->data[3];
	bz = (float)sin(rad);
	bw = (float)cos(rad);

	out->data[0] = ax * bw + ay * bz;
	out->data[1] = ay * bw - ax * bz;
	out->data[2] = az * bw + aw * bz;
	out->data[3] = aw * bw - az * bz;
	return out;
}

NtmQuat *ntm_quat_calculateW(NtmQuat *out, NtmQuat *a) {
	float x = a->data[0], y = a->data[1], z = a->data[2];

	out->data[0] = x;
	out->data[1] = y;
	out->data[2] = z;
	out->data[3] = (float)sqrt(fabs(1.0f - x * x - y * y - z * z));
	return out;
}

float ntm_quat_dot(NtmQuat *a, NtmQuat *b) {
	return	a->data[0] * b->data[0]
			+ a->data[1] * b->data[1]
			+ a->data[2] * b->data[2]
			+ a->data[3] * b->data[3];
}

NtmQuat *ntm_quat_lerp(NtmQuat *out, NtmQuat *a, NtmQuat *b, float t) {
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

NtmQuat *ntm_quat_slerp(NtmQuat *out, NtmQuat *a, NtmQuat *b, float t) {
	float ax = a->data[0], ay = a->data[1], az = a->data[2], aw = a->data[3],
		bx = b->data[0], by = b->data[1], bz = b->data[2], bw = b->data[3];

	float omega, cosom, sinom, scale0, scale1;

	/* calc cosine */
	cosom = ax * bx + ay * by + az * bz + aw * bw;
	/* adjust signs (if necessary) */
	if (cosom < 0.0f) {
		cosom = -cosom;
		bx = - bx;
		by = - by;
		bz = - bz;
		bw = - bw;
	}

	/* calculate coefficients */
	if ((1.0f - cosom) > NTM_EPSILON) {
		/* standard case (slerp) */
		omega  = (float)acos(cosom);
		sinom  = (float)sin(omega);
		scale0 = (float)sin((1.0f - t) * omega) / sinom;
		scale1 = (float)sin(t * omega) / sinom;
	} else {
		/* "from" and "to" quaternions are very close */
		/*  ... so we can do a linear interpolation */
		scale0 = 1.0f - t;
		scale1 = t;
	}
	/* calculate final values */
	out->data[0] = scale0 * ax + scale1 * bx;
	out->data[1] = scale0 * ay + scale1 * by;
	out->data[2] = scale0 * az + scale1 * bz;
	out->data[3] = scale0 * aw + scale1 * bw;

	return out;
}

NtmQuat *ntm_quat_invert(NtmQuat *out, NtmQuat *a) {
	float a0 = a->data[0], a1 = a->data[1], a2 = a->data[2], a3 = a->data[3],
		dot = a0*a0 + a1*a1 + a2*a2 + a3*a3;
	if (dot < NTM_EPSILON) {
		out->data[0] = 0.0f;
		out->data[1] = 0.0f;
		out->data[2] = 0.0f;
		out->data[3] = 0.0f;
	} else {
		dot = 1.0f/dot;
		out->data[0] = -a0*dot;
		out->data[1] = -a1*dot;
		out->data[2] = -a2*dot;
		out->data[3] = a3*dot;
	}
	return out;
}

NtmQuat *ntm_quat_conjugate(NtmQuat *out, NtmQuat *a) {
	out->data[0] = -a->data[0];
	out->data[1] = -a->data[1];
	out->data[2] = -a->data[2];
	out->data[3] = a->data[3];
	return out;
}

float ntm_quat_length(NtmQuat *a) {
	float x = a->data[0],
		y = a->data[1],
		z = a->data[2],
		w = a->data[3];
	return (float)sqrt(x*x + y*y + z*z + w*w);
}

float ntm_quat_squaredLength(NtmQuat *a) {
	float x = a->data[0],
		y = a->data[1],
		z = a->data[2],
		w = a->data[3];
	return x*x + y*y + z*z + w*w;
}

NtmQuat *ntm_quat_normalize(NtmQuat *out, NtmQuat *a) {
	float x = a->data[0],
		y = a->data[1],
		z = a->data[2],
		w = a->data[3],
		len = (float)sqrt(x*x + y*y + z*z + w*w);
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

NtmQuat *ntm_quat_fromMat3(NtmQuat *out, NtmMat3 *m) {
	/* Algorithm in Ken Shoemake's article in 1987 SIGGRAPH course notes */
	/* article "Quaternion Calculus and Fast Animation". */
	float fTrace = m->data[0] + m->data[4] + m->data[8];
	float fRoot;

	if (fTrace > 0.0f) {
		/* |w| > 1/2, may as well choose w > 1/2 */
		fRoot = (float)sqrt(fTrace + 1.0f); /* 2w */
		out->data[3] = 0.5f * fRoot;
		fRoot = 0.5f/fRoot; /* 1/(4w) */
		out->data[0] = (m->data[5]-m->data[7])*fRoot;
		out->data[1] = (m->data[6]-m->data[2])*fRoot;
		out->data[2] = (m->data[1]-m->data[3])*fRoot;
	} else {
		/* |w| <= 1/2 */
		int i = 0, j, k;
		if (m->data[4] > m->data[0]) {
			i = 1;
		}
		if (m->data[8] > m->data[i*3 + i]) {
			i = 2;
		}
		j = (i+1)%3;
		k = (i+2)%3;

		fRoot = (float)sqrt(m->data[i*3+i] - m->data[j*3+j] - m->data[k*3+k] + 1.0f);
		out->data[i] = 0.5f * fRoot;
		fRoot = 0.5f / fRoot;
		out->data[3] = (m->data[j*3+k] - m->data[k*3+j]) * fRoot;
		out->data[j] = (m->data[j*3+i] + m->data[i*3+j]) * fRoot;
		out->data[k] = (m->data[k*3+i] + m->data[i*3+k]) * fRoot;
	}

	return out;
}
