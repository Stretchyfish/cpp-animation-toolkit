#include <iostream>
#include "cpp-animation-engine.h"

int main()
{
    simple::animation_engine animation_engine("Simple animation", 800, 800);
    animation_engine.start_animation();
}
