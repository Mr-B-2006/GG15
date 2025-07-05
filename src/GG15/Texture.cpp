#include "Texture.h"

GG15::Texture::Texture()
{
    //ctor
}

GG15::Texture::~Texture()
{
    //dtor
}

std::vector<uint8_t> GG15::Texture::get_texture_data()
{
    return texture_data;
}

bool GG15::Texture::load_from_file(std::string file_dir)
{

}

void GG15::Texture::load_from_string(std::string &data)
{
    texture_data.clear();
    texture_data.shrink_to_fit();

    bool count_width = false;

    for (int i=0; i != data.length(); i++)
    {
        if (!count_width)
        {
            width++;
        }
        if (data[i] != '\n')
        {
            texture_data.push_back(data[i] - '0');
        }
        else if (data[i] == '\n')
        {
            count_width = true;
            height++;
        }
    }
    width--;
}

GG15::Pixel_vector GG15::Texture::get_bounds()
{
    return  GG15::Pixel_vector {width, height};
}


GG15::Pixel_vector GG15::Texture::get_dimensions()
{
    return GG15::Pixel_vector { width, height };
}
