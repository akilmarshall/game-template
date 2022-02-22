#include "api.hpp"

using namespace api::scene;
using namespace scene;

void api::scene::init(scene_t scene) {
    alpha = 0.f;
    transition_fade_out = true;
    on_transition = false;
    current = scene;
    switch (scene) {
        case RAYANIM: {
            rayanim::init();
        } break;
        case SPLASH: {
            splash::init();
        } break;
        case MENU: {
            menu::init();
        } break;
        case CREDIT: {
            credit::init();
        } break;
    }
}
void api::scene::change(scene_t scene) {
    switch (scene) {
        case RAYANIM: {
            rayanim::init();
        } break;
        case SPLASH: {
            splash::init();
        } break;
        case MENU: {
            menu::init();
        } break;
        case CREDIT: {
            credit::init();
        } break;
    }
    current = scene;
}
void api::scene::transition(scene_t scene) {
    on_transition = true;
    transition_fade_out = false;
    from_scene = current;
    to_scene = scene;
    alpha = 0.f;
}
void api::scene::updateTransition() {
    if (!transition_fade_out) {
        alpha += 0.05f;
        if (alpha > 1.01f) {
            alpha = 1.f;
            // initialize next scene
            switch (to_scene) {
                case RAYANIM: {
                    rayanim::init();
                } break;
                case SPLASH: {
                    splash::init();
                } break;
                case MENU: {
                    menu::init();
                } break;
                case CREDIT: {
                    credit::init();
                } break;
            }
            current = to_scene;
            transition_fade_out = true;
        }
    } else {
        alpha -= 0.02;
        if (alpha < -0.01f) {
            alpha = 0.f;
            transition_fade_out = false;
            on_transition = false;
        }
    }
}
void api::scene::drawTransition() {
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(),
                  Fade(BLACK, alpha));
}

void api::scene::step() {
    if (!on_transition) {
        switch (current) {
            case RAYANIM: {
                rayanim::update();
                if (::scene::rayanim::done) {
                    transition(SPLASH);
                }
            } break;
            case SPLASH: {
                splash::update();
                if (::scene::splash::done) {
                    transition(MENU);
                }
            } break;
            case MENU: {
                menu::update();
            } break;
            case CREDIT: {
                credit::update();
                if (::scene::credit::done) {
                    transition(MENU);
                }
            } break;
        }
    } else {
        updateTransition();
    }
    BeginDrawing();
    switch (current) {
        case RAYANIM: {
            rayanim::draw();
        } break;
        case SPLASH: {
            splash::draw();
        } break;
        case MENU: {
            menu::draw();
        } break;
        case CREDIT: {
            credit::draw();
        } break;
    }
    if (on_transition) {
        drawTransition();
    }
    EndDrawing();
}
