#ifndef TESTS_NTMTEST_QUAT_H_
#define TESTS_NTMTEST_QUAT_H_

	#ifdef __cplusplus
		extern "C" {
	#endif
		
		int ntmtest_quat_identity(void);
		int ntmtest_quat_copy(void);
		int ntmtest_quat_set(void);
		int ntmtest_quat_rotationTo(void);
		int ntmtest_quat_setAxes(void);
		int ntmtest_quat_setAxisAngle(void);
		int ntmtest_quat_fromAxisAngle(void);
		int ntmtest_quat_setAxisAngleF(void);
		int ntmtest_quat_fromAxisAngleF(void);
		int ntmtest_quat_add(void);
		int ntmtest_quat_multiply(void);
		int ntmtest_quat_scale(void);
		int ntmtest_quat_rotateX(void);
		int ntmtest_quat_rotateY(void);
		int ntmtest_quat_rotateZ(void);
		int ntmtest_quat_calculateW(void);
		int ntmtest_quat_dot(void);
		int ntmtest_quat_lerp(void);
		int ntmtest_quat_slerp(void);
		int ntmtest_quat_invert(void);
		int ntmtest_quat_conjugate(void);
		int ntmtest_quat_length(void);
		int ntmtest_quat_squaredLength(void);
		int ntmtest_quat_normalize(void);
		int ntmtest_quat_fromMat3(void);
		
		int ntmtest_quat(void);
		
	#ifdef __cplusplus
		}
	#endif

#endif /* TESTS_NTMTEST_QUAT_H_ */
