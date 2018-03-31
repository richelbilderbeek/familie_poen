#include "turn.h"

#include <cassert>

turn::turn(
  const int player_index,
  const std::vector<action>& actions
) : m_actions{actions},
    m_player_index{player_index}
{
  assert(m_player_index >= 0);
  assert(m_player_index < 4); //It's a max 4 player game
  assert(!m_actions.empty());
  assert(m_actions.size() <= 2);

}
