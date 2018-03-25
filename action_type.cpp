#include "action_type.h"

#include <cassert>
#include <iostream>

std::string to_str(const action_type t) noexcept
{
  switch(t)
  {
    case action_type::draw: return "draw";
    case action_type::play: return "play";
  }
  assert(!"Should not get here"); return ""; //!OCLINT
}

std::ostream& operator<<(std::ostream& os, const action_type t) noexcept
{
  os << to_str(t);
  return os;
}
