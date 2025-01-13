#include <iostream>
#include "animation_engine/animation_engine.h"
#include "animation_engine/objects/animated_text_object.h"

int main()
{
    anim::AnimationEngine animation_engine("Simple animation", 800, 800);
    anim::AnimatedTextObject text1("text", 400, 400);
    text1.start_time = 2;
    text1.stop_time = 100;

    text1.add_position_move_after(300, 300, 1);

    //text1.add_size_change_after(50, 2);
    text1.add_size_change_after(50, 2, 4);

    text1.add_position_move_linearly_after(700, 700, 3, 8);
    //text1.update_position_after(700, 700, 2);
    //text1.move_position_linearly_after(400, 400, 4, 2);



    animation_engine.add_object_to_animation(text1);
    
    animation_engine.start_animation();
}
