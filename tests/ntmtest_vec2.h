#ifndef TESTS_NTMTEST_VEC2_H_
#define TESTS_NTMTEST_VEC2_H_

	#ifdef __cplusplus
		extern "C" {
	#endif

		int ntmtest_vec2_copy(void);
		int ntmtest_vec2_set(void);
		int ntmtest_vec2_add(void);
		int ntmtest_vec2_subtract(void);
		int ntmtest_vec2_multiply(void);
		int ntmtest_vec2_divide(void);
		int ntmtest_vec2_min(void);
		int ntmtest_vec2_max(void);
		int ntmtest_vec2_scale(void);
		int ntmtest_vec2_scaleAndAdd(void);
		int ntmtest_vec2_distance(void);
		int ntmtest_vec2_squaredDistance(void);
		int ntmtest_vec2_length(void);
		int ntmtest_vec2_squaredLength(void);
		int ntmtest_vec2_negate(void);
		int ntmtest_vec2_inverse(void);
		int ntmtest_vec2_normalize(void);
		int ntmtest_vec2_dot(void);
		int ntmtest_vec2_cross(void);
		int ntmtest_vec2_lerp(void);
		int ntmtest_vec2_random(void);
		int ntmtest_vec2_transformMat2(void);
		int ntmtest_vec2_transformMat2d(void);
		int ntmtest_vec2_transformMat3(void);
		int ntmtest_vec2_transformMat4(void);

		int ntmtest_vec2(void);

	#ifdef __cplusplus
		}
	#endif

#endif /* TESTS_NTMTEST_VEC2_H_ */
