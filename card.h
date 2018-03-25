#ifndef CARD_H
#define CARD_H

#include "card_color.h"

#include <iosfwd>
#include <vector>

///A card has 6 colors and one of the possible values of 1,2,5,10,20,50
class card
{
public:
  card(const int value, const card_color color);
  card_color get_color() const noexcept { return m_color; }
  int get_value() const noexcept { return m_value; }
private:
  card_color m_color;
  int m_value;
};

/// All the cards in the game
std::vector<card> all_cards() noexcept;

/// All the possible card values
std::vector<int> all_values() noexcept;

///Is the value a valid card value?
bool is_card_value(const int value) noexcept;

///Do the cards share an equal color or value?
bool is_combination(const card& lhs, const card& rhs);

bool operator==(const card& lhs, const card& rhs) noexcept;
bool operator<(const card& lhs, const card& rhs) noexcept;

std::ostream& operator<<(std::ostream& os, const card& c) noexcept;

#endif // CARD_H
