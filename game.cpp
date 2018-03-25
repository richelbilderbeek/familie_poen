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
    m_player_index{0},
    m_rng_engine{rng_seed},
    m_rng_seed{rng_seed}
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

  assert(this->get_n_players() == n_players);
  //All players should have five card
  for (const auto& hand: m_hands) { assert(hand.size() == 5); }
}

std::vector<action> game::get_actions() const noexcept
{
  std::vector<action> actions;

  // Can play a card?
  const auto hand = m_hands.at(m_player_index);
  if (hand.empty()) return {};
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

const card& game::get_active_card() const noexcept
{
  assert(!m_played_pile.empty());
  return m_played_pile.back();
}

auto& game::active_hand() noexcept
{
  assert(m_player_index >= 0);
  assert(m_player_index < static_cast<int>(m_hands.size()));
  return m_hands[m_player_index];
}

bool game::can_play(const card& c) const noexcept
{
  const auto top = get_active_card();
  return c.color() == top.color() || c.value() == top.value();
}

void game::do_action(const action& a)
{
  if (a.get_type() == action_type::play)
  {
    m_played_pile.push_back(a.get_card());
    active_hand().erase(a.get_card());
    m_player_index = (m_player_index + 1) % get_n_players();
    return;
  }
  assert(a.get_type() == action_type::draw);
  if (m_draw_pile.empty())
  {
    m_draw_pile = m_played_pile;
    m_played_pile = { get_active_card() };
    assert(m_draw_pile.back() == get_active_card());
    m_draw_pile.pop_back();
    std::shuffle(std::begin(m_draw_pile), std::end(m_draw_pile), m_rng_engine);
  }
  assert(!m_draw_pile.empty());
  const auto drawn_card = m_draw_pile.back();
  m_draw_pile.pop_back();
  active_hand().insert(drawn_card);

  if (get_actions().empty())
  {
    m_player_index = (m_player_index + 1) % get_n_players();
  }
  else
  {
    assert(get_actions().size() == 1);
    do_action(get_actions().back());
  }
}

std::string hash(const game& g) noexcept
{
  std::string s;
  {
    //Played pile
    //Active card is most important
    s += hash(g.get_active_card());
    auto played = g.get_played_pile();
    assert(played.back() == g.get_active_card());
    //Order of played cards is irrelevant
    played.pop_back();
    std::sort(std::begin(played), std::end(played));
    for (const card& c: played)
    {
      s += hash(c);
    }
  }
  s += "-";
  {
    //Player hands
    const int n_players = g.get_n_players();
    for (int i=0; i!=n_players; ++i)
    {
      const auto& hand = g.get_player_hand(i);
      for (const card& c: hand)
      {
        s += hash(c);
      }
      s += "-";
    }
  }
  //Draw pile order is irrelevent
  {
    auto draw = g.get_draw_pile();
    std::sort(std::begin(draw), std::end(draw));
    for (const card& c: draw)
    {
      s += hash(c);
    }
  }
  return s;
}

int game::get_n_cards(const int player_index) const
{
  return m_hands.at(player_index).size();
}

std::string played_pile_to_str(std::vector<card> played_pile)
{
  //Played cards, display cards on top first
  //First card displayed is the active card, other cards are invisible
  std::stringstream s;
  s << played_pile.back();
  played_pile.pop_back();

  s << " (";
  std::reverse_copy(
    std::begin(played_pile),
    std::end(played_pile),
    std::ostream_iterator<card>(s, " ")
  );
  std::string t = s.str();
  if (!t.empty())
  {
    t.pop_back();
    s << t;
  }
  s << ")\n";
  return s.str();
}

const std::set<card>& game::get_player_hand(
  const int player_index
) const noexcept
{
  assert(player_index >= 0);
  assert(player_index < static_cast<int>(m_hands.size()));
  return m_hands[player_index];
}

std::ostream& operator<<(std::ostream& os, const game& g) noexcept
{
  {
    os << played_pile_to_str(g.get_played_pile());
  }
  {
    //Hands
    const auto n_players = g.get_n_players();
    for (int i=0; i!=n_players; ++i)
    {
      os << (i == g.get_player_index() ? '*' : ' ') << i << ": ";
      const auto hand = g.get_player_hand(i);
      std::copy(std::begin(hand), std::end(hand),
        std::ostream_iterator<card>(os, "  ")
      );
      os << '\n';
    }
  }
  {
    //Cards that are not yet draw, display cards on top first
    auto draw_pile = g.get_draw_pile();

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
