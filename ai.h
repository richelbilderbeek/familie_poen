#ifndef AI_H
#define AI_H

#include "ai_strategy.h"
#include "action.h"
#include "hand.h"

/// Artificial intelligence to pick an action
class ai
{
public:
  ai(const ai_strategy);

  ///Pick one of the actions
  const action& pick_action(
    const std::vector<action>& actions,
    const std::vector<card>& played_pile,
    const hand& hand
  ) const noexcept;

private:

  ai_strategy m_strategy;
};

const action& pick_common_in_hand(
  const std::vector<action>& actions,
  const std::vector<card>& played_pile,
  const hand& hand
) noexcept;

std::vector<ai> create_ais(const std::vector<ai_strategy>& strategies) noexcept;

const action& pick_lowest(const std::vector<action>& actions) noexcept;
const action& pick_highest(const std::vector<action>& actions) noexcept;
const action& pick_random(const std::vector<action>& actions) noexcept;

const action& pick_uncommon_in_hand(
  const std::vector<action>& actions,
  const std::vector<card>& played_pile,
  const hand& hand
) noexcept;

#endif // AI_H
