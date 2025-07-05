#pragma once
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
#include <g15daemon_client.h>
#include <unistd.h>
#include <sys/socket.h>

#include "Drawable.h"
#include "Sprite.h"


namespace GG15
{
    class Screen
    {
    private:
        unsigned int fps = 0; //0fps = unlimited, not recommended, will probably cause G15daemon to be unstable
        char framebuffer[G15_BUFSIZE];
        int keystate = 0;
        int id;

    public:
        Screen(int fps_param);
        ~Screen();

        void clear_screen(bool pixel_on);

        void display_to_LCD(); //^----update documentation cause we now have clear screen with pixel on or pixel of parameter
        void take_input();
        int get_keystate();
        void copy_to_framebuffer(char copied_buff[G15_BUFSIZE]);
        int get_screen_id();
        void get_framebuffer(char fb_destination[G15_BUFSIZE]);
        char get_pixel(int x, int y);
        void set_pixel(int x, int y, bool pixel_on);
        void invert_screen();
        void draw(GG15::Sprite &to_draw);
    };
}

#endif // GG15_H
