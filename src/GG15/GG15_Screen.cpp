/*#include <g15daemon_client.h>
#include "GG15_Screen.h"

GG15::Screen(int fps_param)
{
    id = new_g15_screen(G15_PIXELBUF);
    fps = fps_param;
    if (id < 0)
    {
        perror("Could not open G15daemon"); //maybe make it so we output an error when we see that the G15 has been disconnected, maybe maybe even try to have us be able to reconnect without restarting the program (be bale to reconnect the G15 while maintaining current program state)

    }
}

GG15::~Screen()
{
    g15_close_screen(id);
}

void GG15::Screen::clear_screen()
{
    char frame_clr[6880] = {}; //clear screen
    memcpy(framebuffer, frame_clr, 6880);
}

void GG15::Screen::display_to_LCD()
{

    g15_send(id, framebuffer, 6880);
    if (fps > 0)
    {
        usleep(int(float((1.f/fps)*1000000)));
    }
}

void GG15::Screen::copy_framebuffers(char copied_buff[G15_BUFSIZE])
{
    memcpy(this->framebuffer, copied_buff, G15_BUFSIZE);
}

void GG15::Screen::take_input()
{
    recv(this->id, &this->keystate, sizeof(this->keystate), 0);
}

int GG15::Screen::get_keystate()
{
    return keystate;
}
*/
