#include "console_game.h"

#include <cassert>
#include <iostream>
#include <iterator>

std::string ask_user_for_string() noexcept
{
  std::string s;
  std::getline(std::cin,s);
  return s;
}

console_game::console_game(const int n_players)
  : m_game(n_players)
{
  assert(m_game.state() == game_state::running);
}

void console_game::execute()
{
  while (m_game.state() == game_state::running)
  {
    //Show hands
    show_hands();
    std::cout
      << '\n'
      << "Play which card?\n"
    ;
    const std::string input = ask_user_for_string();
  }
}

void console_game::show_hands(std::ostream& os)
{
  os << "Active card: " << m_game.active_card() << '\n'
    << '\n'
    << "Your hand:\n"
    << '\n'
  ;
  int option{1};
  for (const auto card: m_game.player_hand())
  {
    os
      << '[' << (m_game.can_play(card) ? '*' : ' ') << "] " << option
      << ": " << card << '\n'
    ;
    ++option;
  }
  os << '\n';
  const int n_players{m_game.n_players()};
  for (int other_player = 1; other_player!=n_players; ++other_player)
  {
    os
      << "Player " << (other_player + 1) << " has "
      << m_game.n_cards(other_player) << " cards.\n"
    ;
  }
}
