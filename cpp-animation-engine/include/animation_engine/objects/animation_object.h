#pragma once

#include <iostream>
#include <optional>
#include <vector>
#include <queue>

#include "animation_engine/actions/animation_action.h"

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

            float position_x;
            float position_y;
            float position_z;

            float position_before_an_action_x;
            float position_before_an_action_y;

        protected:
            virtual void draw_animation_actions(const float& current_time);
            std::queue<AnimationAction> animation_actions;

        private:



    };
};

