#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include "animation_engine/animation_object.h"
#include "animated_text_object.h"

#include <raylib.h>

namespace anim
{
    class AnimationEngine
    {
        public:
            AnimationEngine();
            AnimationEngine(const std::string& title, const int& screen_width, const int& screen_height);

            void add_object_to_animation(const AnimatedTextObject& animated_text_object);

            void start_animation();

            std::string title;
            int screen_width;
            int screen_height;

        private:
            std::vector<AnimatedTextObject> animated_text_objects;
    };
}