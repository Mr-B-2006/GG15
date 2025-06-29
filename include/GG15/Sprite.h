#ifndef SPRITE_H
#define SPRITE_H

#include <cstring>
#include <algorithm>
#include <vector>
#include <inttypes.h>

#include "Texture.h"

namespace GG15
{
    class Sprite : public GG15::Drawable
    {
        private:
        GG15::Region texture_region = {0,0,0,0};
        GG15::Texture *texture_ref;


        public:

        Sprite();
        ~Sprite();

        GG15::Texture *get_texture_reference();
        GG15::Region get_texture_region();
        std::vector<uint8_t> get_sprite(); //return array of uint_8 instead
        void set_texture_region(int x1, int y1, int x2, int y2);
        void assign_texture(GG15::Texture *texture);

    };
}

#endif // SPRITE_H
