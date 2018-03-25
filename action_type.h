#ifndef ACTION_TYPE_H
#define ACTION_TYPE_H

#include <iosfwd>

/// Type of action, as used by \link{action}
enum class action_type
{
  draw,  // draw a card from the pile
  play // play a card
};

std::string to_str(const action_type t) noexcept;

std::ostream& operator<<(std::ostream& os, const action_type t) noexcept;

#endif // ACTION_TYPE_H
