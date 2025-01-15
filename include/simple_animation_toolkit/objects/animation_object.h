#pragma once

#include <iostream>
#include <optional>
#include <vector>
#include <queue>

#include "simple_animation_toolkit/actions/animation_action.h"

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
            float size;

            void add_position_move_instant_after(const float& new_position_x, const float& new_position_y, const float& time_to_update_position);
            void add_position_move_linear_after(const float& new_position_x, const float& new_position_y, const float& time_to_update_position, const float& duration);
            void add_size_change_instant_after(const float& new_size, const float& time_to_update_position);
            void add_size_change_linear_after(const float& new_size, const float& time_to_update_position, const float& duration);

        protected:
            virtual void draw_animation_actions(const float& current_time);
            std::queue<AnimationAction> animation_actions;

        private:



    };
};

