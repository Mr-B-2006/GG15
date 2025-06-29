#include <g15daemon_client.h>
#include "GG15/Screen.h"


GG15::Screen::Screen(int fps_param)
{
    id = new_g15_screen(G15_PIXELBUF);
    fps = fps_param;
    if (id < 0)
    {
        perror("Could not open G15daemon"); //maybe make it so we output an error when we see that the G15 has been disconnected, maybe maybe even try to have us be able to reconnect without restarting the program (be bale to reconnect the G15 while maintaining current program state)

    }
}

GG15::Screen::~Screen()
{
    g15_close_screen(id);
}

void GG15::Screen::clear_screen(bool pixel_on)
{
    memset(framebuffer, pixel_on, G15_BUFSIZE);
}

void GG15::Screen::display_to_LCD()
{
    g15_send(id, framebuffer, G15_BUFSIZE);
    if (fps > 0)
    {
        usleep(int(float((1.f/fps)*1000000)));
    }
}

void GG15::Screen::copy_to_framebuffer(char copied_buff[G15_BUFSIZE])
{
    memcpy(this->framebuffer, copied_buff, G15_BUFSIZE);
}

void GG15::Screen::take_input()
{
    recv(this->id, &keystate, sizeof(keystate), 0);
}

int GG15::Screen::get_keystate()
{
    return keystate;
}

int GG15::Screen::get_screen_id()
{
    return this->id;
}

void GG15::Screen::get_framebuffer(char fb_destination[G15_BUFSIZE])
{
    memcpy(fb_destination, this->framebuffer, G15_BUFSIZE);
}

char GG15::Screen::get_pixel(int x, int y)
{
    int index = y * G15_WIDTH + x;
    return framebuffer[index];
}

void GG15::Screen::set_pixel(int x, int y, bool pixel_on)
{
    int index = y * G15_WIDTH + x;
    framebuffer[index] = pixel_on;
}

void GG15::Screen::invert_screen()
{
    for (int i=0; i != G15_BUFSIZE; i++)
    {
        framebuffer[i] = !framebuffer[i];
    }
}

void GG15::Screen::draw(GG15::Sprite &to_draw)
{
    int x_offset = 0;
    int y_offset = 0;
    std::vector<uint8_t> spr_data = to_draw.get_sprite();
        std::cout << to_draw.get_dimensions().x << ", " << to_draw.get_dimensions().y << "\n";

    for (int i=0; i!=spr_data.size(); i++)
    {
        int this_pixel_xpos = to_draw.get_position().x + x_offset;
        int this_pixel_ypos = to_draw.get_position().y + y_offset;


        if (x_offset == to_draw.get_dimensions().x-1)
        {
            y_offset++;
            x_offset = -1;
        }
        if ( (spr_data[i] == 0 || spr_data[i] == 1) && (this_pixel_xpos < G15_WIDTH && this_pixel_xpos >= 0) && (this_pixel_ypos < G15_HEIGHT && this_pixel_ypos >= 0))
        {
            set_pixel(this_pixel_xpos, this_pixel_ypos, spr_data[i]);
        } //else we dont place a pixel as this is a "transparent" pixel
        x_offset++;
    }
}

//I imagine we will want different functions for the different types of drawable as they WILL have to be drawn differently (for example, doing geometric calculations (with different formulae at that) for shapes, rather than just outputting texture data like we would with sprites)
//also, textures shouldnt be assigned to drawables, as we are going to want to assign textures to shapes differnetly than we will to drawables
