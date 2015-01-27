#include <math.h>

#include "ntmtest_common.h"
#include "ntmtest_vec3.h"

#include "ntm.h"

int ntmtest_vec3_copy(void) {
	NtmVec3 vec1;
	NtmVec3 vec2;
	ntm_vec3_set(&vec2, 2.5f, 5.0f, 7.5f);

	ntm_vec3_copy(&vec1, &vec2);

	NTMTEST_ASSERT(&vec1 != &vec2);
	NTMTEST_ASSERT(vec1.data != vec2.data);
	
	NTMTEST_VEC3EQ(&vec1, 2.5f, 5.0f, 7.5f);

	return 0;
}

int ntmtest_vec3_set(void) {
	NtmVec3 vec;
	ntm_vec3_set(&vec, 5.0f, 2.0f, -10.0f);
	
	NTMTEST_VEC3EQ(&vec, 5.0f, 2.0f, -10.0f);

	return 0;
}

int ntmtest_vec3_add(void) {
	NtmVec3 vec1, vec2;
	ntm_vec3_set(&vec1, 1.0f, -2.0f, 3.0f);
	ntm_vec3_set(&vec2, 4.0f, 5.0f, 6.5f);

	ntm_vec3_add(&vec1, &vec1, &vec2);
	
	NTMTEST_VEC3EQ(&vec1, 5.0f, 3.0f, 9.5f);

	return 0;
}

int ntmtest_vec3_subtract(void) {
	NtmVec3 vec1, vec2, vec3;
	ntm_vec3_set(&vec1, -4.5f, 3.5f, 5.0f);
	ntm_vec3_set(&vec2, 5.0f, 4.0f, 0.5f);

	ntm_vec3_subtract(&vec3, &vec2, &vec1);
	
	NTMTEST_VEC3EQ(&vec1, -4.5f, 3.5f, 5.0f);
	NTMTEST_VEC3EQ(&vec2, 5.0f, 4.0f, 0.5f);
	NTMTEST_VEC3EQ(&vec3, 9.5f, 0.5f, -4.5f);

	return 0;
}

int ntmtest_vec3_multiply(void) {
	NtmVec3 vec1, vec2;
	ntm_vec3_set(&vec1, 2.0f, 3.0f, -2.0f);
	ntm_vec3_set(&vec2, -3.0f, 0.5f, 1.5f);

	ntm_vec3_multiply(&vec2, &vec1, &vec2);
	
	NTMTEST_VEC3EQ(&vec2, -6.0f, 1.5f, -3.0f);

	return 0;
}

int ntmtest_vec3_divide(void) {
	NtmVec3 vec1, vec2;
	ntm_vec3_set(&vec1, 36.0f, -24.0f, -12.0f);
	ntm_vec3_set(&vec2, 2.0f, 3.0f, -4.0f);

	ntm_vec3_divide(&vec1, &vec1, &vec2);

	NTMTEST_VEC3EQ(&vec1, 18.0f, -8.0f, 3.0f);

	return 0;
}

int ntmtest_vec3_min(void) {
	NtmVec3 vec1, vec2;
	ntm_vec3_set(&vec1, 3.5f, 110.0f, -34.0f);
	ntm_vec3_set(&vec2, 5.0f, -542.0f, -50.0f);

	ntm_vec3_min(&vec1, &vec1, &vec2);

	NTMTEST_VEC3EQ(&vec1, 3.5f, -542.0f, -50.0f);

	return 0;
}

int ntmtest_vec3_max(void) {
	NtmVec3 vec1, vec2;
	ntm_vec3_set(&vec1, 0.5f, 1.5f, 50.0f);
	ntm_vec3_set(&vec2, -4.5f, 2.0f, -105.5f);

	ntm_vec3_max(&vec2, &vec1, &vec2);

	NTMTEST_VEC3EQ(&vec2, 0.5f, 2.0f, 50.0f);

	return 0;
}

int ntmtest_vec3_scale(void) {
	NtmVec3 vec1, vec2;
	ntm_vec3_set(&vec1, 3.0f, -3.0f, -4.5f);

	ntm_vec3_scale(&vec2, &vec1, 4.0f);

	NTMTEST_VEC3EQ(&vec2, 12.0f, -12.0f, -18.0f);

	return 0;
}

int ntmtest_vec3_scaleAndAdd(void) {
	NtmVec3 a, b;
	ntm_vec3_set(&a, 2.0f, 3.0f, -4.0f);
	ntm_vec3_set(&b, 1.5f, 2.5f, -2.0f);

	ntm_vec3_scaleAndAdd(&a, &a, &b, -2.0f);

	NTMTEST_VEC3EQ(&a, -1.0f, -2.0f, 0.0f);

	return 0;
}

int ntmtest_vec3_distance(void) {
	NtmVec3 a, b;
	float d, e;
	ntm_vec3_set(&a, 2.0f, 3.0f, -4.0f);
	ntm_vec3_set(&b, 6.0f, 5.0f, 4.0f);

	d = ntm_vec3_distance(&a, &b);
	e = ntm_vec3_distance(&b, &a);

	NTMTEST_EQF(d, e);
	NTMTEST_EQF(e, 9.16515139f);

	return 0;
}

int ntmtest_vec3_squaredDistance(void) {
	NtmVec3 a, b;
	float d, e;
	ntm_vec3_set(&a, -4.5f, 3.0f, 15.0f);
	ntm_vec3_set(&b, -6.5f, -2.0f, -12.0f);

	d = ntm_vec3_squaredDistance(&a, &b);
	e = ntm_vec3_squaredDistance(&b, &a);

	NTMTEST_EQF(d, e);
	NTMTEST_EQF(e, 758.0f);

	return 0;
}

int ntmtest_vec3_length(void) {
	NtmVec3 a;
	float l;
	ntm_vec3_set(&a, 5.0f, -3.0f, 6.0f);

	l = ntm_vec3_length(&a);

	NTMTEST_EQF(l, 8.366600265f);

	return 0;
}

int ntmtest_vec3_squaredLength(void) {
	NtmVec3 a;
	float l;
	ntm_vec3_set(&a, -15.0f, 10.5f, 3.0f);

	l = ntm_vec3_squaredLength(&a);

	NTMTEST_EQF(l, 344.25f);

	return 0;
}

int ntmtest_vec3_negate(void) {
	NtmVec3 a, b;
	ntm_vec3_set(&a, -12.5f, 2.5f, 5.0f);

	ntm_vec3_negate(&b, &a);

	NTMTEST_VEC3EQ(&b, 12.5f, -2.5f, -5.0f);

	ntm_vec3_negate(&a, &a);

	NTMTEST_VEC3EQ(&a, 12.5f, -2.5f, -5.0f);

	return 0;
}

int ntmtest_vec3_inverse(void) {
	NtmVec3 a;
	ntm_vec3_set(&a, 3.0f, 4.0f, -6.0f);

	ntm_vec3_inverse(&a, &a);

	NTMTEST_VEC3EQ(&a, 0.33333333333f, 0.25f, -0.1666666666667f);

	return 0;
}

int ntmtest_vec3_normalize(void) {
	NtmVec3 a;
	ntm_vec3_set(&a, -1.5f, 4.5f, 13.0f);

	ntm_vec3_normalize(&a, &a);

	NTMTEST_VEC3EQ(&a, -0.108394406f, 0.325183218f, 0.939418185f);

	return 0;
}

int ntmtest_vec3_dot(void) {
	NtmVec3 a, b;
	ntm_vec3_set(&a, 4.0f, -1.5f, 5.0f);
	ntm_vec3_set(&b, 2.0f, 3.0f, 4.0f);

	NTMTEST_EQF(ntm_vec3_dot(&a, &b), 23.5f);
	NTMTEST_EQF(ntm_vec3_dot(&b, &a), 23.5f);

	return 0;
}

int ntmtest_vec3_cross(void) {
	NtmVec3 a, b, c;
	ntm_vec3_set(&a, 3.0f, -2.5f, -5.0f);
	ntm_vec3_set(&b, -4.0f, -5.5f, 6.0f);

	ntm_vec3_cross(&c, &a, &b);

	NTMTEST_VEC3EQ(&c, -42.5f, 2.0f, -26.5f);

	return 0;
}

int ntmtest_vec3_lerp(void) {
	NtmVec3 a, b;
	ntm_vec3_set(&a, 2.5f, 6.0f, -11.5f);
	ntm_vec3_set(&b, 10.5f, 2.0f, 0.5f);

	ntm_vec3_lerp(&a, &a, &b, 0.75f);

	NTMTEST_VEC3EQ(&a, 8.5f, 3.0f, -2.5f);

	return 0;
}

int ntmtest_vec3_random(void) {
	NtmVec3 a;
	ntm_vec3_random(&a);

	NTMTEST_ASSERT(fabs(a.data[0]) <= 0.5);
	NTMTEST_ASSERT(fabs(a.data[1]) <= 0.5);
	NTMTEST_ASSERT(fabs(a.data[2]) <= 0.5);

	return 0;
}

int ntmtest_vec3_transformMat4(void) {
	NtmVec3 a;
	NtmMat4 m;
	ntm_mat4_set(&m,
		2.0f, 3.0f, 1.5f, -2.0f,
		-3.0f, -1.5f, 4.0f, -1.0f,
		4.0f, -4.0f, 0.5f, 2.0f,
		1.0f, 1.5f, 2.0f, -2.5f
	);
	ntm_vec3_set(&a, 4.0f, 5.0f, 2.0f);

	ntm_vec3_transformMat4(&a, &a, &m);

	NTMTEST_VEC3EQ(&a, 1.0f, -3.5f, 27.0f);

	return 0;
}

int ntmtest_vec3_transformMat3(void) {
	NtmVec3 a;
	NtmMat3 m;
	ntm_mat3_set(&m,
		3.0f, -5.0f, 1.0f,
		-4.0f, 2.0f, -2.0f,
		-0.5f, 4.5f, 2.5f
	);
	ntm_vec3_set(&a, 1.5f, -3.0f, 5.0f);

	ntm_vec3_transformMat3(&a, &a, &m);

	NTMTEST_VEC3EQ(&a, 14.0f, 9.0f, 20.0f);

	return 0;
}

int ntmtest_vec3_transformQuat(void) {
	NtmVec3 a;
	NtmQuat q;
	ntm_quat_set(&q, 0.0f, 0.0f, -0.707106781f, 0.707106781f);
	ntm_vec3_set(&a, 2.0f, 1.0f, 0.0f);
	
	ntm_vec3_transformQuat(&a, &a, &q);

	NTMTEST_VEC3EQ(&a, 1.0f, -2.0f, 0.0f);

	return 0;
}

int ntmtest_vec3_rotateX(void) {
	NtmVec3 a;
	ntm_vec3_set(&a, 3.0f, 5.0f, 2.0f);
	ntm_vec3_rotateX(&a, &a, 0.5f);
	
	NTMTEST_VEC3EQ(&a, 3.0f, 3.429062f, 4.152293f);
	
	return 0;
}

int ntmtest_vec3_rotateY(void) {
	NtmVec3 a;
	ntm_vec3_set(&a, 7.0f, -5.0f, 1.5f);
	ntm_vec3_rotateY(&a, &a, 0.7f);
	
	NTMTEST_VEC3EQ(&a, 6.320222f, -5.0f, -3.362261f);
	
	return 0;
}

int ntmtest_vec3_rotateZ(void) {
	NtmVec3 a;
	ntm_vec3_set(&a, -4.0f, 2.5f, -3.0f);
	ntm_vec3_rotateZ(&a, &a, 2.1f);
	
	NTMTEST_VEC3EQ(&a, -0.138639f, -4.714953f, -3.0f);
	
	return 0;
}

int ntmtest_vec3(void) {
	return
		ntmtest_vec3_copy()
		+ ntmtest_vec3_set()
		+ ntmtest_vec3_add()
		+ ntmtest_vec3_subtract()
		+ ntmtest_vec3_multiply()
		+ ntmtest_vec3_divide()
		+ ntmtest_vec3_min()
		+ ntmtest_vec3_max()
		+ ntmtest_vec3_scale()
		+ ntmtest_vec3_scaleAndAdd()
		+ ntmtest_vec3_distance()
		+ ntmtest_vec3_squaredDistance()
		+ ntmtest_vec3_length()
		+ ntmtest_vec3_squaredLength()
		+ ntmtest_vec3_negate()
		+ ntmtest_vec3_inverse()
		+ ntmtest_vec3_normalize()
		+ ntmtest_vec3_dot()
		+ ntmtest_vec3_cross()
		+ ntmtest_vec3_lerp()
		+ ntmtest_vec3_random()
		+ ntmtest_vec3_transformMat4()
		+ ntmtest_vec3_transformMat3()
		+ ntmtest_vec3_transformQuat()
		+ ntmtest_vec3_rotateX()
		+ ntmtest_vec3_rotateY()
		+ ntmtest_vec3_rotateZ();
}
