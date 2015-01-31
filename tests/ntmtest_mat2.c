#include <stdio.h>
#include <math.h>

#include "ntmtest_common.h"
#include "ntmtest_mat2.h"

#include "ntm.h"

int ntmtest_mat2_identity(void) {
	NtmMat2 a;

	NTMTEST_MAT2EQ(ntm_mat2_identity(&a), 1.0f, 0.0f, 0.0f, 1.0f);

	return 0;
}

int ntmtest_mat2_copy(void) {
	NtmMat2 a, b;
	ntm_mat2_set(&b, 0.5f, 1.5f, 4.5f, 3.0f);

	ntm_mat2_copy(&a, &b);

	NTMTEST_MAT2EQ(&a, 0.5f, 1.5f, 4.5f, 3.0f);

	return 0;
}

int ntmtest_mat2_transpose(void) {
	NtmMat2 a, b;
	ntm_mat2_set(&b, 3.5f, 4.5f, 23.0f, 33.5f);

	ntm_mat2_transpose(&b, &b);
	
	NTMTEST_MAT2EQ(&b, 3.5f, 23.0f, 4.5f, 33.5f);

	ntm_mat2_transpose(&a, &b);
	
	NTMTEST_MAT2EQ(&a, 3.5f, 4.5f, 23.0f, 33.5f);

	return 0;
}

int ntmtest_mat2_invert(void) {
	NtmMat2 a;
	ntm_mat2_set(&a, 2.0f, 4.0f, 3.0f, 8.0f);

	ntm_mat2_invert(&a, &a);
	
	NTMTEST_MAT2EQ(&a, 2.0f, -1.0f, -0.75f, 0.5f);
	
	ntm_mat2_set(&a, 2.0f, 3.0f, 2.0f, 3.0f);
	
	NTMTEST_ASSERT(ntm_mat2_invert(&a, &a) == NULL);
	
	return 0;
}

int ntmtest_mat2_adjoint(void) {
	NtmMat2 a;
	ntm_mat2_set(&a, 2.0f, 4.0f, 3.0f, 8.0f);

	ntm_mat2_adjoint(&a, &a);
	
	NTMTEST_MAT2EQ(&a, 8.0f, -4.0f, -3.0f, 2.0f);

	return 0;
}

int ntmtest_mat2_determinant(void) {
	NtmMat2 a;
	ntm_mat2_set(&a, 2.0f, 4.0f, 3.0f, 8.0f);
	
	NTMTEST_EQF(ntm_mat2_determinant(&a), 4.0f);

	return 0;
}

int ntmtest_mat2_multiply(void) {
	NtmMat2 a, b;
	ntm_mat2_set(&a, 2.0f, 4.0f, 3.0f, 8.0f);
	ntm_mat2_set(&b, 3.0f, -2.0f, -1.0f, 4.0f);

	ntm_mat2_multiply(&a, &a, &b);
	
	NTMTEST_MAT2EQ(&a, 0.0f, -4.0f, 10.0f, 28.0f);

	return 0;
}

int ntmtest_mat2_rotate(void) {
	NtmMat2 a;
	ntm_mat2_set(&a, 1.5f, 2.5f, 3.5f, 4.5f);

	ntm_mat2_rotate(&a, &a, NTM_PI / 6.0f);
	
	NTMTEST_MAT2EQ(&a,
		3.049038106f, 4.415063509f,
		2.281088913f, 2.647114317f
	);

	return 0;
}

int ntmtest_mat2_scale(void) {
	NtmMat2 a;
	NtmVec2 b;
	ntm_mat2_set(&a, -4.0f, 0.5f, 1324.0f, -451.0f);
	ntm_vec2_set(&b, 2.0f, 3.0f);

	ntm_mat2_scale(&a, &a, &b);
	
	NTMTEST_MAT2EQ(&a, -8.0f, 1.0f, 3972.0f, -1353.0f);

	return 0;
}

int ntmtest_mat2_fromRotation(void) {
	NtmMat2 mat;

	NTMTEST_MAT2EQ(ntm_mat2_fromRotation(&mat, NTM_PI / 3.0f),
		0.5f, 0.866025403f,
		-0.866025403f, 0.5f
	);

	return 0;
}

int ntmtest_mat2_fromScaling(void) {
	NtmVec2 vec;
	NtmMat2 mat;
	ntm_vec2_set(&vec, 4.0f, 6.0f);

	NTMTEST_MAT2EQ(ntm_mat2_fromScaling(&mat, &vec),
		4.0f, 0.0f,
		0.0f, 6.0f
	);

	return 0;
}

int ntmtest_mat2_frob(void) {
	NtmMat2 mat;
	ntm_mat2_set(&mat, 2.0f, 6.0f, -3.0f, 4.5f);
	
	NTMTEST_EQF(ntm_mat2_frob(&mat), 8.32165848854662f);

	return 0;
}

int ntmtest_mat2(void) {
	return
		ntmtest_mat2_identity()
		+ ntmtest_mat2_copy()
		+ ntmtest_mat2_transpose()
		+ ntmtest_mat2_invert()
		+ ntmtest_mat2_adjoint()
		+ ntmtest_mat2_determinant()
		+ ntmtest_mat2_multiply()
		+ ntmtest_mat2_rotate()
		+ ntmtest_mat2_scale()
		+ ntmtest_mat2_fromRotation()
		+ ntmtest_mat2_fromScaling()
		+ ntmtest_mat2_frob();
}
