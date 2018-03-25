#include "action_type.h"

#include <iostream>

std::string to_str(const action_type t) noexcept
{
  switch(t)
  {
    case action_type::draw: return "draw";
    default:
    case action_type::play: return "play";
  }
}

std::ostream& operator<<(std::ostream& os, const action_type t) noexcept
{
  os << to_str(t);
  return os;
}
