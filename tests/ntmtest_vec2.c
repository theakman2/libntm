#include <stdio.h>
#include <math.h>

#include "ntmtest_common.h"
#include "ntmtest_vec2.h"

#include "ntm.h"

int ntmtest_vec2_copy(void) {
	NtmVec2 vec1;
	NtmVec2 vec2;
	
	vec1.data[0] = 0.5f;
	vec1.data[1] = 1.5f;
	
	vec2.data[0] = 4.5f;
	vec2.data[1] = 50.0f;

	NTMTEST_ASSERT(&vec1 != &vec2);
	NTMTEST_ASSERT(vec1.data != vec2.data);

	ntm_vec2_copy(&vec1, &vec2);

	NTMTEST_ASSERT(&vec1 != &vec2);
	NTMTEST_ASSERT(vec1.data != vec2.data);
	NTMTEST_VEC2EQ(&vec1, 4.5f, 50.0f);

	return 0;
}

int ntmtest_vec2_set(void) {
	NtmVec2 vec1;

	ntm_vec2_set(&vec1, 3.5f, 7.5f);

	NTMTEST_VEC2EQ(&vec1, 3.5f, 7.5f);

	return 0;
}

int ntmtest_vec2_add(void) {
	NtmVec2 a;
	NtmVec2 b;
	
	ntm_vec2_set(&a, 4.5f, 5.5f);
	ntm_vec2_set(&b, 2.0f, 3.5f);

	ntm_vec2_add(&a, &a, &b);

	NTMTEST_VEC2EQ(&a, 6.5f, 9.0f);
	NTMTEST_VEC2EQ(&b, 2.0f, 3.5f);

	return 0;
}

int ntmtest_vec2_subtract(void) {
	NtmVec2 a;
	NtmVec2 b;
	ntm_vec2_set(&a, 4.5f, 5.5f);
	ntm_vec2_set(&b, 2.0f, 3.5f);

	ntm_vec2_subtract(&a, &a, &b);

	NTMTEST_VEC2EQ(&a, 2.5f, 2.0f);
	NTMTEST_VEC2EQ(&b, 2.0f, 3.5f);

	return 0;
}

int ntmtest_vec2_multiply(void) {
	NtmVec2 a;
	NtmVec2 b;
	ntm_vec2_set(&a, 2.5f, 3.0f);
	ntm_vec2_set(&b, 5.0f, 2.0f);

	ntm_vec2_multiply(&b, &a, &b);

	NTMTEST_VEC2EQ(&b, 12.5f, 6.0f);

	return 0;
}

int ntmtest_vec2_divide(void) {
	NtmVec2 a, b;
	ntm_vec2_set(&a,6.0f, 11.0f);
	ntm_vec2_set(&b,2.0f, 5.5f);

	ntm_vec2_divide(&a, &a, &b);

	NTMTEST_VEC2EQ(&a, 3.0f, 2.0f);
	NTMTEST_VEC2EQ(&b, 2.0f, 5.5f);

	return 0;
}

int ntmtest_vec2_min(void) {
	NtmVec2 a, b, c;
	ntm_vec2_set(&a, 2.5f, 4.5f);
	ntm_vec2_set(&b, 5.5f, 1.0f);

	ntm_vec2_min(&c, &a, &b);

	NTMTEST_VEC2EQ(&c, 2.5f, 1.0f);

	return 0;
}

int ntmtest_vec2_max(void) {
	NtmVec2 a, b, c;
	ntm_vec2_set(&a, 2.5f, 4.5f);
	ntm_vec2_set(&b, 5.5f, 1.0f);

	ntm_vec2_max(&c, &a, &b);

	NTMTEST_VEC2EQ(&c, 5.5f, 4.5f);

	return 0;
}

int ntmtest_vec2_scale(void) {
	NtmVec2 a;
	ntm_vec2_set(&a, 3.5f, 5.5f);
	
	ntm_vec2_scale(&a, &a, 4.0f);

	NTMTEST_VEC2EQ(&a, 14.0f, 22.0f);

	return 0;
}

int ntmtest_vec2_scaleAndAdd(void) {
	NtmVec2 a, b;
	ntm_vec2_set(&a, 2.0f, 3.0f);
	ntm_vec2_set(&b, 1.5f, 2.5f);

	ntm_vec2_scaleAndAdd(&a, &a, &b, 3.0f);

	NTMTEST_VEC2EQ(&a, 6.5f, 10.5f);

	return 0;
}

int ntmtest_vec2_distance(void) {
	NtmVec2 a, b;
	float d, e;
	ntm_vec2_set(&a, 3.0f, -5.0f);
	ntm_vec2_set(&b, 7.0f, -8.0f);
	
	d = ntm_vec2_distance(&a, &b);
	e = ntm_vec2_distance(&b, &a);

	NTMTEST_EQF(d, e);
	NTMTEST_EQF(d, 5.0f);

	return 0;
}

int ntmtest_vec2_squaredDistance(void) {
	NtmVec2 a, b;
	float d, e;
	ntm_vec2_set(&a, 3.0f, -5.0f);
	ntm_vec2_set(&b, 7.0f, -8.0f);
	d = ntm_vec2_squaredDistance(&a, &b);
	e = ntm_vec2_squaredDistance(&b, &a);

	NTMTEST_EQF(d, e);
	NTMTEST_EQF(d, 25.0f);

	return 0;
}

int ntmtest_vec2_length(void) {
	NtmVec2 a;
	ntm_vec2_set(&a, 6.0f, 8.0f);

	NTMTEST_EQF(ntm_vec2_length(&a), 10.0f);

	return 0;
}

int ntmtest_vec2_squaredLength(void) {
	NtmVec2 a;
	ntm_vec2_set(&a, 6.0f, 8.0f);
	
	NTMTEST_EQF(ntm_vec2_squaredLength(&a), 100.0f);

	return 0;
}

int ntmtest_vec2_negate(void) {
	NtmVec2 a;
	ntm_vec2_set(&a, 6.0f, 8.0f);

	ntm_vec2_negate(&a,&a);

	NTMTEST_VEC2EQ(&a, -6.0f, -8.0f);

	return 0;
}

int ntmtest_vec2_inverse(void) {
	NtmVec2 a;
	ntm_vec2_set(&a, 8.0f, 4.0f);

	ntm_vec2_inverse(&a, &a);

	NTMTEST_VEC2EQ(&a, 0.125f, 0.25f);
	
	ntm_vec2_set(&a, 0.0f, 6.0f);
	
	NTMTEST_ASSERT(ntm_vec2_inverse(&a, &a) == NULL);
	
	return 0;
}

int ntmtest_vec2_normalize(void) {
	NtmVec2 a, b;
	ntm_vec2_set(&a, 3.0f, 4.0f);

	ntm_vec2_normalize(&b, &a);

	NTMTEST_VEC2EQ(&b, 0.6f, 0.8f);
	
	ntm_vec2_set(&a, -0.0000001f, 0.0000001f);
	
	NTMTEST_ASSERT(ntm_vec2_normalize(&a, &a) == NULL);
	
	return 0;
}

int ntmtest_vec2_dot(void) {
	NtmVec2 a, b;
	ntm_vec2_set(&a, 2.0f, 4.5f);
	ntm_vec2_set(&b, 1.5f, 3.0f);

	NTMTEST_EQF(ntm_vec2_dot(&a, &b), 16.5f);

	return 0;
}

int ntmtest_vec2_cross(void) {
	NtmVec2 a, b;
	NtmVec3 out;
	ntm_vec2_set(&a, 1.5f, 5.0f);
	ntm_vec2_set(&b, 2.5f, 3.0f);
	
	ntm_vec2_cross(&out, &a, &b);

	NTMTEST_VEC3EQ(&out, 0.0f, 0.0f, -8.0f);

	return 0;
}

int ntmtest_vec2_lerp(void) {
	NtmVec2 a, b;
	ntm_vec2_set(&a, 10.0f, 20.0f);
	ntm_vec2_set(&b, 30.0f, -10.0f);
	ntm_vec2_lerp(&a, &a, &b, 0.5f);

	NTMTEST_VEC2EQ(&a, 20.0f, 5.0f);

	return 0;
}

int ntmtest_vec2_random(void) {
	NtmVec2 a;
	ntm_vec2_random(&a);

	NTMTEST_ASSERT(fabs(a.data[0]) <= 0.5);
	NTMTEST_ASSERT(fabs(a.data[1]) <= 0.5);

	return 0;
}

int ntmtest_vec2_transformMat2(void) {
	NtmVec2 a;
	NtmMat2 m;
	ntm_mat2_set(&m, 1.5f, 2.5f, 4.0f, 5.0f);
	ntm_vec2_set(&a, 2.0f, 3.0f);

	ntm_vec2_transformMat2(&a, &a, &m);

	NTMTEST_VEC2EQ(&a, 15.0f, 20.0f);

	return 0;
}

int ntmtest_vec2_transformMat2d(void) {
	NtmVec2 a;
	NtmMat2d m;
	ntm_mat2d_set(&m,
		2.0f, 3.0f,
		4.0f, 5.0f,
		6.0f, 9.0f
	);
	ntm_vec2_set(&a, -1.5f, 0.5f);

	ntm_vec2_transformMat2d(&a, &a, &m);

	NTMTEST_VEC2EQ(&a, 5.0f, 7.0f);

	return 0;
}

int ntmtest_vec2_transformMat3(void) {
	NtmVec2 a;
	NtmMat3 m;
	ntm_mat3_set(&m,
		2.0f, 2.5f, 3.0f,
		2.0f, 5.0f, -2.0f,
		9.0f, -9.0f, 12.0f
	);
	ntm_vec2_set(&a, 7.5f, -2.0f);

	ntm_vec2_transformMat3(&a, &a, &m);

	NTMTEST_VEC2EQ(&a, 20.0f, -0.25f);

	return 0;
}

int ntmtest_vec2_transformMat4(void) {
	NtmVec2 a;
	NtmMat4 m;
	ntm_mat4_set(&m,
		-4.0f, -3.0f, -2.0f, -1.0f,
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, -8.0f, -7.0f, -6.0f
	);
	ntm_vec2_set(&a, -3.0f, -6.5f);

	ntm_vec2_transformMat4(&a, &a, &m);

	NTMTEST_VEC2EQ(&a, 14.5f, -12.0f);

	return 0;
}


int ntmtest_vec2(void) {
	return
		ntmtest_vec2_copy()
		+ ntmtest_vec2_set()
		+ ntmtest_vec2_add()
		+ ntmtest_vec2_subtract()
		+ ntmtest_vec2_multiply()
		+ ntmtest_vec2_divide()
		+ ntmtest_vec2_min()
		+ ntmtest_vec2_max()
		+ ntmtest_vec2_scale()
		+ ntmtest_vec2_scaleAndAdd()
		+ ntmtest_vec2_distance()
		+ ntmtest_vec2_squaredDistance()
		+ ntmtest_vec2_length()
		+ ntmtest_vec2_squaredLength()
		+ ntmtest_vec2_negate()
		+ ntmtest_vec2_inverse()
		+ ntmtest_vec2_normalize()
		+ ntmtest_vec2_dot()
		+ ntmtest_vec2_cross()
		+ ntmtest_vec2_lerp()
		+ ntmtest_vec2_random()
		+ ntmtest_vec2_transformMat2()
		+ ntmtest_vec2_transformMat2d()
		+ ntmtest_vec2_transformMat3()
		+ ntmtest_vec2_transformMat4();
}
