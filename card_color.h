#ifndef CARD_COLOR_H
#define CARD_COLOR_H

#include <iosfwd>
#include <vector>

/// The six possible card colors
enum class card_color
{
  red,
  yellow,
  grey,
  cyan,
  pink,
  blue,
};

///Get all the six colors
std::vector<card_color> all_colors() noexcept;

std::string to_str(const card_color c) noexcept;

std::ostream& operator<<(std::ostream&, const card_color color) noexcept;

#endif // CARD_COLOR_H
