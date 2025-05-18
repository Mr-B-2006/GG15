#ifndef TEXTURE_H
#define TEXTURE_H

#include <vector>
#include <iostream>

#include "Drawable.h"

namespace GG15
{
    class Texture //texture can either be from: string, txt file/raw data file or image file supported by magick
    {
        private:
        std::vector<bool> pixel_data;
        bool repeat = false;
        int width = 0;
        int height = 0;

        public:

        Texture();
        virtual ~Texture();

        bool load_from_file(std::string file_dir);
        void load_from_string(std::string data);
    };
}

#endif // TEXTURE_H
