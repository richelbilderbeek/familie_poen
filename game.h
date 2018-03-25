#ifndef GAME_H
#define GAME_H

#include "action.h"
#include "card.h"
#include "game_state.h"

#include <random>
#include <set>
#include <vector>

/// Game logic
class game
{
public:
  game(const int get_n_players, const int rng_seed);

  ///Do an action
  void do_action(const action& a);

  ///Get all valid actions
  std::vector<action> get_actions() const noexcept;

  ///Top card of the played pile
  const card& get_active_card() const noexcept;

  ///Get the draw pile
  const auto& get_draw_pile() const noexcept { return m_draw_pile; }

  ///Get the number of cards a player has
  int get_n_cards(const int get_player_index) const;

  ///Get the number of players
  int get_n_players() const noexcept { return m_hands.size(); }

  ///Get the played pile, card that are actively put on it
  const auto& get_played_pile() const noexcept { return m_played_pile; }

  ///Get a player's hand
  const std::set<card>& get_player_hand(const int get_player_index) const noexcept;

  ///Index of the active player
  int get_player_index() const noexcept { return m_player_index; }

  ///Get the state that the game is in now
  //game_state get_state() const noexcept { return m_state; }
private:

  ///The pile of cards to draw from
  std::vector<card> m_draw_pile;

  ///The cards in the hands of the players.
  ///The human player is always at index 0
  std::vector<std::set<card>> m_hands;

  ///The cards that are played, the top card is the active card
  std::vector<card> m_played_pile;

  ///Index of the player whose turn it is; the active player
  int m_player_index;

  ///The RNG engine
  std::mt19937 m_rng_engine;

  ///The RNG seed
  const int m_rng_seed;

  ///Get the currently active hand, the hand of the current player
  auto& active_hand() noexcept;

  ///Can the card be played?
  bool can_play(const card& c) const noexcept;
};

std::string hash(const game& g) noexcept;

std::string played_pile_to_str(std::vector<card> played_pile);

std::ostream& operator<<(std::ostream&, const game& g) noexcept;

#endif // GAME_H
