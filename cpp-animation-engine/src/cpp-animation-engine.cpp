#include "cpp-animation-engine.h"

void print_text(std::string text)
{
    std::cout << text << std::endl;
}

void test_raylib()
{
}

simple::animation_engine::animation_engine()
{
    this->title = "Example title";
    this->screen_width = 400;
    this->screen_height = 400;
}

simple::animation_engine::animation_engine(std::string title, int screen_width, int screen_height)
{
    this->title = title;
    this->screen_width = screen_width;
    this->screen_height = screen_height;
}

void simple::animation_engine::start_animation()
{
    rl::InitWindow(this->screen_width, this->screen_height, this->title.c_str());
    rl::SetTargetFPS(60);

    while (!rl::WindowShouldClose())
    {
        rl::BeginDrawing();

        rl::ClearBackground(rl::BLACK);

        rl::DrawText("Animation window", 190, 200, 20, rl::WHITE);

        rl::EndDrawing();
    }

    rl::CloseWindow();
}