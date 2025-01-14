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

void anim::AnimationEngine::add_object_to_animation(const anim::AnimatedCircleObject& animated_circle_object)
{
    this->animated_circle_objects.push_back(animated_circle_object);
}

//void anim::AnimationEngine::add_object_to_animation(const anim::AnimatedSquareObject& animated_square_object)
//{
//    this->animated_square_objects.push_back(animated_square_object);
//}


void anim::AnimationEngine::start_animation()
{
    rl::InitWindow(this->screen_width, this->screen_height, this->title.c_str());
    rl::SetTargetFPS(60);

    std::string font_path = "Roboto_Condensed-Medium.ttf";

    rl::Font font = rl::LoadFont(font_path.c_str());

    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    } else {
        perror("getcwd() error");
    }

    if (font.texture.id == 0) {
        printf("Failed to load font from: %s%s\n", cwd, font_path);
    }

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

        for (AnimatedCircleObject& circle_object : this->animated_circle_objects)
        {
            circle_object.draw_object(this->time);
        }

        //for (AnimatedSquareObject& square_object : this->animated_square_objects)
        //{
        //    square_object.draw_object(this->time);
        //}

        rl::DrawText("Animation window", 190, 200, 20, rl::WHITE);

        rl::DrawText(std::to_string(time).c_str(), 20, 20, 20, rl::WHITE);

        rl::EndDrawing();
    }

    rl::CloseWindow();
}