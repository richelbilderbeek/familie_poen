#include "card_color.h"

#include <cassert>
#include <string>

std::vector<card_color> all_colors() noexcept
{
  return
  {
    card_color::red,
    card_color::yellow,
    card_color::grey,
    card_color::cyan,
    card_color::pink,
    card_color::blue
  };
}

std::string to_str(const card_color c) noexcept
{
  switch (c)
  {
    case card_color::red: return "R";
    case card_color::yellow: return "Y";
    case card_color::grey: return "G";
    case card_color::cyan: return "C";
    case card_color::pink: return "P";
    case card_color::blue: return "B";
  }
  assert(!"Should not get here"); return ""; //!OCLINT
}

std::ostream& operator<<(std::ostream& os, const card_color color) noexcept
{
  os << to_str(color);
  return os;
}
