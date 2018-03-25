#ifndef AI_H
#define AI_H

#include "ai_strategy.h"
#include "action.h"

/// Artificial intelligence to pick an action
class ai
{
public:
  ai(const ai_strategy);

  ///Pick one of the actions
  action pick_action(const std::vector<action>& actions);

private:

  ai_strategy m_strategy;
};

#endif // AI_H
