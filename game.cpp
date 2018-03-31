#include "game.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <sstream>
#include <utility>

game::game(
  const int n_players,
  const int rng_seed
) : m_draw_pile{},
    m_hands(n_players),
    m_n_players{n_players},
    m_n_points(n_players, 112),
    m_played_pile{},
    m_player_index{0},
    m_rng_engine{rng_seed},
    m_rng_seed{rng_seed},
    m_round_index{0}
{
  assert(m_n_players >= 2);
  assert(m_n_players <= 4);

  start_round();

  assert(get_n_players() == n_players);
  assert(get_rng_seed() == rng_seed);
}

bool game::can_play(const card& c) const noexcept
{
  return is_combination(c, get_active_card());
}

std::vector<int> collect_n_points(const game& g) noexcept
{
  const int n_players = g.get_n_players();
  std::vector<int> n_points(n_players);
  for (int i=0; i!=n_players; ++i)
  {
    n_points[i] = g.get_n_points(i);
  }
  return n_points;
}

void game::do_action(const action& a)
{
  assert(is_valid());
  //Play
  if (a.get_type() == action_type::play)
  {
    m_played_pile.push_back(a.get_card());
    get_active_hand().erase(a.get_card());

    m_action_history.push_back(turn(get_player_index(), {a}));
    m_player_index = (m_player_index + 1) % get_n_players();
    assert(m_player_index >= 0 && m_player_index < 4); //It's a max 4 player game
    return;
  }
  //Must draw
  assert(a.get_type() == action_type::draw);
  assert(is_valid());
  assert(!m_draw_pile.empty());
  const auto drawn_card = m_draw_pile.back();
  m_draw_pile.pop_back();
  get_active_hand().insert(drawn_card);
  if (m_draw_pile.empty())
  {
    reshuffle();
  }

  const auto new_actions = get_actions();
  assert(new_actions.size() == 1);
  const auto& new_action = new_actions.back();
  if (new_action.get_type() == action_type::draw)
  {
    m_action_history.push_back(turn(get_player_index(), {a}));
  }
  else
  {
    m_played_pile.push_back(new_action.get_card());
    get_active_hand().erase(new_action.get_card());
    m_action_history.push_back(turn(get_player_index(), {a, new_action}));
  }
  m_player_index = (m_player_index + 1) % get_n_players();
  assert(m_player_index >= 0 && m_player_index < 4); //It's a max 4 player game
  assert(is_valid());
}

std::string draw_pile_to_str(std::vector<card> draw_pile)
{
  std::stringstream s;
  //Cards that are not yet draw, display cards on top first
  s << "(";

  //Show other cards
  std::reverse_copy(
    std::begin(draw_pile),
    std::end(draw_pile),
    std::ostream_iterator<card>(s, " ")
  );
  std::string t = s.str();
  assert(!t.empty());
  t.pop_back();
  t += ")";
  return t;
}

std::vector<action> game::get_actions() const noexcept
{
  std::vector<action> actions;

  if (has_winner())
  {
    return actions;
  }

  // Can play a card?
  const auto h = m_hands.at(m_player_index);
  if (h.empty()) return {};
  for (const card& c: h)
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
  assert(!actions.empty());
  return actions;
}

const card& game::get_active_card() const noexcept
{
  assert(!m_played_pile.empty());
  return m_played_pile.back();
}

const hand& game::get_active_hand() const noexcept
{
  assert(m_player_index >= 0);
  assert(m_player_index < static_cast<int>(m_hands.size()));
  return m_hands[m_player_index];
}

hand& game::get_active_hand() noexcept
{
  assert(m_player_index >= 0);
  assert(m_player_index < static_cast<int>(m_hands.size()));
  return m_hands[m_player_index];
}

int get_most_n_points_index(const game& g)
{
  const auto points = collect_n_points(g);
  return std::distance(
    std::begin(points),
    std::max_element(std::begin(points), std::end(points))
  );
}

int get_n_cards(const game& g) noexcept
{
  int n_cards = 0;
  const int n_players{g.get_n_players()};
  for (int i=0; i!=n_players; ++i)
  {
    n_cards += g.get_n_cards(i);
  }
  n_cards += g.get_played_pile().size() + g.get_draw_pile().size();
  return n_cards;
}

int game::get_n_points(
  const int player_index
) const noexcept
{
  assert(player_index >= 0);
  assert(player_index < static_cast<int>(m_n_points.size()));
  return m_n_points[player_index];
}

std::vector<int> get_summed_values(const game& g) noexcept
{
  const int n_players = g.get_n_players();
  std::vector<int> v(n_players);
  for (int i=0; i!=n_players; ++i)
  {
    v[i] = sum_values(g.get_player_hand(i));
  }
  return v;
}

int game::get_winner_index() const noexcept
{
  int winner_index = 0;
  for (const auto& h: m_hands)
  {
    if (h.empty()) return winner_index;
    ++winner_index;
  }
  return -1;
}

int get_worst_hand_index(const game& g)
{
  const auto values = get_summed_values(g);
  return std::distance(
    std::begin(values),
    std::max_element(std::begin(values), std::end(values))
  );
}

bool game::has_winner() const noexcept
{
  return get_winner_index() != -1;
}

bool has_bankrupt_player(const game& g)
{
  const auto points = collect_n_points(g);
  return std::count_if(
    std::begin(points),
    std::end(points),
    [](const int i) { return i <= 0; }
  );
}

bool game::is_valid() const noexcept
{
  if (::get_n_cards(*this) != 36) return false;
  if (m_player_index < 0) return false;
  if (m_player_index > m_n_players) return false;
  return true;
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

  if (played_pile.empty()) return s.str() + " ()";

  s << " (";
  std::reverse_copy(
    std::begin(played_pile),
    std::end(played_pile),
    std::ostream_iterator<card>(s, " ")
  );
  std::string t = s.str();
  assert(!t.empty());
  t.pop_back();
  t += ")";
  return t;
}

const hand& game::get_player_hand(
  const int player_index
) const noexcept
{
  assert(player_index >= 0);
  assert(player_index < static_cast<int>(m_hands.size()));
  return m_hands[player_index];
}

void game::reshuffle() noexcept
{
  assert(m_draw_pile.empty());
  m_draw_pile = m_played_pile;
  m_played_pile = { get_active_card() };
  assert(m_draw_pile.back() == get_active_card());
  m_draw_pile.pop_back();
  std::shuffle(std::begin(m_draw_pile), std::end(m_draw_pile), m_rng_engine);
  assert(is_valid());
}

void game::start_next_round()
{
  assert(has_winner());
  const int winner_index = get_winner_index();
  const int biggest_loser_index = get_worst_hand_index(*this);
  const int n_players = get_n_players();
  for (int i=0; i!=n_players; ++i)
  {
    const int n_points = sum_values(m_hands[i]);
    m_n_points[i] -= n_points;
    m_n_points[winner_index] += n_points;
  }
  ++m_round_index;
  m_player_index = biggest_loser_index;
  start_round();
  assert(!has_winner());
}

void game::start_round()
{
  //m_round_index and m_active_player_index are already set

  const int n_players = get_n_players();
  assert(n_players > 0);

  //Clear all
  m_hands = std::vector<hand>(n_players);
  m_draw_pile.clear();
  m_played_pile.clear();
  m_draw_pile.clear();

  //Deal cards
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
  //Take first card from draw pile
  m_played_pile.push_back(m_draw_pile.back());
  m_draw_pile.pop_back();

  assert(this->get_n_players() == n_players);
  //All players should have five card
  #ifndef NDEBUG
  for (const auto& h: m_hands) { assert(h.size() == 5); }
  #endif
  assert(m_draw_pile.size() > 2);
  assert(m_played_pile.size() == 1); //Only the active card
  assert(is_valid());
  assert(!m_draw_pile.empty());
}

std::ostream& operator<<(std::ostream& os, const game& g) noexcept
{
  {
    os << "Played pile:\n";
    os << played_pile_to_str(g.get_played_pile()) << '\n';
  }
  {
    os << "Player hands:\n";
    const auto n_players = g.get_n_players();
    for (int i=0; i!=n_players; ++i)
    {
      os << (i == g.get_player_index() ? '*' : ' ') << i << ": ";
      os << to_str(g.get_player_hand(i)) << '\n';
    }
  }
  {
    os << "Draw pile:\n";
    os << draw_pile_to_str(g.get_draw_pile()) << '\n';
  }
  return os;
}
