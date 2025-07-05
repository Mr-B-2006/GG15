#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <vector>
#include <inttypes.h>

#include "Abstractions.h"

namespace GG15
{
    class Drawable
    {
        protected:

        int posX = 0;
        int posY = 0;

        int width = 0;
        int height = 0;

        public:

        Drawable();
        virtual ~Drawable();

        void set_position(int x, int y);
        GG15::Pixel_vector get_position();
        void move(int x, int y);
        int get_pixel_data_size();

        GG15::Pixel_vector get_dimensions();
    };
}


#endif // DRAWABLE_H
