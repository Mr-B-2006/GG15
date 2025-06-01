#ifndef SPRITE_H
#define SPRITE_H

#include <cstring>
#include "Texture.h"

namespace GG15
{
    class Sprite : public GG15::Drawable
    {
        private:
        GG15::Texture *texture_ref;
        GG15::Region texture_region;

        public:
        Sprite();
        ~Sprite();

        GG15::Region get_texture_region();
        void set_texture_region(int x, int y);
        void assign_texture(GG15::Texture *texture);

    };
}

#endif // SPRITE_H
