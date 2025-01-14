#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include "animation_engine/objects/animation_object.h"
#include "objects/animated_text_object.h"
#include "objects/animated_circle_object.h"
#include "objects/animated_square_object.h"
#include <unistd.h>

namespace rl
{
    #include <raylib.h>
}

namespace anim
{
    class AnimationEngine
    {
        public:
            AnimationEngine();
            AnimationEngine(const std::string& title, const int& screen_width, const int& screen_height);

            void add_object_to_animation(const AnimatedTextObject& animated_text_object);
            void add_object_to_animation(const anim::AnimatedCircleObject& animated_circle_object);
            //void add_object_to_animation(const anim::AnimatedSquareObject& animated_square_object);

            void start_animation();

            std::string title;
            int screen_width;
            int screen_height;
            rl::Font font;

        private:

            float time;

            std::vector<AnimatedTextObject> animated_text_objects;
            std::vector<AnimatedCircleObject> animated_circle_objects;
            //std::vector<AnimatedSquareObject> animated_square_objects;
    };
}