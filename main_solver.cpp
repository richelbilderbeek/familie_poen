#include "game.h"

#include "ai.h"

#include <cassert>
#include <iostream>

int get_winner(
  const int rng_seed,
  const std::vector<ai_strategy>& strategies,
  const bool verbose = false
)
{
  const int n_players = strategies.size();
  game g(n_players, rng_seed);
  std::vector<ai> ais;
  for (int i=0; i!=n_players; ++i)
  {
    ais.push_back(ai(strategies[i]));
  }

  while (1)
  {
    if (verbose)
    {
      std::cout << g << '\n';
      std::cout << "Hash: " << hash(g) << '\n';
    }
    const auto actions = g.actions();
    const int n_actions = actions.size();
    if (verbose)
    {
      for (int i=0; i!=n_actions; ++i)
      {
        std::cout << '[' << i << "] " << actions[i] << '\n';
      }
    }
    if (actions.empty())
    {
      if (verbose)
      {
        std::cout << "Player " << (1 + g.player_index()) << " won\n";
      }
      return g.player_index();
    }
    assert(!actions.empty());
    const action& a = ais[g.player_index()].pick_action(actions);
    if (verbose)
    {
      std::cout << "Do action: " << a << '\n';
    }
    g.do_action(a);
    if (verbose)
    {
      std::cout << '\n';
    }
  }

}

std::vector<ai_strategy> parse_strategies(const std::string& s)
{
  std::vector<ai_strategy> v;
  for (const char c: s)
  {
    v.push_back(to_strategy(c));
  }
  return v;
}

int main(int argc, char* argv[])
{
  std::vector<std::string> args(argv, argv + argc);
  if (args.size() != 3)
  {
    std::cout << "Please use two command line arguments, "
      << "for example:\n"
      << "\n"
      << " ./familie_poen_solver LH 10000\n"
    ;
    return 1;
  }
  try
  {
    parse_strategies(args[1]);
  }
  catch (const std::invalid_argument& e)
  {
    std::cout << "Incorrect argument: " << e.what() << '\n';
    return 1;
  }
  try
  {
    std::stoi(args[2]);
  }
  catch (const std::invalid_argument& e)
  {
    std::cout << "Number of experiments must be a number\n";
    return 1;
  }

  const std::vector<ai_strategy> strategies = parse_strategies(args[1]);
  const int n_experiments = std::stoi(args[2]);
  const int n = strategies.size();

  std::vector<int> tally(n, 0);
  for (int rng_seed=0; rng_seed!=n_experiments; ++rng_seed)
  {
    const int winner = get_winner(
      rng_seed,
      strategies
    );
    ++tally[winner];
  }
  for (int i=0; i!=n; ++i)
  {
    std::cout << "Player " << (i + 1)
      << " playing " << strategies[i] << " won " << tally[i]
      << " times\n"
    ;
  }
}
