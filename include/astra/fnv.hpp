//
// Licensed as public domain.
// https://tools.ietf.org/html/draft-eastlake-fnv-17
// http://www.isthe.com/chongo/tech/comp/fnv/index.html
//

#pragma once

#include <cstdint>
#include <cstddef>
#include "macros.hpp"

namespace astra::hash {
    constexpr const char FNV1_IV[33] = "chongo <Landon Curt Noll> /\\../\\";
    constexpr const char FNV1_IV_ALT[33] = "chongo (Landon Curt Noll) /\\oo/\\";

    constexpr uint32_t FNV_PRIME_32 = 0x01000193;
    constexpr uint32_t FNV1_BASIS_32 = 0x811C9DC5;
    constexpr uint32_t FNV1_BASIS_32_ALT = 0x8D9A085E;
    // the year 2013
    constexpr uint64_t FNV_PRIME_64 = 0x00000100000001B3;
    constexpr uint64_t FNV1_BASIS_64 = 0xCBF29CE484222325;
    constexpr uint64_t FNV1_BASIS_64_ALT = 0xDF8E50CB9ED4BBFE;
    // // the year 2063
    // constexpr uint128_t FNV_PRIME_128 = 0x0000000001000000000000000000013B;
    // constexpr uint128_t FNV1_BASIS_128 = 0x6C62272E07BB014262B821756295C58D;
    // constexpr uint128_t FNV1_BASIS_128_ALT = 0xB5912BB60230CD8C98787BAB303F8EF6;
    // // the year 2183
    // constexpr uint256_t FNV_PRIME_256 = 0x0000000000000000000001000000000000000000000000000000000000000163;
    // constexpr uint256_t FNV1_BASIS_256 = 0xDD268DBCAAC550362D98C384C4E576CCC8B1536847B6BBB31023B4C8CAEE0535;
    // constexpr uint256_t FNV1_BASIS_256_ALT = 0X28EF4B97D34C767DA12E704DCE98F5F32F0205DDD0286B79CD568A04CCC38B6E;
    // // the year 2423
    // constexpr uint512_t FNV_PRIME_512 = 0x00000000000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000000000000000000000000157;
    // constexpr uint512_t FNV1_BASIS_512 = 0xB86DB0B1171F4416DCA1E50F309990ACAC87D059C90000000000000000000D21E948F68A34C192F62EA79BC942DBE7CE182036415F56E34BAC982AAC4AFE9FD9;
    // constexpr uint512_t FNV1_BASIS_512_ALT = 0X1111C00BEFE664A4589A4858AC3BD43A24A612CFFB0000000000000000000D21E948F68A34C1C75E9642CFE6E4EE183AC52BD549D131472BAC0D227B30846262;
    // // the year 2903
    // constexpr uint1024_t FNV_PRIME_1024 = 0x000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000018D;
    // constexpr uint1024_t FNV1_BASIS_1024 = 0x5F7A76758ECC4D32E56D5A591028B74B29FC4223FDADA16C3BF34EDA3674DA9A21D9000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000004C6D7EB6E73802734510A555F256CC005AE556BDE8CC9C6A93B21AFF4B16C71EE90B3;
    // constexpr uint1024_t FNV1_BASIS_1024_ALT = 0x5F7A76758ECC4D3396093343FCB46AAF6AFB9B5F00519FADC94A179979138247F2C3000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000004C6D7EB6E7380273FBA537A1BAA73D9E6D480C8663104287CFAAF3FE5486070E00150;

    // to calculate a basis call fnv##(FNV1_IV, 32, 0);
    // you can change FNV1_IV, however it would result in different hashes.
    // there's some math behind the theory on selecting FNV primes, read more on it on either linked pages.
    // the IETF page also has sample C code for 128 and higher bit spaces.

    [[maybe_unused]] ASTRA_INLINE uint32_t fnv32(const uint8_t *buf, size_t size, uint32_t basis = FNV1_BASIS_32, uint32_t prime = FNV_PRIME_32) {
        #pragma omp simd
        for (size_t i = 0; i < size; ++i) {
            basis *= prime;
            basis ^= buf[i];
        }

        return basis;
    }

    [[maybe_unused]] ASTRA_INLINE uint32_t fnva32(const uint8_t *buf, size_t size, uint32_t basis = FNV1_BASIS_32, uint32_t prime = FNV_PRIME_32) {
        #pragma omp simd
        for (size_t i = 0; i < size; ++i) {
            basis ^= buf[i];
            basis *= prime;
        }

        return basis;
    }

    [[maybe_unused]] ASTRA_INLINE uint64_t fnv64(const uint8_t *buf, size_t size, uint64_t basis = FNV1_BASIS_64, uint64_t prime = FNV_PRIME_64) {
        #pragma omp simd
        for (size_t i = 0; i < size; ++i) {
            basis *= prime;
            basis ^= buf[i];
        }

        return basis;
    }

    [[maybe_unused]] ASTRA_INLINE uint64_t fnva64(const uint8_t *buf, size_t size, uint64_t basis = FNV1_BASIS_64, uint64_t prime = FNV_PRIME_64) {
        #pragma omp simd
        for (size_t i = 0; i < size; ++i) {
            basis ^= buf[i];
            basis *= prime;
        }

        return basis;
    }
} // namespace astra::hash
