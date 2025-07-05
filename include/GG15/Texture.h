#ifndef TEXTURE_H
#define TEXTURE_H

#include <vector>
#include <iostream>
#include <inttypes.h>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstdlib>

#include "Drawable.h"

namespace GG15
{
    class Texture //texture can either be from: string, txt file or image file supported by magick
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

        GG15::Pixel_vector get_dimensions();

    };
}

#endif // TEXTURE_H
