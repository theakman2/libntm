#include <math.h>

#include "ntmtest_common.h"
#include "ntmtest_vec4.h"

#include "ntm.h"

int ntmtest_vec4_copy(void) {
	NtmVec4 a, b;
	ntm_vec4_set(&b, 1.4f, 2.0f, -3.7f, 5.0f);
	
	ntm_vec4_copy(&a, &b);
	
	NTMTEST_ASSERT(&a != &b);
	NTMTEST_ASSERT(a.data != b.data);
	NTMTEST_VEC4EQ(&a, 1.4f, 2.0f, -3.7f, 5.0f);
	
	return 0;
}

int ntmtest_vec4_set(void) {
	NtmVec4 a;
	ntm_vec4_set(&a, 1.0f, 2.0f, 3.0f, -4.0f);
	
	NTMTEST_VEC4EQ(&a, 1.0f, 2.0f, 3.0f, -4.0f);
	
	return 0;
}

int ntmtest_vec4_add(void) {
	NtmVec4 a, b;
	ntm_vec4_set(&a, 3.5f, 5.5f, 3.0f, -2.0f);
	ntm_vec4_set(&b, -3.0f, -7.0f, 1.5f, 4.0f);
	
	ntm_vec4_add(&a, &a, &b);
	
	NTMTEST_VEC4EQ(&a, 0.5f, -1.5f, 4.5f, 2.0f);
	
	return 0;
}

int ntmtest_vec4_subtract(void) {
	NtmVec4 a, b;
	ntm_vec4_set(&a, 2.0f, 4.0f, 6.0f, -8.0f);
	ntm_vec4_set(&b, 4.0f, 3.5f, -1.0f, -30.0f);
	
	ntm_vec4_subtract(&a, &a, &b);
	
	NTMTEST_VEC4EQ(&a, -2.0f, 0.5f, 7.0f, 22.0f);
	
	return 0;
}

int ntmtest_vec4_multiply(void) {
	NtmVec4 a, b;
	ntm_vec4_set(&a, -1.5f, 2.0f, 0.5f, 4.0f);
	ntm_vec4_set(&b, 2.0f, 3.0f, 4.0f, -2.0f);
	
	ntm_vec4_multiply(&b, &a, &b);
	
	NTMTEST_VEC4EQ(&b, -3.0f, 6.0f, 2.0f, -8.0f);
	
	return 0;
}

int ntmtest_vec4_divide(void) {
	NtmVec4 a, b;
	ntm_vec4_set(&a, 3.0f, -2.0f, 4.0f, -15.0f);
	ntm_vec4_set(&b, 2.0f, -0.5f, -4.0f, 5.0f);
	
	ntm_vec4_divide(&a, &a, &b);
	
	NTMTEST_VEC4EQ(&a, 1.5f, 4.0f, -1.0f, -3.0f);
	
	return 0;
}

int ntmtest_vec4_min(void) {
	NtmVec4 a, b, c;
	ntm_vec4_set(&a, -35.0f, 50.0f, 20.5f, 0.5f);
	ntm_vec4_set(&b, -25.5f, 29.5f, 45.0f, -1.0f);
	
	ntm_vec4_min(&c, &a, &b);
	
	NTMTEST_VEC4EQ(&c, -35.0f, 29.5f, 20.5f, -1.0f);
	
	return 0;
}

int ntmtest_vec4_max(void) {
	NtmVec4 a, b;
	ntm_vec4_set(&a, 11.0f, -25.5f, 25.0f, 2.0f);
	ntm_vec4_set(&b, -50.5f, -19.5f, -3.0f, 1.5f);
	
	ntm_vec4_max(&a, &a, &b);
	
	NTMTEST_VEC4EQ(&a, 11.0f, -19.5f, 25.0f, 2.0f);
	
	return 0;
}

int ntmtest_vec4_scale(void) {
	NtmVec4 a;
	ntm_vec4_set(&a, 5.0f, 3.5f, -2.0f, -1.5f);
	
	ntm_vec4_scale(&a, &a, 3.0f);
	
	NTMTEST_VEC4EQ(&a, 15.0f, 10.5f, -6.0f, -4.5f);
	
	return 0;
}

int ntmtest_vec4_scaleAndAdd(void) {
	NtmVec4 a;
	ntm_vec4_set(&a, 4.5f, -3.0f, 9.5f, -7.0f);
	
	ntm_vec4_scaleAndAdd(&a, &a, &a, 2.0f);
	
	NTMTEST_VEC4EQ(&a, 13.5f, -9.0f, 28.5f, -21.0f);
	
	return 0;
}

int ntmtest_vec4_distance(void) {
	NtmVec4 a, b;
	float d, e;
	ntm_vec4_set(&a, 1.0f, -2.0f, 3.0f, -4.0f);
	ntm_vec4_set(&b, 8.0f, -7.0f, 6.0f, -5.0f);
	
	d = ntm_vec4_distance(&a, &b);
	e = ntm_vec4_distance(&b, &a);
	
	NTMTEST_EQF(d, e);
	NTMTEST_EQF(d, 9.16515139f);
	
	return 0;
}

int ntmtest_vec4_squaredDistance(void) {
	NtmVec4 a, b;
	float d, e;
	ntm_vec4_set(&a, 4.0f, -15.5f, 12.0f, 1.0f);
	ntm_vec4_set(&b, 9.0f, 1.5f, 3.0f, -14.0f);
	
	d = ntm_vec4_squaredDistance(&a, &b);
	e = ntm_vec4_squaredDistance(&b, &a);
	
	NTMTEST_EQF(d, e);
	NTMTEST_EQF(d, 620.0f);
	
	return 0;
}

int ntmtest_vec4_length(void) {
	NtmVec4 a;
	float d;
	ntm_vec4_set(&a, 3.0f, -2.0f, 4.5f, 2.5f);
	
	d = ntm_vec4_length(&a);
	
	NTMTEST_EQF(d, 6.284902545f);
	
	return 0;
}

int ntmtest_vec4_squaredLength(void) {
	NtmVec4 a;
	float d;
	ntm_vec4_set(&a, -13.0f, 2.0f, -4.0f, 0.0f);
	
	d = ntm_vec4_squaredLength(&a);
	
	NTMTEST_EQF(d, 189.0f);
	
	return 0;
}

int ntmtest_vec4_negate(void) {
	NtmVec4 a, b;
	ntm_vec4_set(&a, 24.0f, -35.0f, 122.5f, -62.0f);
	
	ntm_vec4_negate(&b, &a);
	
	NTMTEST_VEC4EQ(&b, -24.0f, 35.0f, -122.5f, 62.0f);
	
	return 0;
}

int ntmtest_vec4_inverse(void) {
	NtmVec4 a;
	ntm_vec4_set(&a, 4.0f, -2.0f, 8.0f, -8.0f);
	
	ntm_vec4_inverse(&a, &a);
	
	NTMTEST_VEC4EQ(&a, 0.25f, -0.5f, 0.125f, -0.125f);
	
	return 0;
}

int ntmtest_vec4_normalize(void) {
	NtmVec4 a, b;
	ntm_vec4_set(&a, 3.5f, 2.2f, -19.3f, 11.0f);
	
	ntm_vec4_normalize(&b, &a);
	
	NTMTEST_VEC4EQ(
		&b,
		0.154894552f,
		0.09736229f,
		-0.854132819f,
		0.486811451f
	);
	
	return 0;
}

int ntmtest_vec4_dot(void) {
	NtmVec4 a, b;
	float d, e;
	ntm_vec4_set(&a, 4.0f, -5.5f, 7.0f, 2.0f);
	ntm_vec4_set(&b, 10.0f, 2.0f, -1.0f, 6.5f);
	
	d = ntm_vec4_dot(&a, &b);
	e = ntm_vec4_dot(&b, &a);
	
	NTMTEST_EQF(d, e);
	NTMTEST_EQF(d, 35.0f);
	
	return 0;
}

int ntmtest_vec4_lerp(void) {
	NtmVec4 a, b;
	ntm_vec4_set(&a, 3.0f, -2.0f, 1.0f, -2.0f);
	ntm_vec4_set(&b, 11.0f, 2.0f, 13.0f, 14.0f);
	
	ntm_vec4_lerp(&a, &a, &b, 0.25f);
	
	NTMTEST_VEC4EQ(
		&a,
		5.0f,
		-1.0f,
		4.0f,
		2.0f
	);
	
	return 0;
}

int ntmtest_vec4_random(void) {
	NtmVec4 a;
	ntm_vec4_random(&a);
	
	NTMTEST_ASSERT(fabs(a.data[0]) <= 0.5);
	NTMTEST_ASSERT(fabs(a.data[1]) <= 0.5);
	NTMTEST_ASSERT(fabs(a.data[2]) <= 0.5);
	NTMTEST_ASSERT(fabs(a.data[3]) <= 0.5);

	return 0;
}

int ntmtest_vec4_transformMat4(void) {
	NtmVec4 a;
	NtmMat4 m;
	ntm_mat4_set(&m,
		-2.0f, 4.0f, 1.5f, -2.0f,
		3.0f, -1.0f, 4.0f, 1.0f,
		4.0f, -4.0f, 2.5f, 2.0f,
		-1.0f, 1.5f, 2.0f, -2.0f
	);
	ntm_vec4_set(&a, 4.0f, 5.0f, 2.0f, 3.0f);

	ntm_vec4_transformMat4(&a, &a, &m);
	
	NTMTEST_VEC4EQ(
		&a,
		12.0f,
		7.5f,
		37.0f,
		-5.0f
	);

	return 0;
}

int ntmtest_vec4_transformQuat(void) {
	NtmVec4 a;
	NtmQuat q;
	ntm_vec4_set(&a, 1.0f, 2.0f, -4.0f, 4.5f);
	ntm_quat_set(&q, 0.0f, -0.707106781f, 0.0f, 0.707106781f);

	ntm_vec4_transformQuat(&a, &a, &q);
	NTMTEST_VEC4EQ(
		&a,
		4.0f,
		2.0f,
		1.0f,
		4.5f
	);

	return 0;
}

int ntmtest_vec4(void) {
	return
		ntmtest_vec4_copy()
		+ ntmtest_vec4_set()
		+ ntmtest_vec4_add()
		+ ntmtest_vec4_subtract()
		+ ntmtest_vec4_multiply()
		+ ntmtest_vec4_divide()
		+ ntmtest_vec4_min()
		+ ntmtest_vec4_max()
		+ ntmtest_vec4_scale()
		+ ntmtest_vec4_scaleAndAdd()
		+ ntmtest_vec4_distance()
		+ ntmtest_vec4_squaredDistance()
		+ ntmtest_vec4_length()
		+ ntmtest_vec4_squaredLength()
		+ ntmtest_vec4_negate()
		+ ntmtest_vec4_inverse()
		+ ntmtest_vec4_normalize()
		+ ntmtest_vec4_dot()
		+ ntmtest_vec4_lerp()
		+ ntmtest_vec4_random()
		+ ntmtest_vec4_transformMat4()
		+ ntmtest_vec4_transformQuat();
}
