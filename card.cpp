#include "card.h"

#include <cassert>
#include <set>
#include <iostream>
#include <stdexcept>

card::card(const int value, const card_color color)
  : m_color{color},
    m_value{value}
{
  if (!is_card_value(m_value)) {
    throw std::invalid_argument("Invalid card value");
  }
}

std::vector<card> all_cards() noexcept
{
  std::vector<card> cards;
  cards.reserve(36);
  for (const auto color: all_colors())
  {
    for (const int value: all_values())
    {
      cards.push_back(card(value, color));
    }
  }
  return cards;
}

std::vector<int> all_values() noexcept
{
  return {1,2,5,10,20,50};
}

std::string hash(const card& c) noexcept
{
  // most valueable info is the value of the card
  std::string s = "  ";
  switch (c.value())
  {
    case 1: s[0] = '1'; break;
    case 2: s[0] = '2'; break;
    case 5: s[0] = '3'; break;
    case 10: s[0] = '4'; break;
    case 20: s[0] = '5'; break;
    case 50: s[0] = '6'; break;
    default: assert(!"Should not get here");
  }
  s[1] = to_str(c.color())[0];
  return s;
}

bool is_card_value(const int value) noexcept
{
  const std::set<int> legal_values = {1,2,5,10,20,50};
  return legal_values.count(value) == 1;
}

bool operator==(const card& lhs, const card& rhs) noexcept
{
  return lhs.value() == rhs.value()
    && lhs.color() == rhs.color()
  ;
}

bool operator<(const card& lhs, const card& rhs) noexcept
{
  //First sort on value
  if (lhs.value() < rhs.value()) return true;
  if (lhs.value() > rhs.value()) return false;
  return static_cast<int>(lhs.color()) < static_cast<int>(rhs.color());
}

std::ostream& operator<<(std::ostream& os, const card& c) noexcept
{
  os << c.color() << c.value();
  return os;
}
