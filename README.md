# Nitrine Math

A port of the [glmatrix](https://github.com/toji/gl-matrix) javascript library
to ANSI C (C89) for manipulating vectors, matrices and quaternions for OpenGL
applications.

## Building

Building requires CMake 2.8+ in your path.

To build and install on Linux and OS X:

	$ ./build
	$ cd buildfiles
	$ make install
	
To build on Windows:

	$ build

The project has been successfully compiled on these platforms:

* Windows with MSVC 2010
* Windows with MSVC 2013
* Windows with MingGW and MSYS
* Debian Squeeze with GCC
* OSX 10.9 with Clang

## Usage

	#include <stdio.h>
	#include <ntm/ntm.h>

	int main(void) {
		NtmVec3 a;
		NtmVec3 b;
		NtmVec3 cross;
		
		ntm_vec3_set(&a, 2.0f, 4.0f, -2.5f);
		ntm_vec3_set(&b, 3.0f, 1.5f, 0.4f);
		ntm_vec3_cross(&cross, &a, &b);
		
		print_f(
			"The values are %f, %f and %f",
			cross.data[0],
			cross.data[1],
			cross.data[2]
		);
	}
	
## Changelog

See adjacent CHANGELOG.md for changes.