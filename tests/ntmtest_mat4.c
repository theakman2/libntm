#include <stdio.h>
#include <math.h>

#include "ntmtest_common.h"
#include "ntmtest_mat4.h"

#include "ntm.h"

int ntmtest_mat4_identity(void) {
	NtmMat4 a;
	ntm_mat4_identity(&a);
	
	NTMTEST_MAT4EQ(&a,
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	
	return 0;
}

int ntmtest_mat4_set(void) {
	NtmMat4 a;
	ntm_mat4_set(&a,
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	);
	
	NTMTEST_MAT4EQ(&a,
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	);
	
	return 0;
}

int ntmtest_mat4_copy(void) {
	NtmMat4 a, b;
	ntm_mat4_set(&a,
		1.0f, 2.0f, 3.0f, -4.0f,
		-5.0f, -6.0f, 7.0f, 8.0f,
		-9.0f, 10.0f, 11.0f, 12.0f,
		13.0f, -14.0f, 15.0f, 16.0f
	);
	
	ntm_mat4_copy(&b, &a);
	
	NTMTEST_ASSERT(&a != &b);
	NTMTEST_ASSERT(a.data != b.data);
	NTMTEST_MAT4EQ(&b,
		1.0f, 2.0f, 3.0f, -4.0f,
		-5.0f, -6.0f, 7.0f, 8.0f,
		-9.0f, 10.0f, 11.0f, 12.0f,
		13.0f, -14.0f, 15.0f, 16.0f
	);
	
	return 0;
}

int ntmtest_mat4_transpose(void) {
	NtmMat4 a, b;
	ntm_mat4_set(&a,
		1.0f, -2.0f, 3.0f, -4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 10.0f, 11.0f, -12.0f,
		-13.0f, -14.0f, 15.0f, 16.0f
	);
	
	ntm_mat4_transpose(&b, &a);
	
	NTMTEST_MAT4EQ(&b,
		1.0f, 5.0f, 9.0f, -13.0f,
		-2.0f, 6.0f, 10.0f, -14.0f,
		3.0f, 7.0f, 11.0f, 15.0f,
		-4.0f, 8.0f, -12.0f, 16.0f
	);
	
	return 0;
}

int ntmtest_mat4_invert(void) {
	NtmMat4 a;
	ntm_mat4_set(&a,
		1.0f, -2.0f, 3.0f, -4.0f,
		-5.0f, 6.0f, 7.0f, 8.0f,
		-9.0f, -10.0f, 11.0f, 12.0f,
		13.0f, -14.0f, 15.0f, -16.0f
	);
	
	ntm_mat4_invert(&a, &a);
	
	NTMTEST_MAT4EQ(&a,
		-0.436507936507937f, 0.028571428571429f, -0.033333333333333f, 0.098412698412698f,
		0.035714285714286f, 0.078571428571429f, -0.05f, -0.007142857142857f,
		0.047619047619048f, 0.071428571428571f, 0.0f, 0.023809523809524f,
		-0.341269841269841f, 0.021428571428571f, 0.016666666666667f, 0.046031746031746f
	);
	
	return 0;
}

int ntmtest_mat4_adjoint(void) {
	NtmMat4 a;
	ntm_mat4_set(&a,
		5.0f, 2.0f, -7.0f, 5.0f,
		1.0f, -4.0f, 7.0f, 4.0f,
		7.0f, 2.0f, 8.0f, 4.0f,
		2.0f, -6.0f, 5.0f, 2.0f
	);
	
	NTMTEST_MAT4EQ(ntm_mat4_adjoint(&a,&a),
		52.0f, -478.0f, 210.0f, 406.0f,
		-30.0f, 117.0f, 117.0f, -393.0f,
		-132.0f, 102.0f, 102.0f, -78.0f,
		188.0f, 574.0f, -114.0f, -358.0f
	);
	
	return 0;
}

int ntmtest_mat4_determinant(void) {
	NtmMat4 a;
	ntm_mat4_set(&a,
		-3.0f, 12.0f, 8.0f, -4.0f,
		0.0f, 15.0f, 5.0f, -5.0f,
		3.0f, 14.0f, 2.0f, -2.0f,
		6.0f, 11.0f, -1.0f, 1.0f
	);
	
	NTMTEST_EQF(ntm_mat4_determinant(&a), 120.0f);
	
	return 0;
}

int ntmtest_mat4_multiply(void) {
	NtmMat4 a, b;
	ntm_mat4_set(&a,
		1.0f, 5.0f, 9.5f, 13.0f,
		-2.0f, 6.0f, -10.0f, 14.0f,
		3.0f, 7.0f, -11.0f, -15.0f,
		4.0f, 8.0f, 12.0f, 16.0f
	);
	ntm_mat4_set(&b,
		14.0f, 10.0f, 6.5f, 2.0f,
		13.5f, 9.0f, 5.0f, 1.0f,
		12.0f, 8.0f, 4.0f, 0.0f,
		11.0f, 7.0f, 3.0f, -1.0f
	);
	
	ntm_mat4_multiply(&a, &a, &b);
	
	NTMTEST_MAT4EQ(&a,
		21.5f, 191.5f, -14.5f, 256.5f,
		14.5f, 164.5f, -4.75f, 242.5f,
		8.0f, 136.0f, -10.0f, 208.0f,
		2.0f, 110.0f, -10.5f, 180.0f
	);
	
	return 0;
}

int ntmtest_mat4_translate(void) {
	NtmMat4 a;
	NtmVec3 b;
	ntm_mat4_set(&a,
		1.5f, 2.0f, -2.5f, 3.0f,
		3.5f, -4.0f, 4.5f, 5.0f,
		-5.5f, 6.0f, 6.5f, 7.0f,
		7.5f, 8.0f, -8.5f, -9.0f
	);
	ntm_vec3_set(&b, 3.0f, -4.0f, -2.0f);
	
	ntm_mat4_translate(&a, &a, &b);
	
	NTMTEST_MAT4EQ(&a,
		1.5f, 2.0f, -2.5f, 3.0f,
		3.5f, -4.0f, 4.5f, 5.0f,
		-5.5f, 6.0f, 6.5f, 7.0f,
		9.0f, 18.0f, -47.0f, -34.0f
	);
	
	return 0;
}

int ntmtest_mat4_scale(void) {
	NtmMat4 a;
	NtmVec3 b;
	ntm_mat4_set(&a,
		3.0f, 7.0f, 9.0f, -5.0f,
		4.0f, 8.0f, -8.0f, 4.0f,
		-5.0f, 9.0f, 7.0f, 3.0f,
		6.0f, 0.0f, 6.0f, -2.0f
	);
	ntm_vec3_set(&b, 2.0f, 3.0f, 4.0f);
	
	ntm_mat4_scale(&a, &a, &b);
	
	NTMTEST_MAT4EQ(&a,
		6.0f, 14.0f, 18.0f, -10.0f,
		12.0f, 24.0f, -24.0f, 12.0f,
		-20.0f, 36.0f, 28.0f, 12.0f,
		6.0f, 0.0f, 6.0f, -2.0f
	);
	
	return 0;
}

int ntmtest_mat4_rotate(void) {
	NtmMat4 a;
	NtmVec3 b;
	ntm_mat4_set(&a,
		5.0f, 2.0f, -7.0f, 5.0f,
		1.0f, -4.0f, 7.0f, 4.0f,
		7.0f, 2.0f, 8.0f, 4.0f,
		2.0f, -6.0f, 5.0f, 2.0f
	);
	ntm_vec3_set(&b, 1.0f, 2.0f, 3.0f);
	
	NTMTEST_MAT4EQ(ntm_mat4_rotate(&a, &a, 1.0f, &b),
		1.1470885f, -2.5176767f, -1.6397512f, 4.4219706f,
		0.5799524f, -3.0607795f, 12.3398050f, 1.3291683f,
		8.5643355f, 2.8797453f, 2.6533804f, 5.9732309f,
		2.0f, -6.0f, 5.0f, 2.0f
	);
	
	return 0;
}

int ntmtest_mat4_rotateX(void) {
	NtmMat4 a;
	ntm_mat4_set(&a,
		1.0f, 1.25f, 1.5f, 1.75f,
		0.75f, 0.5f, 0.25f, 0.0f,
		-0.25f, -0.5f, -0.75f, -1.0f,
		1.5f, 2.5f, 3.5f, 5.0f
	);
	
	ntm_mat4_rotateX(&a, &a, 0.9f);
	
	NTMTEST_MAT4EQ(&a,
		1.0f, 1.25f, 1.5f, 1.75f,
		0.270376f, -0.080858f, -0.432093f, -0.783327f,
		-0.742898f, -0.702468f, -0.662039f, -0.62161f,
		1.5f, 2.5f, 3.5f, 5.0f
	);
	
	return 0;
}

int ntmtest_mat4_rotateY(void) {
	NtmMat4 a;
	ntm_mat4_set(&a,
		25.0f, 24.0f, 23.0f, -22.0f,
		21.0f, -20.0f, 19.0f, 18.0f,
		17.0f, -16.0f, 15.0f, 14.0f,
		13.0f, 12.0f, -11.0f, 10.0f
	);
	
	ntm_mat4_rotateY(&a, &a, 1.4f);
	
	NTMTEST_MAT4EQ(&a,
		-12.503467f, 19.846407f, -10.872502f, -17.535573f,
		21.0f, -20.f, 19.0f, 18.0f,
		27.525685f, 20.931319f, 25.214851f, -19.300354f,
		13.0f, 12.0f, -11.0f, 10.0f
	);
	
	return 0;
}

int ntmtest_mat4_rotateZ(void) {
	NtmMat4 a;
	ntm_mat4_set(&a,
		-19.0f, -17.0f, -15.0f, -13.0f,
		-11.0f, -9.0f, -7.0f, -5.0f,
		-3.0f, -1.0f, 1.0f, 3.0f,
		5.0f, 7.0f, 9.0f, 11.0f
	);
	
	ntm_mat4_rotateZ(&a, &a, 1.2f);
	
	NTMTEST_MAT4EQ(&a,
		-17.137227f, -14.548434f, -11.959640f, -9.370846f,
		13.722807f, 12.583445f, 11.444082f, 10.304719f,
		-3.0f, -1.0f, 1.0f, 3.0f,
		5.0f, 7.0f, 9.0f, 11.0f
	);
	
	return 0;
}

int ntmtest_mat4_fromTranslation(void) {
	NtmMat4 a;
	NtmVec3 b;
	ntm_vec3_set(&b, 4.5f, -3.5f, 6.0f);
	ntm_mat4_fromTranslation(&a, &b);
	
	NTMTEST_MAT4EQ(&a,
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		4.5f, -3.5f, 6.0f, 1.0f
	);
	
	return 0;
}

int ntmtest_mat4_fromScaling(void) {
	NtmMat4 a;
	NtmVec3 b;
	ntm_vec3_set(&b, 2.0f, 3.0f, 4.0f);
	
	ntm_mat4_fromScaling(&a, &b);
	
	NTMTEST_MAT4EQ(&a,
		2.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 3.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 4.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	
	return 0;
}

int ntmtest_mat4_fromRotation(void) {
	NtmMat4 a;
	NtmVec3 axis;
	ntm_vec3_set(&axis, 0.0f, 1.0f, 0.0f);

	ntm_mat4_fromRotation(&a, NTM_PI/2.0f, &axis);
	
	NTMTEST_MAT4EQ(&a,
		0.0f, 0.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);

	return 0;
}

int ntmtest_mat4_fromXRotation(void) {
	NtmMat4 a;
	
	ntm_mat4_fromXRotation(&a, 0.6f);
	
	NTMTEST_MAT4EQ(&a,
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.825335614f, 0.564642473f, 0.0f,
		0.0f, -0.564642473f, 0.825335614f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	
	return 0;
}

int ntmtest_mat4_fromYRotation(void) {
	NtmMat4 a;
		
	ntm_mat4_fromYRotation(&a, 1.1f);
	
	NTMTEST_MAT4EQ(&a,
		0.453596121f, 0.0f, -0.89120736f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.89120736f, 0.0f, 0.453596121f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	
	return 0;
}

int ntmtest_mat4_fromZRotation(void) {
	NtmMat4 a;
		
	ntm_mat4_fromZRotation(&a, 1.9f);
	
	NTMTEST_MAT4EQ(&a,
		-0.323289566f, 0.946300087f, 0.0f, 0.0f,
		-0.946300087f, -0.323289566f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	
	return 0;
}

int ntmtest_mat4_fromRotationTranslation(void) {
	NtmMat4 a;
	NtmVec3 b;
	NtmQuat c;
	ntm_quat_setAxisAngleF(&c, 2.0f, 3.0f, 4.0f, 0.8f);
	ntm_vec3_set(&b, -5.0f, 3.5f, 14.0f);
	
	ntm_mat4_fromRotationTranslation(&a, &c, &b);
	
	NTMTEST_MAT4EQ(&a,
		-6.582332f, 4.689184f, 0.274278f, 0.0f,
		-1.049665f, -5.065866f, 5.074232f, 0.0f,
		4.578415f, 2.204807f, -2.942813f, 0.0f,
		-5.0f, 3.5f, 14.0f, 1.0f
	);
	
	return 0;
}

int ntmtest_mat4_fromQuat(void) {
	NtmMat4 a;
	NtmQuat b;
	ntm_quat_setAxisAngleF(&b, 2.0f, 3.0f, 4.0f, 0.8f);
	
	ntm_mat4_fromQuat(&a, &b);
	
	NTMTEST_MAT4EQ(&a,
		-6.582332f, 4.689184f, 0.274278f, 0.0f,
		-1.049665f, -5.065866f, 5.074232f, 0.0f,
		4.578415f, 2.204807f, -2.942813f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	
	return 0;
}

int ntmtest_mat4_fromMat3(void) {
	NtmMat4 a;
	NtmMat3 b;
	ntm_mat3_set(&b,
		12.0f, 14.0f, -16.0f,
		-18.0f, 20.0f, 6.0f,
		4.0f, 2.0f, -0.5f
	);
	
	ntm_mat4_fromMat3(&a, &b);
	
	NTMTEST_MAT4EQ(&a,
		12.0f, 14.0f, -16.0f, 0.0f,
		-18.0f, 20.0f, 6.0f, 0.0f,
		4.0f, 2.0f, -0.5f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
	
	return 0;
}

int ntmtest_mat4_frustum(void) {
	NtmMat4 a;
	
	ntm_mat4_frustum(&a, 3.0f, 7.0f, 5.0f, 14.0f, 2.0f, 9.0f);
	
	NTMTEST_MAT4EQ(&a,
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.4444444f, 0.0f, 0.0f,
		2.5f, 2.1111111f, -1.57142857f, -1.0f,
		0.0f, 0.0f, -5.1428571f, 0.0f
	);
	
	return 0;
}

int ntmtest_mat4_perspective(void) {
	NtmMat4 a;
	
	ntm_mat4_perspective(&a, 1.0f, 1.5f, 0.5f, 500.0f);
	
	NTMTEST_MAT4EQ(&a,
		1.220325148f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.830487722f, 0.0f, 0.0f,
		0.0f, 0.0f, -1.002002f, -1.0f,
		0.0f, 0.0f, -1.001001f, 0.0f
	);
	
	return 0;
}

int ntmtest_mat4_ortho(void) {
	NtmMat4 a;
	
	ntm_mat4_ortho(&a, -25.0f, 25.0f, -15.0f, 15.0f, 0.5f, 500.0f);
	
	NTMTEST_MAT4EQ(&a,
		0.04f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.066666667f, 0.0f, 0.0f,
		0.0f, 0.0f, -0.004004004f, 0.0f,
		0.0f, 0.0f, -1.002002f, 1.0f
	);
	
	return 0;
}

int ntmtest_mat4_lookAt(void) {
	NtmMat4 a;
	NtmVec3 eye;
	NtmVec3 center;
	NtmVec3 up;

	ntm_vec3_set(&eye, 1.0f, 2.0f, 3.0f);
	ntm_vec3_set(&center, 5.0f, 2.0f, 3.0f);
	ntm_vec3_set(&up, 0.0f, 1.0f, 0.0f);

	ntm_mat4_lookAt(&a, &eye, &center, &up);
	
	NTMTEST_MAT4EQ(&a,
		0.0f, 0.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f, 0.0f,
		-3.0f, -2.0f, 1.0f, 1.0f
	);

	return 0;
}

int ntmtest_mat4_frob(void) {
	NtmMat4 a;
	ntm_mat4_set(&a,
		4.0f, 3.0f, 2.0f, 1.0f,
		0.0f, -1.0f, -2.0f, 3.0f,
		-4.0f, 5.0f, 6.0f, -5.0f,
		-3.0f, -1.0f, 2.0f, 3.0f
	);
	
	NTMTEST_EQF(ntm_mat4_frob(&a), 13.0f);
	
	return 0;
}

int ntmtest_mat4(void) {
	return
		ntmtest_mat4_identity()
		+ ntmtest_mat4_set()
		+ ntmtest_mat4_copy()
		+ ntmtest_mat4_transpose()
		+ ntmtest_mat4_invert()
		+ ntmtest_mat4_adjoint()
		+ ntmtest_mat4_determinant()
		+ ntmtest_mat4_multiply()
		+ ntmtest_mat4_translate()
		+ ntmtest_mat4_scale()
		+ ntmtest_mat4_rotate()
		+ ntmtest_mat4_rotateX()
		+ ntmtest_mat4_rotateY()
		+ ntmtest_mat4_rotateZ()
		+ ntmtest_mat4_fromTranslation()
		+ ntmtest_mat4_fromScaling()
		+ ntmtest_mat4_fromRotation()
		+ ntmtest_mat4_fromXRotation()
		+ ntmtest_mat4_fromYRotation()
		+ ntmtest_mat4_fromZRotation()
		+ ntmtest_mat4_fromRotationTranslation()
		+ ntmtest_mat4_fromQuat()
		+ ntmtest_mat4_fromMat3()
		+ ntmtest_mat4_frustum()
		+ ntmtest_mat4_perspective()
		+ ntmtest_mat4_ortho()
		+ ntmtest_mat4_lookAt()
		+ ntmtest_mat4_frob();
}
