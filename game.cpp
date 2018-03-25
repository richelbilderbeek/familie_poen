#include "game.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <sstream>
game::game(
  const int n_players,
  const int rng_seed
) : m_draw_pile{},
    m_hands(n_players),
    m_played_pile{},
    m_rng_engine{rng_seed},
    m_rng_seed{rng_seed},
    m_state{game_state::running}
{
  auto cards = all_cards();
  std::shuffle(std::begin(cards), std::end(cards), m_rng_engine);
  for (int player_index = 0; player_index!=n_players; ++player_index)
  {
    for (int card_index = 0; card_index!=5; ++card_index)
    {
      m_hands[player_index].insert(cards.back());
      cards.pop_back();
    }
  }
  m_draw_pile = cards;
  //Draw first card
  m_played_pile.push_back(m_draw_pile.back());
  m_draw_pile.pop_back();

  assert(state() == game_state::running);
  assert(this->n_players() == n_players);
  //All players should have five card
  for (const auto& hand: m_hands) { assert(hand.size() == 5); }
}

std::vector<action> game::actions() const noexcept
{
  std::vector<action> actions;

  // Can play a card?
  const auto hand = m_hands.at(m_player_index);
  for (const card& c: hand)
  {
    if (can_play(c))
    {
      actions.push_back(create_play_action(c));
    }
  }

  // No card can be played, create a draw action
  if (actions.empty())
  {
    actions.push_back(create_draw_action());
  }

  return actions;
}

const card& game::active_card() const noexcept
{
  assert(!m_played_pile.empty());
  return m_played_pile.back();
}

bool game::can_play(const card& c) const noexcept
{
  const auto top = active_card();
  return c.color() == top.color() || c.value() == top.value();
}

void game::do_action(const action& a)
{
  if (a.get_type() == action_type::play)
  {
    m_played_pile.push_back(a.get_card());
    active_hand().erase(a.get_card());
    m_player_index = (m_player_index + 1) % n_players();
    return;
  }
  assert(a.get_type() == action_type::draw);

}

int game::n_cards(const int player_index) const
{
  return m_hands.at(player_index).size();
}

std::ostream& operator<<(std::ostream& os, const game& g) noexcept
{
  {
    //Played cards, display cards on top first
    //First card displayed is the active card, other cards are invisible
    auto played_pile = g.played_pile();
    os << played_pile.back();
    played_pile.pop_back();

    std::stringstream s;
    os << " (";
    std::reverse_copy(
      std::begin(played_pile),
      std::end(played_pile),
      std::ostream_iterator<card>(s, " ")
    );
    std::string t = s.str();
    if (!t.empty())
    {
      t.pop_back();
      os << t;
    }
    os << ")\n";
  }
  {
    //Hands
    const auto n_players = g.n_players();
    for (int i=0; i!=n_players; ++i)
    {
      os << (i == g.player_index() ? '*' : ' ') << i << ": ";
      const auto hand = g.player_hand(i);
      std::copy(std::begin(hand), std::end(hand),
        std::ostream_iterator<card>(os, "  ")
      );
      os << '\n';
    }
  }
  {
    //Cards that are not yet draw, display cards on top first
    auto draw_pile = g.draw_pile();

    //Show active card
    os << "(";

    //Show other cards
    std::stringstream s;
    std::reverse_copy(
      std::begin(draw_pile),
      std::end(draw_pile),
      std::ostream_iterator<card>(s, " ")
    );
    std::string t = s.str();
    t.pop_back();
    os << t << ")\n";
  }
  return os;
}
