#pragma once

// try to figure out how to force inlining.
#ifndef ASTRA_INLINE
#    ifdef WIN32
#        define ASRTA_INLINE __forceinline
#    else
#        define ASRTA_INLINE __attribute__((always_inline))
#    endif
#endif

// try to determine the alignment space of the current architectuire
#ifdef __AVX__
#    ifdef __AVX512F__
#        define ASRTA_ALIGNMENT 64
#    else
#        ifdef __AVX2__
#            define ASRTA_ALIGNMENT 32
#        else
#            define ASRTA_ALIGNMENT 16
#        endif
#    endif
#else
#    define ASRTA_ALIGNMENT __STDCPP_DEFAULT_NEW_ALIGNMENT__
#endif