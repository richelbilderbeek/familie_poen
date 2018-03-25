#include "ai_strategy.h"

#include <cassert>
#include <iostream>
#include <stdexcept>

std::vector<ai_strategy> all_strategies() noexcept
{
  return
  {
    ai_strategy::highest_value,
    ai_strategy::lowest_value
  };
}

std::string to_str(const ai_strategy s) noexcept
{
  switch (s)
  {
    case ai_strategy::common_in_hand: return "C";
    case ai_strategy::highest_value: return "H";
    case ai_strategy::lowest_value: return "L";
    case ai_strategy::random: return "R";
    case ai_strategy::uncommon_in_hand: return "U";
    default: assert(!"Should not get here"); return ""; //!OCLINT
  }
  assert(!"Should not get here"); return ""; //!OCLINT
}

ai_strategy to_strategy(const char c)
{
  if (c == 'C') return ai_strategy::common_in_hand;
  if (c == 'H') return ai_strategy::highest_value;
  if (c == 'L') return ai_strategy::lowest_value;
  if (c == 'R') return ai_strategy::random;
  if (c == 'U') return ai_strategy::uncommon_in_hand;
  throw std::invalid_argument(
    "char cannot be converted to ai_strategy"
  );
}

std::ostream& operator<<(std::ostream& os, const ai_strategy s) noexcept
{
  os << to_str(s);
  return os;
}
