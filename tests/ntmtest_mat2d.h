#ifndef TESTS_NTMTEST_MAT2D_H_
#define TESTS_NTMTEST_MAT2D_H_

	#ifdef __cplusplus
		extern "C" {
	#endif
		
		int ntmtest_mat2d_identity(void);
		int ntmtest_mat2d_copy(void);
		int ntmtest_mat2d_invert(void);
		int ntmtest_mat2d_determinant(void);
		int ntmtest_mat2d_multiply(void);
		int ntmtest_mat2d_rotate(void);
		int ntmtest_mat2d_scale(void);
		int ntmtest_mat2d_translate(void);
		int ntmtest_mat2d_fromRotation(void);
		int ntmtest_mat2d_fromScaling(void);
		int ntmtest_mat2d_fromTranslation(void);
		int ntmtest_mat2d_frob(void);
		
		int ntmtest_mat2d(void);
		
	#ifdef __cplusplus
		}
	#endif

#endif /* TESTS_NTMTEST_MAT2D_H_ */
