#pragma once
#include <iostream>
#include <string>

namespace rl
{
    #include "raylib.h"
}


namespace simple
{
    class animation_engine
    {
        public:
            animation_engine();
            animation_engine(std::string title, int screen_width, int screen_height);

            void start_animation();

        private:

            std::string title;
            int screen_width;
            int screen_height;

    };
}

void print_text(std::string text);


void test_raylib();