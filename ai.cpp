#include "ai.h"

#include <algorithm>
#include <cassert>

ai::ai(const ai_strategy s)
  : m_strategy{s}
{

}

const action& ai::pick_action(
  const std::vector<action>& actions,
  const std::vector<card>& played_pile,
  const hand& h
) const noexcept
{
  assert(!actions.empty());
  if (actions.size() == 1) return actions.back();
  switch(m_strategy)
  {
    case ai_strategy::common_in_hand: return pick_common_in_hand(actions, played_pile, h);
    case ai_strategy::lowest_value: return pick_lowest(actions);
    case ai_strategy::highest_value: return pick_highest(actions);
    case ai_strategy::random: return pick_random(actions);
    case ai_strategy::uncommon_in_hand: return pick_uncommon_in_hand(actions, played_pile, h);
  }
}

const action& pick_common_in_hand(
  const std::vector<action>& actions,
  const std::vector<card>& played_pile,
  const hand& h
) noexcept
{
  //Count how often each action's card combines with player
  //knowledge (played pile and hand)
  std::vector<card> known = played_pile;
  std::copy(std::begin(h), std::end(h), std::back_inserter(known));
  assert(known.size() == h.size() + played_pile.size());

  const int n = actions.size();
  std::vector<int> tally(n, 0);
  for (int i=0; i!=n; ++i)
  {
    const card& action_card = actions[i].get_card();
    tally[i] = std::count_if(
      std::begin(known),
      std::end(known),
      [action_card](const card& c)
      {
        return is_combination(action_card, c);
      }
    );
  }

  //Take the value that is tallied lowest
  const int index = std::distance(
    std::begin(tally),
    std::min_element(std::begin(tally), std::end(tally))
  );
  assert(index >= 0);
  assert(index < static_cast<int>(actions.size()));
  return actions[index];
}

const action& pick_lowest(
  const std::vector<action>& actions
) noexcept
{
  return *std::min_element(std::begin(actions), std::end(actions));
}

const action& pick_highest(
  const std::vector<action>& actions
) noexcept
{
  return *std::max_element(std::begin(actions), std::end(actions));
}

const action& pick_random(
  const std::vector<action>& actions
) noexcept
{
  //Dirty RNG, but good enough for now
  const int i = std::rand() % static_cast<int>(actions.size());
  return actions[i];
}

const action& pick_uncommon_in_hand(
  const std::vector<action>& actions,
  const std::vector<card>& played_pile,
  const hand& h
) noexcept
{
  //Count how often each action's card combines with player
  //knowledge (played pile and hand)
  std::vector<card> known = played_pile;
  std::copy(std::begin(h), std::end(h), std::back_inserter(known));
  assert(known.size() == h.size() + played_pile.size());

  const int n = actions.size();
  std::vector<int> tally(n, 0);
  for (int i=0; i!=n; ++i)
  {
    const card& action_card = actions[i].get_card();
    tally[i] = std::count_if(
      std::begin(known),
      std::end(known),
      [action_card](const card& c)
      {
        return is_combination(action_card, c);
      }
    );
  }

  //Take the value that is tallied highest
  const int index = std::distance(
    std::begin(tally),
    std::max_element(std::begin(tally), std::end(tally))
  );
  assert(index >= 0);
  assert(index < static_cast<int>(actions.size()));
  return actions[index];
}
