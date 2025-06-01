#ifndef TEXTURE_H
#define TEXTURE_H

#include <vector>
#include <iostream>
#include <inttypes.h>
#include <algorithm>
#include <string>

#include "Drawable.h"

namespace GG15
{
    class Texture //texture can either be from: string, txt file/TMI (custom made "Transparent Image File") file or image file supported by magick
    {
        private:
        bool repeat = false;
        int width = 0;
        int height = 0;

        public:
        std::vector<uint8_t> texture_data;

        Texture();
        virtual ~Texture();

        std::vector<uint8_t> get_texture_data();
        bool load_from_file(std::string file_dir);
        void load_from_string(std::string &data);

        GG15::Pixel_vector get_bounds(); //the following three need to be define in cpp file still, but its 2am and im tired so future me can do that shit :p
        GG15::Pixel_vector get_transformed_bounds();

        GG15::Pixel_vector set_bounds(int width_param, int height_param);

        GG15::Pixel_vector get_dimensions();

    };
}

#endif // TEXTURE_H
