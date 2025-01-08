#include "animation_engine/animation_engine.h"

anim::AnimationEngine::AnimationEngine()
{
    this->title = "Example title";
    this->screen_width = 400;
    this->screen_height = 400;
}

anim::AnimationEngine::AnimationEngine(const std::string& title, const int& screen_width, const int& screen_height)
{
    this->title = title;
    this->screen_width = screen_width;
    this->screen_height = screen_height;
}

void anim::AnimationEngine::add_object_to_animation(const anim::AnimatedTextObject& animated_text_object)
{
    this->animated_text_objects.push_back(animated_text_object);
}

void anim::AnimationEngine::start_animation()
{
    InitWindow(this->screen_width, this->screen_height, this->title.c_str());
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        for (AnimatedTextObject& text_object : this->animated_text_objects)
        {
            DrawText(text_object.text.c_str(), text_object.position_x, text_object.position_y, 20, WHITE);            
        }

        DrawText("Animation window", 190, 200, 20, WHITE);
        
        EndDrawing();
    }

    CloseWindow();
}