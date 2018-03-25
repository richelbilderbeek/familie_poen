#ifndef AI_STRATEGY_H
#define AI_STRATEGY_H

#include <iosfwd>
#include <vector>

enum class ai_strategy
{
  common_in_hand, //play card that is rare in play (thus common in hands)
  highest_value, // play the card with the highest value
  lowest_value, // play the card with the lowest value
  random, //play randomly
  uncommon_in_hand //play card that is common in play (thus rare in hands)
};

///Obtain a vector with all ai_strategies
std::vector<ai_strategy> all_strategies() noexcept;

std::string to_str(const ai_strategy) noexcept;

ai_strategy to_strategy(const char);

std::ostream& operator<<(std::ostream&, const ai_strategy) noexcept;

#endif // AI_STRATEGY_H
