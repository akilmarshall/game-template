#ifndef TYPE_HPP
#define TYPE_HPP
#include <string>
#include <tuple>

#include "raylib.h"

using std::string;
using std::tuple;

enum scene_t {
    RAYANIM,
    SPLASH,
    MENU,
    CREDIT,
};
// id, text, position, size, fontsize, active, hovered
// relation types
using button = tuple<string, string, Vector2, Vector2, int, bool, bool>;
#endif
