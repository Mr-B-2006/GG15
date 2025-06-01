#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <vector>
#include <inttypes.h>

namespace GG15
{
    struct Pixel_vector
    {
        int x = 0;
        int y = 0;
    };

    struct Region
    {
        int top_left = 0;
        int bottom_left = 0;

        int top_right = 0;
        int bottom_right = 0;
    };

    class Drawable
    {
        protected:
        std::vector<uint8_t> pixel_data;

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

        int operator[](int index);
        uint8_t get_pixel(int x, int y); //multi-dimensional accessor
    };
}


#endif // DRAWABLE_H
