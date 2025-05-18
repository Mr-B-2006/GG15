#include "Texture.h"

GG15::Texture::Texture()
{
    //ctor
}

GG15::Texture::~Texture()
{
    //dtor
}

bool GG15::Texture::load_from_file(std::string file_dir)
{

}

void GG15::Texture::load_from_string(std::string data)
{
    pixel_data.clear();
    pixel_data.shrink_to_fit();
    for (int i=0; i != data.length(); i++)
    {

    }
}

/* come to think about it, reliably making this algorithm will be harder than thought so ill outline basic pseudocode:

*/

