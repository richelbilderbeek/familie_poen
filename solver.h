#ifndef SOLVER_H
#define SOLVER_H

#include "ai_strategy.h"

#include <vector>


///Determine the winner of a combination of strategies
int get_winner(
  const int rng_seed,
  const std::vector<ai_strategy>& strategies,
  const bool verbose = false
);

#endif // SOLVER_H
