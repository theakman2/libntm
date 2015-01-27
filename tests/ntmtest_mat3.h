#ifndef TESTS_NTMTEST_MAT3_H_
#define TESTS_NTMTEST_MAT3_H_

	#ifdef __cplusplus
		extern "C" {
	#endif
		
		int ntmtest_mat3_identity(void);
		int ntmtest_mat3_set(void);
		int ntmtest_mat3_copy(void);
		int ntmtest_mat3_fromMat4(void);
		int ntmtest_mat3_transpose(void);
		int ntmtest_mat3_invert(void);
		int ntmtest_mat3_adjoint(void);
		int ntmtest_mat3_determinant(void);
		int ntmtest_mat3_multiply(void);
		int ntmtest_mat3_translate(void);
		int ntmtest_mat3_rotate(void);
		int ntmtest_mat3_scale(void);
		int ntmtest_mat3_fromTranslation(void);
		int ntmtest_mat3_fromRotation(void);
		int ntmtest_mat3_fromScaling(void);
		int ntmtest_mat3_fromMat2d(void);
		int ntmtest_mat3_fromQuat(void);
		int ntmtest_mat3_normalFromMat4(void);
		int ntmtest_mat3_frob(void);
		
		int ntmtest_mat3(void);
		
	#ifdef __cplusplus
		}
	#endif

#endif /* TESTS_NTMTEST_MAT3_H_ */
