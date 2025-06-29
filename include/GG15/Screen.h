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

/*

01/06/2025: dedicate this day to admin:
1) make a roadmap of what to do here on out github page, remember, as quickly as we want the Bad Apple project done, it is a demo for GG15, thus we need to get all major features working with it
2) after this for the rest of the day work on admin for older projects, just documentation/how to use documents for LMC naughts and crosses and Bogosearch
3) as for Bow, make the actual Bow repo private, maybe keeping the NEA project repo (if it had its own repo, (i don rember :/ ))
*/

namespace GG15
{
    class Screen
    {
    private: //make it possible to for a screen to only refresh when the user calls a certain function
        unsigned int fps = 0; //0fps = unlimited
        char framebuffer[G15_BUFSIZE];
        int keystate = 0;
        int id; //make a getter for this?

    public: //TO DO: add an invert function that performs NOT operations on each pixel in the framebuffer
        Screen(int fps_param);
        ~Screen();

        void clear_screen(bool pixel_on); //add boolean parameter to clear with either white pixels or orange

        void display_to_LCD(); //^----update documentation to reflect this
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
