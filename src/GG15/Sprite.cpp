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

std::vector<uint8_t> GG15::Sprite::get_sprite() //this func allocates memory to the heap, it needs to be stored in a variable and its memory must be freed after use
{ //we gonna convert the std::vector to a uint8_t array, on the user-side this needs to be put into an a
 //  int seek_begin = GG15::coords_to_index(texture_region.top_left.x, texture_region.top_left.y, this->width);
//   int seek_end = GG15::coords_to_index(texture_region.bottom_right.x, texture_region.bottom_right.y, this->width);
    std::vector<uint8_t> spr_data;
    for (int i=0; i != texture_ref->get_texture_data().size(); i++) //first index returns garbage data???????? maybe has to do with how vector is called? maybe try using heap memory???
    {

        spr_data.push_back(texture_ref->get_texture_data().at(i));
    }
    return spr_data;
}

void GG15::Sprite::set_texture_region(int x1, int y1, int x2, int y2)
{
    texture_region = { {x1, y1}, {x2, y2} };

    this->width  = x2 - x1;
    this->height = y2 - y1;
}

void GG15::Sprite::assign_texture(GG15::Texture *texture)
{ //will need to amend this cause we removed pixel_data :/
    texture_ref = texture;
   // pixel_data.resize(texture_ref->get_texture_data().size());
//    memcpy(pixel_data.data(), texture_ref->get_texture_data().data(), texture_ref->get_texture_data().size());
    this->width = texture_ref->get_dimensions().x;
    this->height = texture_ref->get_dimensions().y;
    texture_region = {0, 0, width, height};
}
