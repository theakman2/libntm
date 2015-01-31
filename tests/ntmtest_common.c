#include <math.h>
#include <stdio.h>

#include "ntmtest_common.h"

int ntmtest_assert(int got, int line, const char *filepath) {
	if (got) {
		printf("PASS\t%04d\t%s\n", line, filepath);
		return 0;
	}
	printf("FAIL\t%04d\t%s\n", line, filepath);
	return 1;
}

int ntmtest_eqf(float got, float expected, int line, const char *filepath) {
	if (fabs(got - expected) < NTMTEST_EPSILON) {
		printf("PASS\t%04d\t%s\n", line, filepath);
		return 0;
	}
	printf(
		"FAIL\t%04d\t%s\tgot %f\texpected %f\n",
		line,
		filepath,
		got,
		expected
	);
	return 1;
}

int ntmtest_vec2Eq(
	NtmVec2 *got,
	float a0,
	float a1,
	int line,
	const char *filepath
) {
	if (
		(fabs(got->data[0] - (a0)) < NTMTEST_EPSILON)
		&& (fabs(got->data[1] - (a1)) < NTMTEST_EPSILON)
	) {
		printf("PASS\t%04d\t%s\n", line, filepath);
		return 0;
	} else {
		printf(
			"FAIL\t%04d\t%s\tgot %f %f\texpected %f %f\n",
			line,
			filepath,
			got->data[0],
			got->data[1],
			a0,
			a1
		);
		return 1;
	}
}

int ntmtest_vec3Eq(
	NtmVec3 *got,
	float a0,
	float a1,
	float a2,
	int line,
	const char *filepath
) {
	if (
		(fabs(got->data[0] - (a0)) < NTMTEST_EPSILON)
		&& (fabs(got->data[1] - (a1)) < NTMTEST_EPSILON)
		&& (fabs(got->data[2] - (a2)) < NTMTEST_EPSILON)
	) {
		printf("PASS\t%04d\t%s\n", line, filepath);
		return 0;
	} else {
		printf(
			"FAIL\t%04d\t%s\tgot %f %f %f\texpected %f %f %f\n",
			line,
			filepath,
			got->data[0],
			got->data[1],
			got->data[2],
			a0,
			a1,
			a2
		);
		return 1;
	}
}

int ntmtest_vec4Eq(
	NtmVec4 *got,
	float a0,
	float a1,
	float a2,
	float a3,
	int line,
	const char *filepath
) {
	if (
		(fabs(got->data[0] - (a0)) < NTMTEST_EPSILON)
		&& (fabs(got->data[1] - (a1)) < NTMTEST_EPSILON)
		&& (fabs(got->data[2] - (a2)) < NTMTEST_EPSILON)
		&& (fabs(got->data[3] - (a3)) < NTMTEST_EPSILON)
	) {
		printf("PASS\t%04d\t%s\n", line, filepath);
		return 0;
	} else {
		printf(
			"FAIL\t%04d\t%s\tgot %f %f %f %f\texpected %f %f %f %f\n",
			line,
			filepath,
			got->data[0],
			got->data[1],
			got->data[2],
			got->data[3],
			a0,
			a1,
			a2,
			a3
		);
		return 1;
	}
}

int ntmtest_quatEq(
	NtmQuat *got,
	float a0,
	float a1,
	float a2,
	float a3,
	int line,
	const char *filepath
) {
	if (
		(fabs(got->data[0] - (a0)) < NTMTEST_EPSILON)
		&& (fabs(got->data[1] - (a1)) < NTMTEST_EPSILON)
		&& (fabs(got->data[2] - (a2)) < NTMTEST_EPSILON)
		&& (fabs(got->data[3] - (a3)) < NTMTEST_EPSILON)
	) {
		printf("PASS\t%04d\t%s\n", line, filepath);
		return 0;
	} else {
		printf(
			"FAIL\t%04d\t%s\tgot %f %f %f %f\texpected %f %f %f %f\n",
			line,
			filepath,
			got->data[0],
			got->data[1],
			got->data[2],
			got->data[3],
			a0,
			a1,
			a2,
			a3
		);
		return 1;
	}
}

int ntmtest_mat2Eq(
	NtmMat2 *got,
	float a0,
	float a1,
	float a2,
	float a3,
	int line,
	const char *filepath
) {
	if (
		(fabs(got->data[0] - (a0)) < NTMTEST_EPSILON)
		&& (fabs(got->data[1] - (a1)) < NTMTEST_EPSILON)
		&& (fabs(got->data[2] - (a2)) < NTMTEST_EPSILON)
		&& (fabs(got->data[3] - (a3)) < NTMTEST_EPSILON)
	) {
		printf("PASS\t%04d\t%s\n", line, filepath);
		return 0;
	} else {
		printf(
			"FAIL\t%04d\t%s\tgot %f %f %f %f\texpected %f %f %f %f\n",
			line,
			filepath,
			got->data[0],
			got->data[1],
			got->data[2],
			got->data[3],
			a0,
			a1,
			a2,
			a3
		);
		return 1;
	}
}

int ntmtest_mat2dEq(
	NtmMat2d *got,
	float a0,
	float a1,
	float a2,
	float a3,
	float a4,
	float a5,
	int line,
	const char *filepath
) {
	if (
		(fabs(got->data[0] - (a0)) < NTMTEST_EPSILON)
		&& (fabs(got->data[1] - (a1)) < NTMTEST_EPSILON)
		&& (fabs(got->data[2] - (a2)) < NTMTEST_EPSILON)
		&& (fabs(got->data[3] - (a3)) < NTMTEST_EPSILON)
		&& (fabs(got->data[4] - (a4)) < NTMTEST_EPSILON)
		&& (fabs(got->data[5] - (a5)) < NTMTEST_EPSILON)
	) {
		printf("PASS\t%04d\t%s\n", line, filepath);
		return 0;
	} else {
		printf(
			"FAIL\t%04d\t%s\tgot %f %f %f %f %f %f\texpected %f %f %f %f %f %f\n",
			line,
			filepath,
			got->data[0],
			got->data[1],
			got->data[2],
			got->data[3],
			got->data[4],
			got->data[5],
			a0,
			a1,
			a2,
			a3,
			a4,
			a5
		);
		return 1;
	}
}

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
	const char *filepath
) {
	if (
		(fabs(got->data[0] - (a0)) < NTMTEST_EPSILON)
		&& (fabs(got->data[1] - (a1)) < NTMTEST_EPSILON)
		&& (fabs(got->data[2] - (a2)) < NTMTEST_EPSILON)
		&& (fabs(got->data[3] - (a3)) < NTMTEST_EPSILON)
		&& (fabs(got->data[4] - (a4)) < NTMTEST_EPSILON)
		&& (fabs(got->data[5] - (a5)) < NTMTEST_EPSILON)
		&& (fabs(got->data[6] - (a6)) < NTMTEST_EPSILON)
		&& (fabs(got->data[7] - (a7)) < NTMTEST_EPSILON)
		&& (fabs(got->data[8] - (a8)) < NTMTEST_EPSILON)
	) {
		printf("PASS\t%04d\t%s\n", line, filepath);
		return 0;
	} else {
		printf(
			"FAIL\t%04d\t%s\tgot %f %f %f %f %f %f %f %f %f\texpected %f %f %f %f %f %f %f %f %f\n",
			line,
			filepath,
			got->data[0],
			got->data[1],
			got->data[2],
			got->data[3],
			got->data[4],
			got->data[5],
			got->data[6],
			got->data[7],
			got->data[8],
			a0,
			a1,
			a2,
			a3,
			a4,
			a5,
			a6,
			a7,
			a8
		);
		return 1;
	}
}

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
	const char *filepath
) {
	if (
		(fabs(got->data[0] - (a0)) < NTMTEST_EPSILON)
		&& (fabs(got->data[1] - (a1)) < NTMTEST_EPSILON)
		&& (fabs(got->data[2] - (a2)) < NTMTEST_EPSILON)
		&& (fabs(got->data[3] - (a3)) < NTMTEST_EPSILON)
		&& (fabs(got->data[4] - (a4)) < NTMTEST_EPSILON)
		&& (fabs(got->data[5] - (a5)) < NTMTEST_EPSILON)
		&& (fabs(got->data[6] - (a6)) < NTMTEST_EPSILON)
		&& (fabs(got->data[7] - (a7)) < NTMTEST_EPSILON)
		&& (fabs(got->data[8] - (a8)) < NTMTEST_EPSILON)
		&& (fabs(got->data[9] - (a9)) < NTMTEST_EPSILON)
		&& (fabs(got->data[10] - (a10)) < NTMTEST_EPSILON)
		&& (fabs(got->data[11] - (a11)) < NTMTEST_EPSILON)
		&& (fabs(got->data[12] - (a12)) < NTMTEST_EPSILON)
		&& (fabs(got->data[13] - (a13)) < NTMTEST_EPSILON)
		&& (fabs(got->data[14] - (a14)) < NTMTEST_EPSILON)
		&& (fabs(got->data[15] - (a15)) < NTMTEST_EPSILON)
	) {
		printf("PASS\t%04d\t%s\n", line, filepath);
		return 0;
	} else {
		printf(
			"FAIL\t%04d\t%s\tgot %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f\texpected %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f\n",
			line,
			filepath,
			got->data[0],
			got->data[1],
			got->data[2],
			got->data[3],
			got->data[4],
			got->data[5],
			got->data[6],
			got->data[7],
			got->data[8],
			got->data[9],
			got->data[10],
			got->data[11],
			got->data[12],
			got->data[13],
			got->data[14],
			got->data[15],
			a0,
			a1,
			a2,
			a3,
			a4,
			a5,
			a6,
			a7,
			a8,
			a9,
			a10,
			a11,
			a12,
			a13,
			a14,
			a15
		);
		return 1;
	}
}
