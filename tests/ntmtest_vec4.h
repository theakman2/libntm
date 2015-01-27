#ifndef TESTS_NTMTEST_VEC4_H_
#define TESTS_NTMTEST_VEC4_H_

	#ifdef __cplusplus
		extern "C" {
	#endif
		
		int ntmtest_vec4_copy(void);
		int ntmtest_vec4_set(void);
		int ntmtest_vec4_add(void);
		int ntmtest_vec4_subtract(void);
		int ntmtest_vec4_multiply(void);
		int ntmtest_vec4_divide(void);
		int ntmtest_vec4_min(void);
		int ntmtest_vec4_max(void);
		int ntmtest_vec4_scale(void);
		int ntmtest_vec4_scaleAndAdd(void);
		int ntmtest_vec4_distance(void);
		int ntmtest_vec4_squaredDistance(void);
		int ntmtest_vec4_length(void);
		int ntmtest_vec4_squaredLength(void);
		int ntmtest_vec4_negate(void);
		int ntmtest_vec4_inverse(void);
		int ntmtest_vec4_normalize(void);
		int ntmtest_vec4_dot(void);
		int ntmtest_vec4_lerp(void);
		int ntmtest_vec4_random(void);
		int ntmtest_vec4_transformMat4(void);
		int ntmtest_vec4_transformQuat(void);
		
		int ntmtest_vec4(void);
		
	#ifdef __cplusplus
		}
	#endif

#endif /* TESTS_NTMTEST_VEC4_H_ */
