#include <iostream>
#include "animation_engine/animation_engine.h"
#include "animation_engine/animated_text_object.h"

int main()
{
    anim::AnimationEngine animation_engine("Simple animation", 800, 800);
    anim::AnimatedTextObject text1("text", 400, 400);
    text1.start_time = 5;
    text1.stop_time = 10;

    animation_engine.add_object_to_animation(text1);
    

    //animation_engine.animation_objects.push_back(&text1);

    animation_engine.start_animation();
}
