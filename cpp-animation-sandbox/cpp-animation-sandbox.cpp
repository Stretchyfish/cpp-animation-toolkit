#include <iostream>
#include "animation_engine/animation_engine.h"
#include "animation_engine/objects/animated_text_object.h"
#include "animation_engine/objects/animated_circle_object.h"
#include "animation_engine/objects/animated_square_object.h"

int main()
{
    anim::AnimationEngine animation_engine("Simple animation", 800, 800);

    anim::AnimatedTextObject text1("text", 400, 400);
    text1.start_time = 2;
    text1.stop_time = 10;

    text1.add_size_change_linear_after(50, 3, 7);

    anim::AnimatedCircleObject circle1(50, 0, 0);
    circle1.start_time = 3;
    circle1.stop_time = 7;
    //circle1.add_position_move_instant_after(200, 200, 1);
    //circle1.add_position_move_linear_after(200, 200, 1, 5);
    circle1.add_size_change_linear_after(100, 1, 3);

    //anim::AnimatedSquareObject square1(50, 100, 200);

    //text1.add_position_move_after(300, 300, 1);
    //text1.add_position_move_linearly_after(800, 800, 3, 5);

    //text1.add_position_move_linearly_after(700, 700, 3, 8);
    //text1.update_position_after(700, 700, 2);
    //text1.move_position_linearly_after(400, 400, 4, 2);

    animation_engine.add_object_to_animation(text1);
    animation_engine.add_object_to_animation(circle1);

    animation_engine.start_animation();
}
