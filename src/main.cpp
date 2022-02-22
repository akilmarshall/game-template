#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

#include "api.hpp"
#include "data.hpp"
#include "raylib.h"

int main() {
    InitWindow(width, height, "raylib template");
    // define initial scene
    api::scene::init(RAYANIM);
#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(api::scene::step, fps, 1);
#else
    SetTargetFPS(fps);
    while (!WindowShouldClose()) {
        api::scene::step();
    }
#endif
    CloseWindow();
    return 0;
}
