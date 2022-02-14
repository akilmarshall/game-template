/* [Accidental]
 * - gui/api (handle the users input, structured output)
 * - feeders
 * - observers
 */
#ifndef API_HXX
#define API_HXX

#include <cmath>

#include "data.hxx"
#include "raylib.h"

namespace api {
namespace scene {
void init(data::scene::Scene);        // define and initialize the initial scene
void change(data::scene::Scene);      // change scene no transition
void transition(data::scene::Scene);  // transition from currentscene to scene
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
