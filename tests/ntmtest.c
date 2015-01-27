#include <stdio.h>
#include "ntmtest_common.h"
#include "ntmtest_vec2.h"
#include "ntmtest_vec3.h"
#include "ntmtest_vec4.h"
#include "ntmtest_mat2.h"
#include "ntmtest_mat2d.h"
#include "ntmtest_mat3.h"
#include "ntmtest_mat4.h"
#include "ntmtest_quat.h"

int allTests(void) {
	return
		ntmtest_vec2()
		|| ntmtest_vec3()
		|| ntmtest_vec4()
		|| ntmtest_mat2()
		|| ntmtest_mat2d()
		|| ntmtest_mat3()
		|| ntmtest_mat4()
		|| ntmtest_quat()
	;
}

int main(void) {
	int result = allTests();
	if (result == 0) {
		printf("COMPLETE: all tests report success.\n");
	} else {
		printf("COMPLETE: a test reports failure.\n");
	}
	return result != 0;
}
