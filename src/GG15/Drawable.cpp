#include "Drawable.h"

GG15::Drawable::Drawable()
{
    //ctor
}

GG15::Drawable::~Drawable()
{
    //dtor
}

void GG15::Drawable::set_position(int x, int y)
{
    posX = x;
    posY = y;
}

GG15::Pixel_vector GG15::Drawable::get_position()
{
    return GG15::Pixel_vector{posX, posY};
}

void GG15::Drawable::move(int x, int y)
{
    posX += x;
    posY += y;
}

int GG15::Drawable::get_pixel_data_size()
{ //currently crashes obv cause no return
    //return pixel_data.size();
    return 1;
}

GG15::Pixel_vector GG15::Drawable::get_dimensions()
{
    return GG15::Pixel_vector { width, height };
}
