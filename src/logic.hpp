#ifndef LOGIC_HPP
#define LOGIC_HPP
#include <string>

#include "type.hpp"
using std::string;

namespace pure {
// button queries
/* string id(button); */
/* string text(button); */
/* Vector2 position(button); */
/* Vector2 size(button); */
/* int fontsize(button); */
/* bool active(button); */
/* bool hovered(button); */
// id, text, position, size, fontsize, active, hovered
button button(string, string, Vector2, Vector2, Vector2, int, bool, bool);
}  // namespace pure
namespace derived {}
namespace constraint {}
#endif
