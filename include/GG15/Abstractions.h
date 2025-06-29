#pragma once
#ifndef ABSTRACTIONS_H
#define ABSTRACTIONS_H

namespace GG15
{
    struct Pixel_vector
    {
        int x = 0;
        int y = 0;
    };

    struct Region
    {
        GG15::Pixel_vector top_left = { 0, 0 };

        GG15::Pixel_vector bottom_right = { 0, 0 };
    };
    inline int coords_to_index(int x, int y, int width)
    {
        return width*y + x;
    }
    inline GG15::Pixel_vector index_to_coords(int index, int width)
    {
        Pixel_vector out;
        out.x = index % width;
        out.y = index / width;
        return out;
    }
}

#endif // ABSTRACTIONS_H_INCLUDED
