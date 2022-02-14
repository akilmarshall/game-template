#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

#include "api.hxx"
#include "data.hxx"
#include "raylib.h"

int main() {
    InitWindow(data::width, data::height, "raylib template");
    // define initial scene
    api::scene::init(data::scene::MENU);
#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(api::scene::step, data::fps, 1);
#else
    SetTargetFPS(data::fps);
    while (!WindowShouldClose()) {
        api::scene::step();
    }
#endif
    CloseWindow();
    return 0;
}
