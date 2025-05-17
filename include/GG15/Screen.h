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
        char framebuffer[G15_WIDTH][G15_HEIGHT];
        int keystate = 0;
        int id; //make a getter for this?

    public: //TO DO: add an invert function that performs NOT operations on each pixel in the framebuffer
        Screen(int fps_param);
        ~Screen();


        void clear_screen(bool pixel_on); //add boolean parameter to clear with either white pixels or orange
        void display_to_LCD(); //^----update documentation to reflect this
        void take_input();
        int get_keystate();
        void copy_to_framebuffer(char copied_buff[G15_WIDTH][G15_HEIGHT]);
        int get_screen_id();
        void get_framebuffer(char fb_destination[G15_WIDTH][G15_HEIGHT]);
        char get_pixel(int x, int y);
        void set_pixel(int x, int y, bool pixel_on);
        void invert_screen();
    };
}

#endif // GG15_H
