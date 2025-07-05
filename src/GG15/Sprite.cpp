#include "Sprite.h"

GG15::Sprite::Sprite()
{
    //ctor
}

GG15::Sprite::~Sprite()
{
    //dtor
}

GG15::Texture *GG15::Sprite::get_texture_reference()
{
    return texture_ref;
}


GG15::Region GG15::Sprite::get_texture_region()
{
    return texture_region;
}

std::vector<uint8_t> GG15::Sprite::get_sprite()
{
    std::vector<uint8_t> spr_data;
    int width_count   = texture_region.top_left.x;
    int height_count  = texture_region.top_left.y;
    int desired_index = 0;

    for (int i=texture_region.top_left.x; i != ((width)+1)*height; i++)
    {
        if (width_count == texture_region.bottom_right.x)
        {
            height_count++;
            width_count = texture_region.top_left.x - 1;
        }
        else
        {
            desired_index = GG15::coords_to_index(width_count, height_count, texture_ref->get_dimensions().x);
            spr_data.push_back(texture_ref->get_texture_data().at(desired_index));
        }
        width_count++;
    }

    return spr_data;
}

void GG15::Sprite::set_texture_region(int x1, int y1, int x2, int y2)
{
    texture_region = { {x1, y1}, {x2, y2} };

    width  = x2 - x1;
    height = y2 - y1;
}

void GG15::Sprite::assign_texture(GG15::Texture *texture)
{
    texture_ref = texture;
    width  = texture_ref->get_dimensions().x;
    height = texture_ref->get_dimensions().y;
    texture_region = {0, 0, width, height};
}
