# Nitrine Math [![Build Status](https://travis-ci.org/theakman2/libntm.svg?branch=master)](https://travis-ci.org/theakman2/libntm)

A port of the [glmatrix](https://github.com/toji/gl-matrix) javascript library
to ANSI C (C89) for manipulating vectors, matrices and quaternions for OpenGL
applications.

## Building and Installation

Building requires CMake 2.8+ in your path.

The libntm library has been successfully compiled on these platforms:

* Windows with MSVC 2010
* Windows with MSVC 2013
* Windows with MingGW and MSYS 1.0
* Debian Squeeze with GCC
* OSX 10.9 with Clang

Since libntm is C89 compliant, it should compile on other platforms.

### Linux and OS X

	$ cd /path/to/this/directory
	$ mkdir buildfiles
	$ cd buildfiles
	$ cmake ..
	$ make
	$ make test
	$ make install
	
### Windows with MinGW and MSYS 1.0

	$ cd /path/to/this/directory
	$ mkdir buildfiles
	$ cd buildfiles
	$ cmake -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX="C:\path\to\suitable\install\prefix" ..
	$ make
	$ make test
	$ make install

`C:\path\to\suitable\install\prefix` should be the full path to a directory
that contains `lib` and `include` directories and which is in gcc's header and
library search path. For example on my system that's `C:\MinGW\msys\1.0`.

### Windows with Visual Studio

If you have Visual Studio 2010:

	$ cd /path/to/this/directory
	$ mkdir buildfiles
	$ cd buildfiles
	$ cmake -G "Visual Studio 10 2010"

For other versions of Visual Studio, just replace the value for cmake's -G flag
with the appropriate string (e.g. "Visual Studio 12 2013").

You can now open the Visual Studio solution in `buildfiles` and complete the
build and installation process in Visual Studio.

## Usage

Usage with gcc on Linux/OS X or Windows with MinGW/MSYS is straightforward.

`ntmexample.c`:

	#include <stdio.h>
	#include <ntm/ntm.h>

	int main(void) {
		NtmVec3 a;
		NtmVec3 b;
		NtmVec3 cross;
		
		ntm_vec3_set(&a, 2.0f, 4.0f, -2.5f);
		ntm_vec3_set(&b, 3.0f, 1.5f, 0.4f);
		ntm_vec3_cross(&cross, &a, &b);
		
		printf(
			"The values are %f, %f and %f\n",
			cross.data[0],
			cross.data[1],
			cross.data[2]
		);
	}
	
At the command prompt:

	$ gcc ntmexample.c -lntm -o ntmexample
	$ ./ntmexample
	
## Changelog

See adjacent CHANGELOG.md.