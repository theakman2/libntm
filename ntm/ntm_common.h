/*
The MIT License (MIT)

Copyright (c) 2015 A Kazim, Brandon Jones, Colin MacKenzie IV.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef NTM_SRC_NTM_COMMON_H_
#define NTM_SRC_NTM_COMMON_H_

	#ifdef __cplusplus
		extern "C" {
	#endif

		#ifndef NTM_EPSILON
			#define NTM_EPSILON 0.00001f
		#endif

		#ifndef NTM_PI
			#define NTM_PI 3.1415926535897932384626433832795f
		#endif

		typedef struct {
			float data[2];
		} NtmVec2;

		typedef struct {
			float data[3];
		} NtmVec3;

		typedef struct {
			float data[4];
		} NtmVec4;

		typedef struct {
			float data[4];
		} NtmMat2;

		typedef struct {
			float data[6];
		} NtmMat2d;

		typedef struct {
			float data[9];
		} NtmMat3;

		typedef struct {
			float data[16];
		} NtmMat4;

		typedef NtmVec4 NtmQuat;

	#ifdef __cplusplus
		}
	#endif

#endif /* NTM_SRC_NTM_COMMON_H_ */
