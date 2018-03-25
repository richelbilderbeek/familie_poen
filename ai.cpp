#include "ai.h"

#include <algorithm>
#include <cassert>

ai::ai(const ai_strategy s)
  : m_strategy{s}
{

}

action ai::pick_action(const std::vector<action>& actions)
{
  assert(!actions.empty());
  if (actions.size() == 1) return actions.back();
  if (m_strategy == ai_strategy::lowest_value)
  {
    return *std::min_element(std::begin(actions), std::end(actions));
  }
  assert(m_strategy == ai_strategy::highest_value);
  return *std::max_element(std::begin(actions), std::end(actions));
}
