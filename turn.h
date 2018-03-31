#ifndef TURN_H
#define TURN_H

#include "action.h"

#include <vector>

///A turn consists out of the one or two actions a player makes, which
/// can be any of these three: (1) play, (2) draw, or (3) draw and play
class turn
{
public:
  turn(
    const int player_index,
    const std::vector<action>& actions
  );
  private:
  std::vector<action> m_actions;
  int m_player_index;
};

#endif // TURN_H
