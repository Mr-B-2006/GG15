/*#pragma once
#ifndef SCREEN_H
#define SCREEN_H


#define G15_SCREEN_WIDTH 160
#define G15_SCREEN_HEIGHT 43

#define G15_BLANK 0
#define G15_COLOURED 1
#define G15_COLORED 1

#include <iostream>
#include <vector>
#include <cstring>
//#include <libg15.h>
#include <g15daemon_client.h>
#include <unistd.h>
#include <sys/socket.h>

namespace GG15
{
    class Screen
    {
    private: //make it possible to for a screen to only refresh when the user calls a certain function
        int fps = 0; //0fps = unlimited
        char framebuffer[G15_BUFSIZE] = {};
        int keystate = 0;

    public:
        Screen(int fps_param);
        ~Screen();

        int id; //make a getter for this?

        void clear_screen(); //add boolean parameter to clear with either white pixels or orange
        void display_to_LCD(); //^----update documentation to reflect this
        //void draw_to_framebuffer(char );
        void take_input();
        int get_keystate();
        void copy_framebuffers(char copied_buff[G15_BUFSIZE]);
    };
}

#endif // GG15_H
*/
