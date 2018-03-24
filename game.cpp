#include "game.h"

#include <algorithm>
#include <cassert>

game::game(const int n_players)
  : m_discarded{},
    m_hands(n_players),
    m_pile{},
    m_state{game_state::running}
{
  auto cards = all_cards();
  std::random_shuffle(std::begin(cards), std::end(cards));
  for (int player_index = 0; player_index!=n_players; ++player_index)
  {
    for (int card_index = 0; card_index!=5; ++card_index)
    {
      m_hands[player_index].push_back(cards.back());
      cards.pop_back();
    }
  }
  m_pile = cards;

  assert(state() == game_state::running);
  assert(this->n_players() == n_players);
  //All players should have five card
  for (const auto& hand: m_hands) { assert(hand.size() == 5); }
}

const card& game::active_card() const noexcept
{
  assert(!m_pile.empty());
  return m_pile.back();
}

bool game::can_do_move(const int player_index) const
{
  const auto hand = m_hands.at(player_index);
  return std::count_if(
    std::begin(hand),
    std::end(hand),
    [this](const card& c){ return can_play(c); }
  );
}

bool game::can_play(const card& c) const noexcept
{
  const auto top = active_card();
  return c.color() == top.color() || c.value() == top.value();
}

int game::n_cards(const int player_index) const
{
  return m_hands.at(player_index).size();
}
