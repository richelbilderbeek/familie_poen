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

console_game::console_game(const int n_players, const int rng_seed)
  : m_game(n_players, rng_seed)
{
  assert(!m_game.get_actions().empty());
}

void console_game::execute()
{
  while (!m_game.get_actions().empty())
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
    const int n_actions = const_cast<const game&>(m_game).get_actions().size();
    if (choice < 1 || choice > n_actions  + 1)
    {
      std::cout << "Please enter the number of a valid action\n" << '\n';
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
  os << "Active card: " << m_game.get_active_card() << '\n'
    << '\n'
    << "Your hand:\n"
    << '\n'
  ;
  int option{1};
  for (const auto card: const_cast<const game&>(m_game).get_active_hand())
  {
    os
      << option
      << ": " << card << '\n'
    ;
    ++option;
  }
  os << '\n';
}
