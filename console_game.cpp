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
      << "What do you want to do?\n"
    ;
    const std::string input = ask_user_for_string();
    if (!is_number(input))
    {
      std::cout << "Please enter a number\n" << '\n';
      continue;
    }
    const int choice = std::stoi(input);
    if (choice < 1 || choice > m_game.n_cards(0) + 1)
    {
      std::cout << "Please enter the number of a valid option\n" << '\n';
      continue;
    }
    if (choice == m_game.n_cards(0) + 1 && m_game.can_do_move(0))
    {
      std::cout << "Cannot pick a card if a card can be played\n" << '\n';
      continue;
    } else if (choice <= m_game.n_cards(0) &&
      !m_game.can_play(m_game.player_hand()[choice + 1]))
    {
      std::cout << "Cannot play that card\n" << '\n';
      continue;
    }
    std::cout << "WEL DONE!\n";
  }
}

bool is_number(const std::string& s) noexcept
{
  try
  {
    std::stoi(s);
    return true;
  }
  catch (std::exception&)
  {
    return false;
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
  os
    << '[' << (m_game.can_do_move(0) ? ' ' : '*') << "] " << option
    << ": take a card\n"
  ;
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
