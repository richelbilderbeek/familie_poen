#ifndef CONSOLE_GAME_H
#define CONSOLE_GAME_H

#include "game.h"

#include <string>
#include <iostream>
/// Using the terminal to play the game
class console_game
{
public:
  console_game(const int n_players, const int rng_seed);
  void execute();
private:
  game m_game;

  ///Show the hands of the human and other players
  void show_hands(std::ostream& os = std::cout);
};

std::string ask_user_for_string() noexcept;

///Determine if the string can be converted to an integer
bool is_number(const std::string& s) noexcept;

#endif // CONSOLE_GAME_H
