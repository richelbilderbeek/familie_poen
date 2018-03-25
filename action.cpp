#include "action.h"

#include <cassert>
#include <iostream>

action::action(action_type type)
  : m_card{},
    m_type{type}
{

}

action::action(action_type type, const card& c)
  : m_card{c},
    m_type{type}
{

}

action create_draw_action() noexcept
{
  return action(action_type::draw);
}

action create_play_action(const card& c) noexcept
{
  return action(action_type::play, c);
}

bool operator<(const action& lhs, const action& rhs) noexcept
{
  assert(lhs.get_type() == action_type::play);
  assert(rhs.get_type() == action_type::play);
  return lhs.get_card() < rhs.get_card();
}

std::ostream& operator<<(std::ostream& os, const action& a) noexcept
{
  os << a.get_type();
  if (a.get_type() == action_type::play)
  {
    os << " " << a.get_card();
  }
  return os;
}
