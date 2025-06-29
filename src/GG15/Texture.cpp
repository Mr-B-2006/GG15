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

    bool wflag = false;

    for (int i=0; i != data.length(); i++)
    {
        if (!wflag)
        {
            width++;
        }
        if (data[i] != '\n')
        {
            texture_data.push_back(data[i] - '0');
                  //  std::cout << texture_data[i] +0;

        }
        else if (data[i] == '\n')
        {
            wflag = true;
            height++;
           // std::cout << "\n";

        }
    }
    width--;
    //std::cout << width;
    //std::cout << "\n\n\n\n\n";
}

GG15::Pixel_vector GG15::Texture::get_dimensions()
{
    return GG15::Pixel_vector { width, height };
}

/* come to think about it, reliably making this algorithm will be harder than thought so ill outline basic pseudocode,
this will only work with text, im going to make my own file format for our textures (.tmif -> Transparent Monochrome Image Format)

    ~go thru each index in string
    ~if 1 then pixel if 0, no pixel, if neither then act as transparency ->
    ~count
*/

