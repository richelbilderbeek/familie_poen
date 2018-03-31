#ifndef SOLVER_H
#define SOLVER_H

#include "ai.h"
#include "ai_strategy.h"
#include "game.h"

#include <vector>


///Determine the winner of a combination of strategies
int get_winner(
  const int rng_seed,
  const std::vector<ai_strategy>& strategies,
  const bool verbose = false
);

///Play one round, up until one has no cards and the
///points/credits/money needs to be subtracted from the players
void play_round(game& g, std::vector<ai>& ais, const bool verbose = false);


#endif // SOLVER_H
