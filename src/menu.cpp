#include "api.hpp"

using namespace scene::menu;

void api::scene::menu::init() {
    frame_counter = 0;
    title = "Menu";
    titlesize = 40;
    root = Vector2{.x = (1 / 2.f) * GetScreenWidth(),
                   .y = (1 / 5.f) * GetScreenHeight()};
    spacing = 40;
    buttons.push_back(button("splash", "Splash Scene",
                             Vector2{.x = root.x, .y = root.y + (2 * spacing)},
                             Vector2{.x = 200, .y = 30}, 20, false, false));
    buttons.push_back(button("rayanim", "Raylib Logo Scene",
                             Vector2{.x = root.x, .y = root.y + (3 * spacing)},
                             Vector2{.x = 200, .y = 30}, 20, false, false));
    buttons.push_back(button("credit", "Game Credits",
                             Vector2{.x = root.x, .y = root.y + (4 * spacing)},
                             Vector2{.x = 200, .y = 30}, 20, false, false));
}
void api::scene::menu::update() {
    auto mouse = GetMousePosition();
    // handle input
    ++frame_counter;
    // buttons
    for (auto &[id, text, pos, size, fontsize, active, hovered] : buttons) {
        auto region = Rectangle{pos.x - (size.x / 2), pos.y, size.x, size.y};
        if (CheckCollisionPointRec(mouse, region) && IsMouseButtonPressed(0)) {
            // button pressed
            active = !active;
            hovered = false;
            // transition to a new scene
            if (id == "splash") {
                api::scene::transition(SPLASH);
            } else if (id == "rayanim") {
                api::scene::transition(RAYANIM);
            } else if (id == "credit") {
                api::scene::transition(CREDIT);
            }
        } else if (CheckCollisionPointRec(mouse, region)) {
            // button hovered
            hovered = true;
        } else {
            // no interaction
            hovered = false;
        }
    }
}
void api::scene::menu::draw() {
    ClearBackground(RAYWHITE);
    DrawText(title.c_str(),
             root.x - (MeasureText(title.c_str(), titlesize) / 2.0), root.y,
             titlesize, BLACK);

    // draw buttons
    for (auto &[id, text, pos, size, fontsize, active, hovered] : buttons) {
        Color c;
        Color text_color;
        if (active) {
            c = DARKGRAY;
            text_color = RED;
        } else if (hovered) {
            c = GRAY;
            text_color = DARKPURPLE;
        } else {
            c = GRAY;
            text_color = RED;
        }
        auto x = pos.x - (MeasureText(title.c_str(), titlesize) / 2.f);
        auto y = pos.y;
        auto region = Rectangle{x, y, size.x, size.y};
        DrawRectangleRec(region, c);
        DrawText(text.c_str(), x, y, fontsize, text_color);
    }
}

