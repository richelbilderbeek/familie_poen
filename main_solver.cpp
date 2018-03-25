#include "game.h"

#include "ai.h"

#include <cassert>
#include <iostream>
#include <iterator>

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
    const auto actions = g.get_actions();
    const int n_actions = actions.size();
    if (verbose)
    {
      std::cout << '\n' << g << '\n';
      for (int i=0; i!=n_actions; ++i)
      {
        std::cout << '[' << i << "] " << actions[i] << '\n';
      }
    }
    if (actions.empty())
    {
      return g.get_player_index();
    }
    assert(!actions.empty());
    const action& a = ais[g.get_player_index()].pick_action(actions);
    if (verbose)
    {
      std::cout << "Do action: " << a << '\n';
    }
    try
    {
      g.do_action(a);
    }
    catch (const std::runtime_error& e)
    {
      std::cerr
        << "Error: " << e.what() << '\n'
        << "rng_seed: " << rng_seed << '\n'
      ;
      std::copy(std::begin(strategies), std::end(strategies),
        std::ostream_iterator<ai_strategy>(std::cerr, " ")
      );
      std::cerr << '\n';
      throw;
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

void run_experiment(
  const std::vector<ai_strategy>& strategies,
  const int n_experiments
)
{
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

int main(int argc, char* argv[])
{
  {
    const int actual{
      get_winner(
        62630,
        {
          ai_strategy::lowest_value,
          ai_strategy::lowest_value,
          ai_strategy::lowest_value,
          ai_strategy::lowest_value
        }
      )
    };
    assert(actual >= -1);
  }
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
  catch (const std::invalid_argument&)
  {
    std::cout << "Number of experiments must be a number\n";
    return 1;
  }
  run_experiment(parse_strategies(args[1]), std::stoi(args[2]));
}
