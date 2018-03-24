#include "card_color.h"

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
};

std::string to_str(const card_color c) noexcept
{
  switch (c)
  {
    case card_color::red: return "red";
    case card_color::yellow: return "yellow";
    case card_color::grey: return "grey";
    case card_color::cyan: return "cyan";
    case card_color::pink: return "pink";
    default:
    case card_color::blue: return "blue";
  }

}

std::ostream& operator<<(std::ostream& os, const card_color color) noexcept
{
  os << to_str(color);
  return os;
}
