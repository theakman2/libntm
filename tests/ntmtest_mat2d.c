#include <stdio.h>
#include <math.h>

#include "ntmtest_common.h"
#include "ntmtest_mat2d.h"

#include "ntm.h"

int ntmtest_mat2d_identity(void) {
	NtmMat2d a;
	
	NTMTEST_MAT2DEQ(ntm_mat2d_identity(&a),
		1.0f, 0.0f,
		0.0f, 1.0f,
		0.0f, 0.0f
	);
	
	return 0;
}

int ntmtest_mat2d_copy(void) {
	NtmMat2d a, b;
	ntm_mat2d_set(&a,
		1.5f, 1.9f,
		-2.4f, 4.12f,
		2.11f, 4.9f
	);
	
	ntm_mat2d_copy(&b, &a);
	
	NTMTEST_ASSERT(&a != &b);
	NTMTEST_ASSERT(a.data != b.data);
	NTMTEST_MAT2DEQ(&b,
		1.5f, 1.9f,
		-2.4f, 4.12f,
		2.11f, 4.9f
	);
	
	return 0;
}

int ntmtest_mat2d_invert(void) {
	NtmMat2d a, b;
	ntm_mat2d_set(&a,
		-4.9f, 6.1f,
		12.4f, 4.8f,
		-3.12f, -2.9f
	);
	
	ntm_mat2d_invert(&b, &a);
	
	NTMTEST_MAT2DEQ(&b,
		-0.048406615570795f, 0.061516740621218f,
		0.125050423557886f, 0.049415086728520f,
		0.211617587736991f, 0.335235982250908f
	);
	
	ntm_mat2d_set(&a, 2.0f, 3.0f, 2.0f, 3.0f, 0.0f, 1.5f);
	
	NTMTEST_ASSERT(ntm_mat2d_invert(&a, &a) == NULL);
	
	return 0;
}

int ntmtest_mat2d_determinant(void) {
	NtmMat2d a;
	ntm_mat2d_set(&a,
		4.5f, 5.3f,
		2.2f, -2.9f,
		-1.5f, -5.1f
	);
	
	NTMTEST_EQF(ntm_mat2d_determinant(&a), -24.71f);
	
	return 0;
}

int ntmtest_mat2d_multiply(void) {
	NtmMat2d a, b;
	ntm_mat2d_set(&a,
		2.1f, 3.6f,
		-4.9f, 5.3f,
		6.2f, 7.8f
	);
	ntm_mat2d_set(&b,
		2.0f, 3.0f,
		4.0f, -3.0f,
		-1.0f, -2.0f
	);
	
	NTMTEST_MAT2DEQ(ntm_mat2d_multiply(&a, &a, &b),
		-10.5f, 23.1f,
		23.1f, -1.5f,
		13.9f, -6.4f
	);
	
	return 0;
}

int ntmtest_mat2d_rotate(void) {
	NtmMat2d a;
	ntm_mat2d_set(&a,
		4.0f, 1.5f,
		-3.2f, 2.7f,
		-3.1f, 0.4f
	);
	
	NTMTEST_MAT2DEQ(ntm_mat2d_rotate(&a, &a, 1.2f),
		-1.53309406f, 3.06004216f,
		-4.88770116f, -0.41969269f,
		-3.1f, 0.4f
	);
	
	return 0;
}

int ntmtest_mat2d_scale(void) {
	NtmVec2 v;
	NtmMat2d a;
	ntm_mat2d_set(&a,
		2.5f, 2.7f,
		-4.2f, 1.0f,
		-5.3f, 1.9f
	);
	ntm_vec2_set(&v, 2.0f, 4.0f);
	
	ntm_mat2d_scale(&a, &a, &v);
	
	NTMTEST_MAT2DEQ(&a,
		5.0f, 5.4f,
		-16.8f, 4.0f,
		-5.3f, 1.9f
	);
	
	return 0;
}

int ntmtest_mat2d_translate(void) {
	NtmVec2 v;
	NtmMat2d a;
	ntm_mat2d_set(&a,
		2.0f, -4.0f,
		3.0f, 6.6f,
		4.5f, 5.0f
	);
	ntm_vec2_set(&v, 6.0f, -3.0f);
	
	ntm_mat2d_translate(&a, &a, &v);
	
	NTMTEST_MAT2DEQ(&a,
		2.0f, -4.0f,
		3.0f, 6.6f,
		7.5f, -38.8f
	);
	
	return 0;
}

int ntmtest_mat2d_fromRotation(void) {
	NtmMat2d a;
	
	NTMTEST_MAT2DEQ(ntm_mat2d_fromRotation(&a, 1.0f),
		0.540302305f, 0.841470984f,
		-0.841470984f, 0.540302305f,
		0.0f, 0.0f
	);
	
	return 0;
}

int ntmtest_mat2d_fromScaling(void) {
	NtmVec2 v;
	NtmMat2d a;
	ntm_vec2_set(&v, 2.0f, -3.0f);
	ntm_mat2d_fromScaling(&a, &v);
	
	NTMTEST_MAT2DEQ(&a,
		2.0f, 0.0f,
		0.0f, -3.0f,
		0.0f, 0.0f
	);
	
	return 0;
}

int ntmtest_mat2d_fromTranslation(void) {
	NtmVec2 v;
	NtmMat2d a;
	ntm_vec2_set(&v, 4.0f, 7.0f);
	ntm_mat2d_fromTranslation(&a, &v);
	
	NTMTEST_MAT2DEQ(&a,
		1.0f, 0.0f,
		0.0f, 1.0f,
		4.0f, 7.0f
	);
	
	return 0;
}

int ntmtest_mat2d_frob(void) {
	NtmMat2d a;
	ntm_mat2d_set(&a,
		-1.5f, 2.4f,
		2.9f, -4.3f,
		3.3f, 3.9f
	);
	
	NTMTEST_EQF(ntm_mat2d_frob(&a), 7.874642849f);
	
	return 0;
}

int ntmtest_mat2d(void) {
	return
		ntmtest_mat2d_identity()
		+ ntmtest_mat2d_copy()
		+ ntmtest_mat2d_invert()
		+ ntmtest_mat2d_determinant()
		+ ntmtest_mat2d_multiply()
		+ ntmtest_mat2d_rotate()
		+ ntmtest_mat2d_scale()
		+ ntmtest_mat2d_translate()
		+ ntmtest_mat2d_fromRotation()
		+ ntmtest_mat2d_fromScaling()
		+ ntmtest_mat2d_fromTranslation()
		+ ntmtest_mat2d_frob();
}

