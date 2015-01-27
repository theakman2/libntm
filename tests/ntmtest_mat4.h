#ifndef TESTS_NTMTEST_MAT4_H_
#define TESTS_NTMTEST_MAT4_H_

	#ifdef __cplusplus
		extern "C" {
	#endif
		
		int ntmtest_mat4_identity(void);
		int ntmtest_mat4_set(void);
		int ntmtest_mat4_copy(void);
		int ntmtest_mat4_transpose(void);
		int ntmtest_mat4_invert(void);
		int ntmtest_mat4_adjoint(void);
		int ntmtest_mat4_determinant(void);
		int ntmtest_mat4_multiply(void);
		int ntmtest_mat4_translate(void);
		int ntmtest_mat4_scale(void);
		int ntmtest_mat4_rotate(void);
		int ntmtest_mat4_rotateX(void);
		int ntmtest_mat4_rotateY(void);
		int ntmtest_mat4_rotateZ(void);
		int ntmtest_mat4_fromTranslation(void);
		int ntmtest_mat4_fromScaling(void);
		int ntmtest_mat4_fromRotation(void);
		int ntmtest_mat4_fromXRotation(void);
		int ntmtest_mat4_fromYRotation(void);
		int ntmtest_mat4_fromZRotation(void);
		int ntmtest_mat4_fromRotationTranslation(void);
		int ntmtest_mat4_fromQuat(void);
		int ntmtest_mat4_fromMat3(void);
		int ntmtest_mat4_frustum(void);
		int ntmtest_mat4_perspective(void);
		int ntmtest_mat4_ortho(void);
		int ntmtest_mat4_lookAt(void);
		int ntmtest_mat4_frob(void);
		
		int ntmtest_mat4(void);
		
	#ifdef __cplusplus
		}
	#endif
	
#endif /* TESTS_NTMTEST_MAT4_H_ */
