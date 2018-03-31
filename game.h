#ifndef GAME_H
#define GAME_H

#include "action.h"
#include "card.h"
#include "hand.h"
#include "turn.h"

#include <random>
#include <vector>

/// Game logic
class game
{
public:
  game(const int get_n_players, const int rng_seed);

  ///Do an action
  void do_action(const action& a);

  ///Get the history of all actions
  const auto& get_action_history() const noexcept { return m_action_history; }

  ///Get all valid actions.
  ///Will return no actions if there is a winner.
  ///If there is a winner, call 'start_next_round'
  std::vector<action> get_actions() const noexcept;

  ///Top card of the played pile
  const card& get_active_card() const noexcept;

  ///Get the currently active hand, the hand of the current player
  const hand& get_active_hand() const noexcept;

  ///Get the draw pile
  const auto& get_draw_pile() const noexcept { return m_draw_pile; }

  ///Get the RNG seed
  int get_rng_seed() const noexcept { return m_rng_seed; }

  ///Get the number of cards a player has
  int get_n_cards(const int get_player_index) const;

  ///Get the number of players
  int get_n_players() const noexcept { return m_hands.size(); }

  ///Get the number of points/credits/coins/money a player has
  int get_n_points(const int player_index) const noexcept;

  ///Get the played pile, card that are actively put on it
  const auto& get_played_pile() const noexcept { return m_played_pile; }

  ///Get a player's hand
  const hand& get_player_hand(const int get_player_index) const noexcept;

  ///Index of the active player
  int get_player_index() const noexcept { return m_player_index; }

  ///The index of the winner. Returns -1 if there is no winner
  int get_winner_index() const noexcept;

  ///Is there a winner? That is, is there a player with
  ///zero cards in hand?
  bool has_winner() const noexcept;

  ///If there is a winner, start the next round
  ///Will throw if there is no winner yet
  void start_next_round();

private:

  ///History of all actions
  ///int: player index
  ///action: the action done
  std::vector<turn> m_action_history;

  ///The pile of cards to draw from
  std::vector<card> m_draw_pile;

  ///The cards in the hands of the players.
  ///The human player is always at index 0
  std::vector<hand> m_hands;

  ///The number of points/credits/coins/money a player has
  std::vector<int> m_n_points;

  ///The cards that are played, the top card is the active card
  std::vector<card> m_played_pile;

  ///Index of the player whose turn it is; the active player
  int m_player_index;

  ///The RNG engine
  std::mt19937 m_rng_engine;

  ///The RNG seed
  const int m_rng_seed;

  ///The index of the round. First round has index 0.
  ///At round index 'x', player 'x % n_players' starts
  int m_round_index;

  ///Get the currently active hand, the hand of the current player
  hand& get_active_hand() noexcept;

  ///Can the card be played?
  bool can_play(const card& c) const noexcept;

  ///Is the game in a valid state, for example,
  ///are there still 36 cards in all piles?
  bool is_valid() const noexcept;

  /// If the draw pile is empty, shuffle to played card
  /// in the draw pile
  void reshuffle() noexcept;

  /// Deal all the cards, called after start_next_round
  void start_round();
};

std::string draw_pile_to_str(std::vector<card> draw_pile);

///Count the number of cards in the game
int get_n_cards(const game& g) noexcept;

std::string played_pile_to_str(std::vector<card> played_pile);

std::ostream& operator<<(std::ostream&, const game& g) noexcept;

#endif // GAME_H
