#pragma once

namespace sti
{

enum class color_image_format
{
    BGR,
    RGB,
    RGBA,
    YUV420,
    invalid
};

/* keeps track of the image info */
struct image_info
{
    image_info();
    explicit image_info(const color_image_format format);
    explicit image_info(const int width, const int height, const int bits, const int stride,
                        const color_image_format format);

    int width;
    int height;
    int stride;
    int bits;
    color_image_format format;
};

inline image_info::image_info()
    : image_info(0, 0, 0, 0, color_image_format::invalid)
{
}

inline image_info::image_info(const color_image_format format)
    : image_info(0, 0, 0, 0, format)
{
}

inline image_info::image_info(const int width, const int height, const int bits, const int stride,
                              const color_image_format format)
    : width(width)
    , height(height)
    , stride(stride)
    , bits(bits)
    , format(format)
{
}

} // namespace sti
