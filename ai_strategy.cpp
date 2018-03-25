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
    case ai_strategy::highest_value: return "H";
    case ai_strategy::lowest_value: return "L";
  }
}

ai_strategy to_strategy(const char c)
{
  if (c == 'H') return ai_strategy::highest_value;
  if (c == 'L') return ai_strategy::lowest_value;
  throw std::invalid_argument(
    "char cannot be converted to ai_strategy"
  );
}

std::ostream& operator<<(std::ostream& os, const ai_strategy s) noexcept
{
  os << to_str(s);
  return os;
}
