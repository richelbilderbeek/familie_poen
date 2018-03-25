#ifndef AI_STRATEGY_H
#define AI_STRATEGY_H

#include <iosfwd>
#include <vector>

enum class ai_strategy
{
  highest_value, // play the card with the highest value
  lowest_value // play the card with the lowest value
};

///Obtain a vector with all ai_strategies
std::vector<ai_strategy> all_strategies() noexcept;

std::string to_str(const ai_strategy) noexcept;

ai_strategy to_strategy(const char);

std::ostream& operator<<(std::ostream&, const ai_strategy) noexcept;

#endif // AI_STRATEGY_H
