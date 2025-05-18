#ifndef SPRITE_H
#define SPRITE_H

#include "Drawable.h"

namespace GG15
{
    class Sprite : public GG15::Drawable
    {
        private:
        GG15::Texture *texture_ref;
        GG15::pixel_vector texture_region;

        public:
        Sprite();
        virtual ~Sprite();

        GG15::pixel_vector get_texture_region();
        void set_texture_region(int x, int y);


    };
}

#endif // SPRITE_H
