#ifndef DATA_HPP
#define DATA_HPP
#include <vector>

#include "type.hpp"
using std::vector;

// relations/singletons
inline int fps = 60;
inline int width = 800;
inline int height = 600;

namespace scene {
inline scene_t current;
inline float alpha;
inline bool transition_fade_out;
inline bool on_transition;
inline scene_t from_scene;
inline scene_t to_scene;

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
inline Vector2 root;  // location of the title/menu button stack
inline int spacing;
inline vector<button> buttons;
}  // namespace menu

namespace credit {
inline int frame_counter;
inline int t;  // duration
inline bool done;
}  // namespace credit

}  // namespace scene
#endif
