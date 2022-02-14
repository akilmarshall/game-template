#include "api.hxx"

using namespace data::scene::menu;

void api::scene::menu::init() {
    frame_counter = 0;
    title = "Menu";
    titlesize = 40;
    root = Vector2{.x = (1 / 2.f) * GetScreenWidth(),
                   .y = (1 / 5.f) * GetScreenHeight()};
    spacing = 40;
    buttons.push_back(data::Button{
        .id = "splash",
        .text = "Splash Scene",
        .position = Vector2{.x = root.x, .y = root.y + (2 * spacing)},
        .size = Vector2{.x = 200, .y = 30},
        .fontsize = 20,
        .active = false,
        .hovered = false,
    });
    buttons.push_back(data::Button{
        .id = "rayanim",
        .text = "Raylib Logo Scene",
        .position = Vector2{.x = root.x, .y = root.y + (3 * spacing)},
        .size = Vector2{.x = 200, .y = 30},
        .fontsize = 20,
        .active = false,
        .hovered = false,
    });
    buttons.push_back(data::Button{
        .id = "credit",
        .text = "Game Credits",
        .position = Vector2{.x = root.x, .y = root.y + (4 * spacing)},
        .size = Vector2{.x = 200, .y = 30},
        .fontsize = 20,
        .active = false,
        .hovered = false,
    });
}
void api::scene::menu::update() {
    auto mouse = GetMousePosition();
    // handle input
    ++frame_counter;
    // buttons
    for (auto &b : buttons) {
        auto region = Rectangle{b.position.x - (b.size.x / 2), b.position.y,
                                b.size.x, b.size.y};
        if (CheckCollisionPointRec(mouse, region) && IsMouseButtonPressed(0)) {
            // button pressed
            b.active = !b.active;
            b.hovered = false;
            // transition to a new scene
            if (b.id == "splash") {
                api::scene::transition(data::scene::SPLASH);
            } else if (b.id == "rayanim") {
                api::scene::transition(data::scene::RAYANIM);
            } else if (b.id == "credit") {
                api::scene::transition(data::scene::CREDIT);
            }
        } else if (CheckCollisionPointRec(mouse, region)) {
            // button hovered
            b.hovered = true;
        } else {
            // no interaction
            b.hovered = false;
        }
    }
}
void api::scene::menu::draw() {
    ClearBackground(RAYWHITE);
    DrawText(title.c_str(),
             root.x - (MeasureText(title.c_str(), titlesize) / 2.0), root.y,
             titlesize, BLACK);

    // draw buttons
    for (auto &b : buttons) {
        Color c;
        Color text_color;
        if (b.active) {
            c = DARKGRAY;
            text_color = RED;
        } else if (b.hovered) {
            c = GRAY;
            text_color = DARKPURPLE;
        } else {
            c = GRAY;
            text_color = RED;
        }
        auto x = b.position.x - (MeasureText(title.c_str(), titlesize) / 2.f);
        auto y = b.position.y;
        auto region = Rectangle{x, y, b.size.x, b.size.y};
        DrawRectangleRec(region, c);
        DrawText(b.text.c_str(), x, y, b.fontsize, text_color);
    }
}

