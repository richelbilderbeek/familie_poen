#include "game.h"

#include "ai.h"
#include "solver.h"

#include <cassert>
#include <iostream>
#include <iterator>

std::vector<ai_strategy> parse_strategies(const std::string& s)
{
  std::vector<ai_strategy> v;
  for (const char c: s)
  {
    v.push_back(to_strategy(c));
  }
  return v;
}

std::vector<int> tally_winners(
  const std::vector<ai_strategy>& strategies,
  const int n_experiments
)
{
  std::vector<int> tally(strategies.size(), 0);
  for (int rng_seed=0; rng_seed!=n_experiments; ++rng_seed)
  {
    const int winner = get_winner(
      rng_seed,
      strategies
    );
    ++tally[winner];
  }
  return tally;
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
  const auto strategies = parse_strategies(args[1]);
  const int n_experiments = std::stoi(args[2]);
  const auto tally = tally_winners(
    strategies,
    n_experiments
  );
  const int n = strategies.size();
  std::copy(
    std::begin(strategies),
    std::end(strategies),
    std::ostream_iterator<ai_strategy>(std::cout, "")
  );
  for (int i=0; i!=n; ++i)
  {
    std::cout << "|" << static_cast<double>(100.0 * tally[i] / n_experiments);
  }
  std::cout << '\n';
}
