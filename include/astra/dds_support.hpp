#pragma once

#include <cstdint>

namespace astra::gdx {
#pragma pack(push, 4)
    typedef struct DDS_PIXEL_FORMAT {
        uint32_t size = 0x20;
        uint32_t flags = 0x00000004;
        uint32_t fourCC = 0x30315844; // DX10
        uint32_t RGBBitCount = 0;
        uint32_t RBitMask = 0;
        uint32_t GBitMask = 0;
        uint32_t BBitMask = 0;
        uint32_t ABitMask = 0;
    } dds_pixel_format_t;
    static_assert(sizeof(dds_pixel_format_t) == 0x20, "sizeof(dds_pixel_format_t) != 0x20");

    typedef struct DDS_HEADER {
        uint32_t magic = 0x20534444;
        uint32_t size = 0x7C;
        uint32_t flags = 0x000A1007;
        uint32_t height = 0;
        uint32_t width = 0;
        uint32_t linear_size = 0;
        uint32_t depth = 1;
        uint32_t mip_count = 0;
        uint32_t reserved1[11] = {};
        dds_pixel_format_t pixel_format = {};
        uint32_t caps = 0x00401008;
        uint32_t caps2 = 0;
        uint32_t caps3 = 0;
        uint32_t caps4 = 0;
        uint32_t reserved2 = {};
    } dds_t;
    static_assert(sizeof(dds_t) == 0x80, "sizeof(dds_t) != 0x80");

    typedef enum class DXGI_FORMAT : uint32_t {
        UNKNOWN,
        R32G32B32A32_TYPELESS,
        R32G32B32A32_FLOAT,
        R32G32B32A32_UINT,
        R32G32B32A32_SINT,
        R32G32B32_TYPELESS,
        R32G32B32_FLOAT,
        R32G32B32_UINT,
        R32G32B32_SINT,
        R16G16B16A16_TYPELESS,
        R16G16B16A16_FLOAT,
        R16G16B16A16_UNORM,
        R16G16B16A16_UINT,
        R16G16B16A16_SNORM,
        R16G16B16A16_SINT,
        R32G32_TYPELESS,
        R32G32_FLOAT,
        R32G32_UINT,
        R32G32_SINT,
        R32G8X24_TYPELESS,
        D32_FLOAT_S8X24_UINT,
        R32_FLOAT_X8X24_TYPELESS,
        X32_TYPELESS_G8X24_UINT,
        R10G10B10A2_TYPELESS,
        R10G10B10A2_UNORM,
        R10G10B10A2_UINT,
        R11G11B10_FLOAT,
        R8G8B8A8_TYPELESS,
        R8G8B8A8_UNORM,
        R8G8B8A8_UNORM_SRGB,
        R8G8B8A8_UINT,
        R8G8B8A8_SNORM,
        R8G8B8A8_SINT,
        R16G16_TYPELESS,
        R16G16_FLOAT,
        R16G16_UNORM,
        R16G16_UINT,
        R16G16_SNORM,
        R16G16_SINT,
        R32_TYPELESS,
        D32_FLOAT,
        R32_FLOAT,
        R32_UINT,
        R32_SINT,
        R24G8_TYPELESS,
        D24_UNORM_S8_UINT,
        R24_UNORM_X8_TYPELESS,
        X24_TYPELESS_G8_UINT,
        R8G8_TYPELESS,
        R8G8_UNORM,
        R8G8_UINT,
        R8G8_SNORM,
        R8G8_SINT,
        R16_TYPELESS,
        R16_FLOAT,
        D16_UNORM,
        R16_UNORM,
        R16_UINT,
        R16_SNORM,
        R16_SINT,
        R8_TYPELESS,
        R8_UNORM,
        R8_UINT,
        R8_SNORM,
        R8_SINT,
        A8_UNORM,
        R1_UNORM,
        R9G9B9E5_SHAREDEXP,
        R8G8_B8G8_UNORM,
        G8R8_G8B8_UNORM,
        BC1_TYPELESS,
        BC1_UNORM,
        BC1_UNORM_SRGB,
        BC2_TYPELESS,
        BC2_UNORM,
        BC2_UNORM_SRGB,
        BC3_TYPELESS,
        BC3_UNORM,
        BC3_UNORM_SRGB,
        BC4_TYPELESS,
        BC4_UNORM,
        BC4_SNORM,
        BC5_TYPELESS,
        BC5_UNORM,
        BC5_SNORM,
        B5G6R5_UNORM,
        B5G5R5A1_UNORM,
        B8G8R8A8_UNORM,
        B8G8R8X8_UNORM,
        R10G10B10_XR_BIAS_A2_UNORM,
        B8G8R8A8_TYPELESS,
        B8G8R8A8_UNORM_SRGB,
        B8G8R8X8_TYPELESS,
        B8G8R8X8_UNORM_SRGB,
        BC6H_TYPELESS,
        BC6H_UF16,
        BC6H_SF16,
        BC7_TYPELESS,
        BC7_UNORM,
        BC7_UNORM_SRGB,
        AYUV,
        Y410,
        Y416,
        NV12,
        P010,
        P016,
        OPAQUE420,
        YUY2,
        Y210,
        Y216,
        NV11,
        AI44,
        IA44,
        P8,
        A8P8,
        B4G4R4A4_UNORM,
        P208,
        V208,
        V408,
        SAMPLER_FEEDBACK_MIN_MIP_OPAQUE,
        SAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE,
        FORCE_UINT
    } dxgi_format_t;

    typedef struct DDS_HEADER_DXT10 {
        dxgi_format_t format = dxgi_format_t::UNKNOWN;
        uint32_t resource_dimension = 0x3;
        uint32_t flags = 0;
        uint32_t array_size = 0x1;
        uint32_t flags2 = 0x2;
    } dx10_t;
    static_assert(sizeof(dx10_t) == 0x14, "sizeof(dds10_t) != 0x14");

    typedef struct DDS_FORMAT {
        dds_t dx9 = {};
        dx10_t dx10 = {};
    } dds10_t;
#pragma pack(pop)
} // namespace astra::gdx
