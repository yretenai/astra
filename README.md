# astra standard library

personal c++ classes

## runtime_array.hpp

_namespace astra::mem_

**defines runtime_array\<T\>**

a fixed-width managed array, it offers features such as slicing and safe type casting.

## fnv.hpp

_namespace astra::hash_

**defines fnv32; fnva32; fnv64; fnva64**

a series of FNV implementations (fnv and fnv-a) for both 32-bit and 64 bit hashes.

default configured for FNV1, but the basis + primes are not hardcoded.

## dds_support.hpp

_namespace astra::gdx_

**defines dds_pixel_format_t; dds_t; dxgi_format_t; dx10_t; dds10_t**

exact implementations of DirectX DDS header structures and enums. useful for compiling on linux if you need to serialize dds headers.

## indent.hpp

_namespace astra::io_

**defines indent**

an indent helper, it supports + and - operators to control the indent depth.


## file_helper.hpp

_namespace astra::io_

**defines read_file; write_file**

helper functions to pipe runtime_array data to a file.

## macros.hpp

**defines ASTRA_INLINE; ASTRA_ALIGNMENT**

see comments for each define.
