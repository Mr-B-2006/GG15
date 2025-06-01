#include "Sprite.h"

GG15::Sprite::Sprite()
{
    //ctor
}

GG15::Sprite::~Sprite()
{
    //dtor
}


GG15::Region GG15::Sprite::get_texture_region()
{

}

void GG15::Sprite::set_texture_region(int x, int y)
{

}

void GG15::Sprite::assign_texture(GG15::Texture *texture)
{
    texture_ref = texture;
    pixel_data.resize(texture_ref->get_texture_data().size());
    memcpy(pixel_data.data(), texture_ref->get_texture_data().data(), texture_ref->get_texture_data().size());
    this->width = texture_ref->get_dimensions().x;
    this->height = texture_ref->get_dimensions().y;
}
