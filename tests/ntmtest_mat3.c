#include <stdio.h>
#include <math.h>

#include "ntmtest_common.h"
#include "ntmtest_mat3.h"

#include "ntm.h"

int ntmtest_mat3_identity(void) {
	NtmMat3 a;
	
	ntm_mat3_identity(&a);
	
	NTMTEST_MAT3EQ(&a,
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f
	);
	
	return 0;
}

int ntmtest_mat3_set(void) {
	NtmMat3 a;
	ntm_mat3_set(&a,
		2.4f, 3.0f, 4.3f,
		5.1f, 6.7f, 7.9f,
		-8.5f, -9.2f, -6.6f
	);
	
	NTMTEST_MAT3EQ(&a,
		2.4f, 3.0f, 4.3f,
		5.1f, 6.7f, 7.9f,
		-8.5f, -9.2f, -6.6f
	);
	
	return 0;
}

int ntmtest_mat3_copy(void) {
	NtmMat3 a, b;
	ntm_mat3_set(&a,
		5.0f, 4.0f, 3.0f,
		2.0f, 1.0f, 0.0f,
		-1.0f, -2.0f, -3.0f
	);
	
	ntm_mat3_copy(&b, &a);
	
	NTMTEST_ASSERT(&a != &b);
	NTMTEST_ASSERT(a.data != b.data);
	NTMTEST_MAT3EQ(&b,
		5.0f, 4.0f, 3.0f,
		2.0f, 1.0f, 0.0f,
		-1.0f, -2.0f, -3.0f
	);
	
	return 0;
}

int ntmtest_mat3_fromMat4(void) {
	NtmMat3 a;
	NtmMat4 b;
	ntm_mat4_set(&b,
		2.0f, 3.0f, 5.0f, -1.9f,
		-2.0f, -2.3f, -34.3f, -0.3f,
		14.3f, -3.9f, 2.2f, -4.5f,
		9.3f, 1.2f, 0.1f, 0.7f
	);
	ntm_mat3_fromMat4(&a, &b);
	
	NTMTEST_MAT3EQ(&a,
		2.0f, 3.0f, 5.0f,
		-2.0f, -2.3f, -34.3f,
		14.3f, -3.9f, 2.2f
	);
	
	return 0;
}

int ntmtest_mat3_transpose(void) {
	NtmMat3 a;
	ntm_mat3_set(&a,
		5.0f, 1.5f, 3.8f,
		-2.5f, -6.2f, 2.7f,
		4.1f, 5.2f, -1.4f
	);
	
	ntm_mat3_transpose(&a, &a);
	
	NTMTEST_MAT3EQ(&a,
		5.0f, -2.5f, 4.1f,
		1.5f, -6.2f, 5.2f,
		3.8f, 2.7f, -1.4f
	);
	
	return 0;
}

int ntmtest_mat3_invert(void) {
	NtmMat3 a;
	ntm_mat3_set(&a,
		2.3f, -5.1f, 1.0f,
		-14.23f, 1.5f, 4.9f,
		2.2f, -9.04f, 4.0f
	);
	
	ntm_mat3_invert(&a, &a);
	
	NTMTEST_MAT3EQ(&a,
		-0.482455635491607f, -0.108968824940048f, 0.254100719424460f,
		-0.649400479616307f, -0.067146282973621f, 0.244604316546763f,
		-1.202294484412470f, -0.091817745803357f, 0.663050359712230f
	);
	
	return 0;
}

int ntmtest_mat3_adjoint(void) {
	NtmMat3 a, b;
	ntm_mat3_set(&a,
		-3.5f, 2.5f, -12.1f,
		2.1f, 4.4f, 18.7f,
		3.3f, -4.4f, 2.0f
	);
	
	ntm_mat3_adjoint(&b, &a);
	
	NTMTEST_MAT3EQ(&b,
		91.08f, 48.24f, 99.99f,
		57.51f, 32.93f, 40.04f,
		-23.76f, -7.15f, -20.65f
	);
	
	return 0;
}

int ntmtest_mat3_determinant(void) {
	NtmMat3 a;
	ntm_mat3_set(&a,
		5.0f, 6.7f, -7.1f,
		-8.0f, 9.2f, -10.5f,
		11.8f, -12.4f, 13.0f
	);
	
	NTMTEST_EQF(ntm_mat3_determinant(&a), -119.874f);
	
	return 0;
}

int ntmtest_mat3_multiply(void) {
	NtmMat3 a, b;
	ntm_mat3_set(&a,
		-43.125f, 9.0f, 0.5f,
		-3.0f, 18429.75f, 34.0f,
		-13.0f, 0.5f, 1.5f
	);
	ntm_mat3_set(&b,
		-28538.5f, 385.5f, -188.25f,
		40.25f, -0.5f, 1.25f,
		-495.75f, 8.25f, 4.0f
	);
	
	ntm_mat3_multiply(&b, &a, &b);
	
	NTMTEST_MAT3EQ(&b,
		1232013.5625f, 6847728.0f, -1444.625f,
		-1750.53125f, -8852.0f, 5.0f,
		21302.46875f, 147585.6875f, 38.625f
	);
	
	return 0;
}

int ntmtest_mat3_translate(void) {
	NtmVec2 b;
	NtmMat3 a;
	ntm_mat3_set(&a,
		-5.9f, -3.4f, -1.0f,
		1.0f, 3.1f, 5.8f,
		7.6f, 9.3f, 11.0f
	);
	ntm_vec2_set(&b, 7.0f, -4.0f);
	
	ntm_mat3_translate(&a, &a, &b);
	
	NTMTEST_MAT3EQ(&a,
		-5.9f, -3.4f, -1.0f,
		1.0f, 3.1f, 5.8f,
		-37.7f, -26.9f, -19.2f
	);
	
	return 0;
}

int ntmtest_mat3_rotate(void) {
	NtmMat3 a;
	ntm_mat3_set(&a,
		1.0f, 4.0f, -11.5f,
		-1.5f, 6.0f, -15.0f,
		2.5f, 8.5f, 19.0f
	);
	
	ntm_mat3_rotate(&a, &a, 1.1f);
	
	NTMTEST_MAT3EQ(&a,
		-0.883215f, 7.161629f, -18.584466f,
		-1.571602f, -0.843253f, 3.444943f,
		2.5f, 8.5f, 19.0f
	);
	
	return 0;
}

int ntmtest_mat3_scale(void) {
	NtmVec2 b;
	NtmMat3 a;
	ntm_mat3_set(&a,
		9.0f, 5.0f, 1.0f,
		-3.0f, -7.0f, -11.0f,
		-15.0f, -19.0f, -23.0f
	);
	ntm_vec2_set(&b, -2.0f, 3.0f);
	
	ntm_mat3_scale(&a, &a, &b);
	
	NTMTEST_MAT3EQ(&a,
		-18.0f, -10.0f, -2.0f,
		-9.0f, -21.0f, -33.0f,
		-15.0f, -19.0f, -23.0f
	);
	
	return 0;
}

int ntmtest_mat3_fromTranslation(void) {
	NtmVec2 b;
	NtmMat3 a;
	ntm_vec2_set(&b, 5.5f, -3.0f);
	
	ntm_mat3_fromTranslation(&a, &b);
	
	NTMTEST_MAT3EQ(&a,
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		5.5f, -3.0f, 1.0f
	);
	
	return 0;
}

int ntmtest_mat3_fromRotation(void) {
	NtmMat3 a;
	
	ntm_mat3_fromRotation(&a, 0.6f);
	
	NTMTEST_MAT3EQ(&a,
		0.825335614f, 0.564642473f, 0.0f,
		-0.564642473f, 0.825335614f, 0.0f,
		0.0f, 0.0f, 1.0f
	);
	
	return 0;
}

int ntmtest_mat3_fromScaling(void) {
	NtmVec2 b;
	NtmMat3 a;
	ntm_vec2_set(&b, 4.0f, 9.0f);
	
	ntm_mat3_fromScaling(&a, &b);
	
	NTMTEST_MAT3EQ(&a,
		4.0f, 0.0f, 0.0f,
		0.0f, 9.0f, 0.0f,
		0.0f, 0.0f, 1.0f
	);
	
	return 0;
}

int ntmtest_mat3_fromMat2d(void) {
	NtmMat2d b;
	NtmMat3 a;
	ntm_mat2d_set(&b,
		0.3f, 1.6f,
		3.7f, -4.0f,
		0.4f, 1.1f 
	);
	
	ntm_mat3_fromMat2d(&a, &b);
	
	NTMTEST_MAT3EQ(&a,
		0.3f, 1.6f, 0.0f,
		3.7f, -4.0f, 0.0f,
		0.4f, 1.1f, 1.0f
	);
	
	return 0;
}

int ntmtest_mat3_fromQuat(void) {
	NtmMat3 a;
	NtmQuat b;
	ntm_quat_setAxisAngleF(&b, 2.0f, 3.0f, 4.0f, 0.8f);
	
	ntm_mat3_fromQuat(&a, &b);
	
	NTMTEST_MAT3EQ(&a,
		-6.582332f, 4.689184f, 0.274278f,
		-1.049665f, -5.065866f, 5.074232f,
		4.578415f, 2.204807f, -2.942813f
	);
	
	return 0;
}

int ntmtest_mat3_normalFromMat4(void) {
	NtmMat3 a;
	NtmMat4 b;
	ntm_mat4_set(&b,
		1.0f, -2.0f, 7.0f, 0.0f,
		-5.0f, -4.0f, 3.0f, 0.0f,
		-2.0f, 3.0f, 9.0f, 0.0f,
		4.0f, 1.0f, 4.0f, 1.0f
	);
	
	ntm_mat3_normalFromMat4(&a, &b);
	
	NTMTEST_MAT3EQ(&a,
		0.15845070422535212f, -0.13732394366197184f, 0.08098591549295775f,
		-0.13732394366197184f, -0.08098591549295775f, -0.0035211267605633804f,
		-0.07746478873239437f, 0.13380281690140847f, 0.04929577464788733f
	);
	
	return 0;
}

int ntmtest_mat3_frob(void) {
	NtmMat3 a;
	ntm_mat3_set(&a,
		1.0f, 2.0f, 3.0f,
		4.0f, 3.0f, 2.0f,
		1.0f, -3.0f, -5.0f
	);
	
	NTMTEST_EQF(ntm_mat3_frob(&a), 8.831760866f);
	
	return 0;
}

int ntmtest_mat3(void) {
	return
		ntmtest_mat3_identity()
		+ ntmtest_mat3_set()
		+ ntmtest_mat3_copy()
		+ ntmtest_mat3_fromMat4()
		+ ntmtest_mat3_transpose()
		+ ntmtest_mat3_invert()
		+ ntmtest_mat3_adjoint()
		+ ntmtest_mat3_determinant()
		+ ntmtest_mat3_multiply()
		+ ntmtest_mat3_translate()
		+ ntmtest_mat3_rotate()
		+ ntmtest_mat3_scale()
		+ ntmtest_mat3_fromTranslation()
		+ ntmtest_mat3_fromRotation()
		+ ntmtest_mat3_fromScaling()
		+ ntmtest_mat3_fromMat2d()
		+ ntmtest_mat3_fromQuat()
		+ ntmtest_mat3_normalFromMat4()
		+ ntmtest_mat3_frob();
}
