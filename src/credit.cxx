#include "api.hxx"

using namespace data::scene::credit;

void api::scene::credit::init() {
    frame_counter = 0;
    t = 10;
    data::scene::credit::done = false;
}
void api::scene::credit::update() {
    //
    if (frame_counter / data::fps >= t) {
        done = true;
    }
    ++frame_counter;
}
void api::scene::credit::draw() {
    ClearBackground(RAYWHITE);
    auto text = "Thanks for playing!";
    auto fs = 40;
    auto a = MeasureText(text, fs) / 2.f;
    DrawText(text, (GetScreenWidth() / 2.f) - a, GetScreenHeight() / 3.f, fs,
             BLACK);
}
