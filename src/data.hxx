/* [Essential]
 * "relational" definitions of the stateful components of the system
 */
#ifndef DATA_HXX
#define DATA_HXX

#include <iostream>
#include <vector>

#include "raylib.h"

using std::string;
using std::vector;

namespace data {
struct Button {
    string id;  // primary key
    string text;
    Vector2 position;
    Vector2 size;
    int fontsize;
    bool active;
    bool hovered;
};

inline int fps = 60;
inline int width = 800;
inline int height = 600;

namespace scene {
enum Scene {
    RAYANIM,
    SPLASH,
    MENU,
};
inline Scene current;
inline float alpha;
inline bool transition_fade_out;
inline bool on_transition;
inline Scene from_scene;
inline Scene to_scene;

namespace rayanim {
inline int frame_counter;
inline bool done;
inline int logoX;
inline int logoY;
inline int letterCount;
inline int top;
inline int left;
inline int bottom;
inline int right;
inline int state;
}  // namespace rayanim

namespace splash {
inline int frame_counter;
inline bool done;
inline int t;  // duration of animation (seconds)
}  // namespace splash

namespace menu {
inline int frame_counter;
inline string title;
inline int titlesize;
inline Vector2 root;
inline int spacing;
inline vector<Button> buttons;
}  // namespace menu

}  // namespace scene

}  // namespace data
#endif
