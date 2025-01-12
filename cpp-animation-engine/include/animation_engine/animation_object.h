#pragma once

#include <iostream>
#include <optional>
#include <vector>
#include "animation_action.h"
#include <queue>

namespace anim
{
    class AnimationObject
    {
        public:
            AnimationObject();
            AnimationObject(const int& position_x, const int& position_y);

            virtual void draw_object(const float& current_time);

            void set_start_time(const float& new_start_time);
            void set_stop_time(const float& new_stop_time);

            float start_time;
            std::optional<float> stop_time;

            int position_x;
            int position_y;
            int position_z;

        protected:
            virtual void draw_animation_actions(const float& current_time);
            std::queue<AnimationAction> animation_actions;

        private:



    };
};

