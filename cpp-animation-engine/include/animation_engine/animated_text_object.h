#pragma once

#include "animation_object.h"
#include <string>

namespace anim
{
    class AnimatedTextObject : public AnimationObject
    {
        public:
            AnimatedTextObject();
            AnimatedTextObject(std::string text, int position_x, int position_y);

            std::string text; // @TODO, should this be a private variable, accessed with a public function?
        private:

    };
};
