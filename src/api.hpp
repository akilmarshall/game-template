#ifndef API_HPP
#define API_HPP


#include "data.hpp"
#include "raylib.h"
#include "type.hpp"

namespace api {
namespace scene {
void init(scene_t);        // define and initialize the initial scene
void change(scene_t);      // change scene no transition
void transition(scene_t);  // transition from currentscene to scene
void updateTransition();
void drawTransition();
void step();  // void function allowing control to be passed off to a web
              // engine, central thread of control for the game
              // engine/definition of the scene graph
namespace rayanim {
void init();
void update();
void draw();
}  // namespace rayanim
namespace splash {
void init();
void update();
void draw();
}  // namespace splash
namespace menu {
void init();
void update();
void draw();
}  // namespace menu
namespace credit {
void init();
void update();
void draw();
}  // namespace credit
}  // namespace scene
namespace feeder {}
namespace observer {}
}  // namespace api
#endif
