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
    texture_data.clear();
    texture_data.shrink_to_fit();

    width  = 0;
    height = 0;

    std::ifstream file(file_dir);

    if (!file.good())
    {
        std::string message = "file at: " + file_dir + " could not be loaded :(";
        std::string system_command = "zenity --error --text=\"" + message + "\"";
        system(system_command.c_str());
        return false;
    }

    std::string file_buffer = "";
    while (std::getline(file, file_buffer))
    {
        if (file_buffer != "") //in case an empty line is accidentally left in the file, which would mess up the image, i ran into this mistake, so a user might as well so we might as well automatically fix it for them ;)
        {

            for (int i=0; i!=file_buffer.length(); i++)
            {

                texture_data.push_back(file_buffer[i] - '0');
            }
            height++;
        }
    }
    width = texture_data.size() / height;
    return true;
}

void GG15::Texture::load_from_string(std::string &data)
{
    texture_data.clear();
    texture_data.shrink_to_fit();
    width  = 0;
    height = 0;

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

GG15::Pixel_vector GG15::Texture::get_dimensions()
{
    return GG15::Pixel_vector { width, height };
}
