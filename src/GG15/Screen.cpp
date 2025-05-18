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

void GG15::Screen::copy_to_framebuffer(char copied_buff[G15_WIDTH][G15_HEIGHT])
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

void GG15::Screen::get_framebuffer(char fb_destination[G15_WIDTH][G15_HEIGHT])
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

void GG15::Screen::draw(GG15::Drawable to_draw)
{

}
