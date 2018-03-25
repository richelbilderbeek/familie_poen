#ifndef ACTION_H
#define ACTION_H

#include <memory>

#include "action_type.h"
#include "card.h"

/// Actions can be:
///   - play a card
///   - draw a card
/// Use \link{create_draw_action} or \link{create_play_action}
/// to create an action
class action
{
public:
  action_type get_type() const noexcept { return m_type; }
  card get_card() const noexcept { return *m_card; }
private:
  action(const action_type type);
  action(const action_type type, const card& c);
  friend action create_draw_action() noexcept;
  friend action create_play_action(const card& c) noexcept;
  std::unique_ptr<card> m_card;
  action_type m_type;
};

///Create the action to draw a card
action create_draw_action() noexcept;

///Create the action to play a card
action create_play_action(const card& c) noexcept;

bool operator<(const action& lhs, const action& rhs) noexcept;

std::ostream& operator<<(std::ostream& os, const action& a) noexcept;

#endif // ACTION_H
