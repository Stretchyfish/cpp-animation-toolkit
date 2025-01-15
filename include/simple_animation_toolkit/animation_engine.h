#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include "simple_animation_toolkit/objects/animation_object.h"
#include "simple_animation_toolkit/objects/animated_text_object.h"
#include "simple_animation_toolkit/objects/animated_circle_object.h"
#include "simple_animation_toolkit/objects/animated_square_object.h"
#include <unistd.h>

namespace rl
{
    #include <raylib.h>
}

namespace sat // namespace simple animation toolkit (sat)
{
    class AnimationEngine
    {
        public:
            AnimationEngine();
            AnimationEngine(const std::string& title, const int& screen_width, const int& screen_height);

            void add_object_to_animation(const AnimatedTextObject& animated_text_object);
            void add_object_to_animation(const AnimatedCircleObject& animated_circle_object);
            void add_object_to_animation(const AnimatedSquareObject& animated_square_object);

            void start_animation();

            std::string title;
            int screen_width;
            int screen_height;
            rl::Font font;

        private:

            float time;

            std::vector<AnimatedTextObject> animated_text_objects;
            std::vector<AnimatedCircleObject> animated_circle_objects;
            std::vector<AnimatedSquareObject> animated_square_objects;
    };
}