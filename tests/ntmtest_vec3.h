#ifndef TESTS_NTMTEST_VEC3_H_
#define TESTS_NTMTEST_VEC3_H_

	#ifdef __cplusplus
		extern "C" {
	#endif

		int ntmtest_vec3_copy(void);
		int ntmtest_vec3_set(void);
		int ntmtest_vec3_add(void);
		int ntmtest_vec3_subtract(void);
		int ntmtest_vec3_multiply(void);
		int ntmtest_vec3_divide(void);
		int ntmtest_vec3_min(void);
		int ntmtest_vec3_max(void);
		int ntmtest_vec3_scale(void);
		int ntmtest_vec3_scaleAndAdd(void);
		int ntmtest_vec3_distance(void);
		int ntmtest_vec3_squaredDistance(void);
		int ntmtest_vec3_length(void);
		int ntmtest_vec3_squaredLength(void);
		int ntmtest_vec3_negate(void);
		int ntmtest_vec3_inverse(void);
		int ntmtest_vec3_normalize(void);
		int ntmtest_vec3_dot(void);
		int ntmtest_vec3_cross(void);
		int ntmtest_vec3_lerp(void);
		int ntmtest_vec3_random(void);
		int ntmtest_vec3_transformMat4(void);
		int ntmtest_vec3_transformMat3(void);
		int ntmtest_vec3_transformQuat(void);
		int ntmtest_vec3_rotateX(void);
		int ntmtest_vec3_rotateY(void);
		int ntmtest_vec3_rotateZ(void);

		int ntmtest_vec3(void);

	#ifdef __cplusplus
		}
	#endif

#endif /* TESTS_NTMTEST_VEC3_H_ */
