#ifndef GAME_H
#define GAME_H

#include "card.h"
#include "game_state.h"

#include <vector>

/// Game logic
class game
{
public:
  game(const int n_players);

  const card& active_card() const noexcept;

  ///Can the card be played?
  bool can_play(const card& c) const noexcept;

  ///Get the number of cards a player has
  int n_cards(const int player_index) const;

  ///Get the number of players
  int n_players() const noexcept { return m_hands.size(); }

  std::vector<card> player_hand() const noexcept { return m_hands[0]; }

  ///Get the state that the game is in now
  game_state state() const noexcept { return m_state; }
private:

  ///The discarded cards
  std::vector<card> m_discarded;

  ///The cards in the hands of the players.
  ///The human player is always at index 0
  std::vector<std::vector<card>> m_hands;

  ///The pile of cards to draw from
  std::vector<card> m_pile;

  ///The current game state
  game_state m_state;
};

#endif // GAME_H
