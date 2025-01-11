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
    rl::InitWindow(this->screen_width, this->screen_height, this->title.c_str());
    rl::SetTargetFPS(60);

    while (!rl::WindowShouldClose())
    {
        float delta_time = rl::GetFrameTime();
        this->time += delta_time;

        rl::BeginDrawing();

        rl::ClearBackground(rl::BLACK);

        for (AnimatedTextObject& text_object : this->animated_text_objects)
        {
            text_object.draw_object(this->time);

        }

        rl::DrawText("Animation window", 190, 200, 20, rl::WHITE);

        rl::DrawText(std::to_string(time).c_str(), 20, 20, 20, rl::WHITE);

        rl::EndDrawing();
    }

    rl::CloseWindow();
}