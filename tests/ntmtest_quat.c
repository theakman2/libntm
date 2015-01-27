#include <stdio.h>
#include <math.h>

#include "ntmtest_common.h"
#include "ntmtest_quat.h"

#include "ntm.h"

int ntmtest_quat_identity(void) {
	NtmQuat a;
	
	ntm_quat_identity(&a);
	
	NTMTEST_QUATEQ(&a, 0.0f, 0.0f, 0.0f, 1.0f);
	
	return 0;
}

int ntmtest_quat_copy(void) {
	NtmQuat a, b;
	ntm_quat_set(&b, 2.0f, 4.0f, 3.0f, 0.5f);
	
	ntm_quat_copy(&a, &b);
	
	NTMTEST_ASSERT(&a != &b);
	NTMTEST_ASSERT(a.data != b.data);
	NTMTEST_QUATEQ(&a, 2.0f, 4.0f, 3.0f, 0.5f);
	
	return 0;
}

int ntmtest_quat_set(void) {
	NtmQuat a;
	
	ntm_quat_set(&a, 0.5f, 1.5f, 2.5f, 3.0f);
	
	NTMTEST_QUATEQ(&a, 0.5f, 1.5f, 2.5f, 3.0f);
	
	return 0;
}

int ntmtest_quat_rotationTo(void) {
	NtmVec3 v1, v2;
	NtmQuat a;
	ntm_vec3_set(&v1, 0.0f, 1.0f, 0.0f);
	ntm_vec3_set(&v2, 0.0f, 0.0f, 1.0f);
	
	ntm_quat_rotationTo(&a, &v1, &v2);
	
	NTMTEST_QUATEQ(&a, 0.707106781f, 0.0f, 0.0f, 0.707106781f);
	
	return 0;
}

int ntmtest_quat_setAxes(void) {
	NtmQuat a;
	NtmVec3 view;
	NtmVec3 right;
	NtmVec3 up;
	ntm_vec3_set(&view, 1.0f, 0.0f, 0.0f);
	ntm_vec3_set(&right, 0.0f, 0.0f, 1.0f);
	ntm_vec3_set(&up, 0.0f, 1.0f, 0.0f);
	
	ntm_quat_setAxes(&a, &view, &right, &up);

	NTMTEST_QUATEQ(&a, 0.0f, 0.7071068f, 0.0f, 0.7071068f);

	return 0;
}

int ntmtest_quat_setAxisAngle(void) {
	NtmQuat a;
	NtmVec3 b;
	ntm_vec3_set(&b, -0.5f, 1.0f, -1.5f);
	
	ntm_quat_setAxisAngle(&a, &b, 1.6f);
	
	NTMTEST_QUATEQ(&a, -0.3586780f, 0.7173561f, -1.0760341f, 0.6967067f);
	
	return 0;
}

int ntmtest_quat_setAxisAngleF(void) {
	NtmQuat a;
	
	ntm_quat_setAxisAngleF(&a, 2.0f, -3.0f, 1.5f, 0.9f);
	
	NTMTEST_QUATEQ(&a, 0.8699311f, -1.3048966f, 0.6524483f, 0.9004471f);
	
	return 0;
}

int ntmtest_quat_add(void) {
	NtmQuat a, b;
	ntm_quat_set(&a, 1.0f, 2.0f, 3.0f, 2.5f);
	ntm_quat_set(&b, 2.0f, -3.0f, 1.5f, 3.0f);
	
	ntm_quat_add(&a, &a, &b);
	
	NTMTEST_QUATEQ(&a, 3.0f, -1.0f, 4.5f, 5.5f);
	
	return 0;
}

int ntmtest_quat_multiply(void) {
	NtmQuat a, b;
	ntm_quat_setAxisAngleF(&a, 1.0f, 2.0f, 3.0f, 0.5f);
	ntm_quat_setAxisAngleF(&b, 8.0f, -4.0f, -3.0f, 0.9f);
	
	ntm_quat_multiply(&a, &a, &b);
	
	NTMTEST_QUATEQ(&a, 4.2399954f, 1.6653036f, -2.7482519f, 1.8409641f);
	
	return 0;
}

int ntmtest_quat_scale(void) {
	NtmQuat a;
	ntm_quat_set(&a, 2.5f, 1.5f, 4.0f, 2.0f);
	
	ntm_quat_scale(&a, &a, 2.0f);
	
	NTMTEST_QUATEQ(&a, 5.0f, 3.0f, 8.0f, 4.0f);
	
	return 0;
}

int ntmtest_quat_rotateX(void) {
	NtmQuat a;
	ntm_quat_setAxisAngleF(&a, 0.0f, 0.0f, 1.0f, 0.5f);
	
	ntm_quat_rotateX(&a, &a, 0.5f);
	
	NTMTEST_QUATEQ(&a, 0.2397128f, 0.0612087f, 0.2397128f, 0.9387913f);
	
	return 0;
}

int ntmtest_quat_rotateY(void) {
	NtmQuat a;
	ntm_quat_setAxisAngleF(&a, 0.0f, 0.0f, 1.0f, 0.5f);
	
	ntm_quat_rotateY(&a, &a, 0.5f);
	
	NTMTEST_QUATEQ(&a, -0.0612087f, 0.2397128f, 0.2397128f, 0.9387913f);
	
	return 0;
}

int ntmtest_quat_rotateZ(void) {
	NtmQuat a;
	ntm_quat_setAxisAngleF(&a, 0.0f, 0.0f, 1.0f, 0.5f);
	
	ntm_quat_rotateZ(&a, &a, 0.5f);
	
	NTMTEST_QUATEQ(&a, 0.0f, 0.0f, 0.4794255f, 0.8775826f);
	
	return 0;
}

int ntmtest_quat_calculateW(void) {
	NtmQuat a;
	ntm_quat_set(&a, 0.30036145f, 0.45054217f, 0.6007229f, 0.0f);
	
	ntm_quat_calculateW(&a, &a);
	
	NTMTEST_QUATEQ(&a, 0.30036145f, 0.45054217f, 0.6007229f, 0.588155f);
	
	return 0;
}

int ntmtest_quat_dot(void) {
	NtmQuat a, b;
	ntm_quat_set(&a, -1.0f, 2.0f, 3.0f, 2.0f);
	ntm_quat_set(&b, 2.0f, -3.5f, 2.0f, -4.0f);
	
	NTMTEST_EQF(ntm_quat_dot(&a, &b), -11.0f);
	
	return 0;
}

int ntmtest_quat_lerp(void) {
	NtmQuat a, b;
	ntm_quat_set(&a, 1.0f, 2.0f, 3.0f, 4.0f);
	ntm_quat_set(&b, 7.0f, 6.0f, 5.0f, 2.0f);
	
	ntm_quat_lerp(&a, &a, &b, 0.25f);
	
	NTMTEST_QUATEQ(&a, 2.5f, 3.0f, 3.5f, 3.5f);
	
	return 0;
}

int ntmtest_quat_slerp(void) {
	NtmQuat a, b;
	ntm_quat_setAxisAngleF(&a, 1.0f, 2.0f, 3.0f, 0.5f);
	ntm_quat_setAxisAngleF(&b, 3.0f, -2.0f, 1.0f, 1.0f);
	
	ntm_quat_slerp(&a, &a, &b, 0.5f);
	
	NTMTEST_QUATEQ(&a, 0.8428403f, -0.2320216f, 0.6108187f, 0.9232475f);
	
	return 0;
}

int ntmtest_quat_invert(void) {
	NtmQuat a, b;
	ntm_quat_set(&a, 0.30036145f, 0.45054217f, 0.6007229f, 0.58815538f);
	
	ntm_quat_invert(&b, &a);
	
	NTMTEST_QUATEQ(&b, -0.300361f, -0.450542f, -0.60072f, 0.588155f);
	
	return 0;
}

int ntmtest_quat_conjugate(void) {
	NtmQuat a;
	ntm_quat_set(&a, 1.0f, 1.5f, 2.0f, 2.5f);
	
	ntm_quat_conjugate(&a, &a);
	
	NTMTEST_QUATEQ(&a, -1.0f, -1.5f, -2.0f, 2.5f);
		
	return 0;
}

int ntmtest_quat_length(void) {
	NtmQuat a;
	ntm_quat_set(&a, 2.0f, 3.0f, 4.0f, 5.0f);
	
	NTMTEST_EQF(ntm_quat_length(&a), 7.348469228f);
	
	return 0;
}

int ntmtest_quat_squaredLength(void) {
	NtmQuat a;
	ntm_quat_set(&a, 4.0f, 2.0f, 2.0f, 3.0f);
	
	NTMTEST_EQF(ntm_quat_squaredLength(&a), 33.0f);
	
	return 0;
}

int ntmtest_quat_normalize(void) {
	NtmQuat a, b;
	ntm_quat_set(&a, 3.0f, 1.5f, 2.0f, 2.5f);
	ntm_quat_normalize(&b, &a);
	
	NTMTEST_QUATEQ(
		&b,
		0.646996639f,
		0.323498319f,
		0.431331092f,
		0.539163866f
	);
	
	
	return 0;
}

int ntmtest_quat_fromMat3(void) {
	NtmMat3 a;
	NtmQuat b;
	ntm_mat3_set(&a,
		0.877582561f, 0.479425538f, 0.0f,
		-0.479425538f, 0.877582561f, 0.0f,
		0.0f, 0.0f, 1.0f
	);
	
	ntm_quat_fromMat3(&b, &a);
	
	NTMTEST_QUATEQ(&b, 0.0f, 0.0f, 0.247404f, 0.968912f);
	
	return 0;
}

int ntmtest_quat(void) {
	return
		ntmtest_quat_identity()
		+ ntmtest_quat_copy()
		+ ntmtest_quat_set()
		+ ntmtest_quat_rotationTo()
		+ ntmtest_quat_setAxes()
		+ ntmtest_quat_setAxisAngle()
		+ ntmtest_quat_setAxisAngleF()
		+ ntmtest_quat_add()
		+ ntmtest_quat_multiply()
		+ ntmtest_quat_scale()
		+ ntmtest_quat_rotateX()
		+ ntmtest_quat_rotateY()
		+ ntmtest_quat_rotateZ()
		+ ntmtest_quat_calculateW()
		+ ntmtest_quat_dot()
		+ ntmtest_quat_lerp()
		+ ntmtest_quat_slerp()
		+ ntmtest_quat_invert()
		+ ntmtest_quat_conjugate()
		+ ntmtest_quat_length()
		+ ntmtest_quat_squaredLength()
		+ ntmtest_quat_normalize()
		+ ntmtest_quat_fromMat3();
}

