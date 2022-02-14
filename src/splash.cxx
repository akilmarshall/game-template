#include "api.hxx"

using namespace data::scene::splash;

void api::scene::splash::init() {
    frame_counter = 0;
    t = 5;
    data::scene::splash::done = false;
}
void api::scene::splash::update() {
    if (frame_counter > (data::fps * t)) {
        data::scene::splash::done = true;
    }
    if (IsMouseButtonPressed(0)) {
        data::scene::splash::done = true;
    }
    ++frame_counter;
}
inline void f(int xlen, int ylen, float xspeed, float yspeed, float a, float b,
              int xoff, int yoff, Color color) {
    // helper function for draw
    float x = xlen * cosf((frame_counter * xspeed) + a);
    float y = ylen * sinf((frame_counter * yspeed) + b);
    DrawCircle(x + xoff, y + yoff, 5, color);
    DrawCircle(-x + xoff, -y + yoff, 5, color);
    DrawLine(x + xoff, y + yoff, -x + xoff, -y + yoff, color);
}
void api::scene::splash::draw() {
    ClearBackground(RAYWHITE);
    f(50, 50, 0.05, 0.03, 0.0, 0.0, GetScreenWidth() / 2, 150, BLACK);
    f(50, 50, 0.01, 0.03, 0.5, 0.5, GetScreenWidth() / 2, 150, RED);
    DrawText("Unknown Studios", (GetScreenWidth() / 2) - 170,
             GetScreenHeight() / 2, 40, BLACK);
    DrawText("i", (GetScreenWidth() / 2) + 114, GetScreenHeight() / 2, 40, RED);
    DrawText("Presents", (GetScreenWidth() / 2) - 70,
             (GetScreenHeight() / 2) + 40, 30, BLACK);
}
