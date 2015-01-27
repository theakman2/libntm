#ifndef TESTS_NTMTEST_MAT2_H_
#define TESTS_NTMTEST_MAT2_H_

	#ifdef __cplusplus
		extern "C" {
	#endif

		int ntmtest_mat2_identity(void);
		int ntmtest_mat2_copy(void);
		int ntmtest_mat2_clone(void);
		int ntmtest_mat2_transpose(void);
		int ntmtest_mat2_invert(void);
		int ntmtest_mat2_adjoint(void);
		int ntmtest_mat2_determinant(void);
		int ntmtest_mat2_multiply(void);
		int ntmtest_mat2_rotate(void);
		int ntmtest_mat2_scale(void);
		int ntmtest_mat2_fromRotation(void);
		int ntmtest_mat2_fromScaling(void);
		int ntmtest_mat2_frob(void);

		int ntmtest_mat2(void);

	#ifdef __cplusplus
		}
	#endif

#endif /* TESTS_NTMTEST_MAT2_H_ */
