#include "api.hxx"

#include "raylib.h"

using namespace api::scene;
using namespace data::scene;

void api::scene::init(Scene scene) {
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
            /* case data::scene::AIRCONTROLLER: { */
            /*     api::scene::ACSceneInit(); */
            /* } break; */
            /* case data::scene::CREDIT: { */
            /* } break; */
    }
}
void api::scene::change(Scene scene) {
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
    }
    current = scene;
}
void api::scene::transition(Scene scene) {
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
                case data::scene::RAYANIM: {
                    rayanim::init();
                } break;
                case SPLASH: {
                    splash::init();
                } break;
                case MENU: {
                    menu::init();
                } break;
                    /* case data::scene::AIRCONTROLLER: { */
                    /*     api::scene::ACSceneInit(); */
                    /* } break; */
                    /* case data::scene::CREDIT: { */
                    /* } break; */
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
            case data::scene::RAYANIM: {
                rayanim::update();
                if (rayanim::done()) {
                    api::scene::transition(SPLASH);
                }
            } break;
            case SPLASH: {
                splash::update();
                if (splash::done()) {
                    api::scene::transition(MENU);
                }
            } break;
            case MENU: {
                menu::update();
            } break;
                /* case data::scene::AIRCONTROLLER: { */
                /*     api::scene::ACSceneUpdate(); */
                /*     if (api::scene::ACSceneDone()) { */
                /*         api::scene::transition(data::scene::AIRCONTROLLER);
                 */
                /*     } */
                /* } break; */
                /* case data::scene::CREDIT: { */
                /* } break; */
        }
    } else {
        api::scene::updateTransition();
    }
    BeginDrawing();
    switch (current) {
        case data::scene::RAYANIM: {
            rayanim::draw();
        } break;
        case SPLASH: {
            splash::draw();
        } break;
        case MENU: {
            menu::draw();
        } break;
            /* case data::scene::AIRCONTROLLER: { */
            /*     api::scene::ACSceneDraw(); */
            /* } break; */
            /* case data::scene::CREDIT: { */
            /* } break; */
    }
    if (on_transition) {
        api::scene::drawTransition();
    }
    EndDrawing();
}
