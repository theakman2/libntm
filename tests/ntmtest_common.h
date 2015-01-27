#ifndef TESTS_NTMTEST_COMMON_H_
#define TESTS_NTMTEST_COMMON_H_
	
	#include "ntm_common.h"

	#define NTMTEST_EPSILON 0.0001

	int ntmtest_assert(int got, int line, char *filepath);
	int ntmtest_eqf(float got, float expected, int line, char *filepath);
	int ntmtest_vec2Eq(
		NtmVec2 *got,
		float a0,
		float a1,
		int line,
		char *filepath
	);
	int ntmtest_vec3Eq(
		NtmVec3 *got,
		float a0,
		float a1,
		float a2,
		int line,
		char *filepath
	);
	int ntmtest_vec4Eq(
		NtmVec4 *got,
		float a0,
		float a1,
		float a2,
		float a3,
		int line,
		char *filepath
	);
	int ntmtest_quatEq(
		NtmQuat *got,
		float a0,
		float a1,
		float a2,
		float a3,
		int line,
		char *filepath
	);
	int ntmtest_mat2Eq(
		NtmMat2 *got,
		float a0,
		float a1,
		float a2,
		float a3,
		int line,
		char *filepath
	);
	int ntmtest_mat2dEq(
		NtmMat2d *got,
		float a0,
		float a1,
		float a2,
		float a3,
		float a4,
		float a5,
		int line,
		char *filepath
	);
	int ntmtest_mat3Eq(
		NtmMat3 *got,
		float a0,
		float a1,
		float a2,
		float a3,
		float a4,
		float a5,
		float a6,
		float a7,
		float a8,
		int line,
		char *filepath
	);
	int ntmtest_mat4Eq(
		NtmMat4 *got,
		float a0,
		float a1,
		float a2,
		float a3,
		float a4,
		float a5,
		float a6,
		float a7,
		float a8,
		float a9,
		float a10,
		float a11,
		float a12,
		float a13,
		float a14,
		float a15,
		int line,
		char *filepath
	);

	#define NTMTEST_ASSERT(a) \
		do {\
			if (ntmtest_assert(a, __LINE__, __FILE__)) {\
				return 1;\
			}\
		} while((void)0,0)

	#define NTMTEST_EQF(a,b) \
		do {\
			if (ntmtest_eqf(a, b, __LINE__, __FILE__)) {\
				return 1;\
			}\
		} while((void)0,0)

	#define NTMTEST_VEC2EQ(got,a,b) \
		do {\
			if (ntmtest_vec2Eq(got, a, b, __LINE__, __FILE__)) {\
				return 1;\
			}\
		} while((void)0,0)

	#define NTMTEST_VEC3EQ(got,a,b,c) \
		do {\
			if (ntmtest_vec3Eq(got, a, b, c, __LINE__, __FILE__)) {\
				return 1;\
			}\
		} while((void)0,0)

	#define NTMTEST_VEC4EQ(got,a,b,c,d) \
		do {\
			if (ntmtest_vec4Eq(got, a, b, c, d, __LINE__, __FILE__)) {\
				return 1;\
			}\
		} while((void)0,0)

	#define NTMTEST_QUATEQ(got,a,b,c,d) \
		do {\
			if (ntmtest_quatEq(got, a, b, c, d, __LINE__, __FILE__)) {\
				return 1;\
			}\
		} while((void)0,0)

	#define NTMTEST_MAT2EQ(got,a,b,c,d) \
		do {\
			if (ntmtest_mat2Eq(got, a, b, c, d, __LINE__, __FILE__)) {\
				return 1;\
			}\
		} while((void)0,0)

	#define NTMTEST_MAT2DEQ(got,a,b,c,d,e,f) \
		do {\
			if (ntmtest_mat2dEq(got, a, b, c, d, e, f, __LINE__, __FILE__)) {\
				return 1;\
			}\
		} while((void)0,0)

	#define NTMTEST_MAT3EQ(got,a,b,c,d,e,f,g,h,i) \
		do {\
			if (ntmtest_mat3Eq(got, a, b, c, d, e, f, g, h, i, __LINE__, __FILE__)) {\
				return 1;\
			}\
		} while((void)0,0)

	#define NTMTEST_MAT4EQ(got,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p) \
		do {\
			if (ntmtest_mat4Eq(got, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, __LINE__, __FILE__)) {\
				return 1;\
			}\
		} while((void)0,0)

#endif /* TESTS_NTMTEST_COMMON_H_ */
