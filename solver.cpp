#include "solver.h"

#include "ai.h"
#include "game.h"

#include <cassert>
#include <iostream>

int get_winner(
  const int rng_seed,
  const std::vector<ai_strategy>& strategies,
  const bool verbose
)
{
  const int n_players = strategies.size();
  game g(n_players, rng_seed);
  std::vector<ai> ais = create_ais(strategies);

  while (1)
  {
    play_round(g, ais, verbose);
  }
}

void play_round(game& g, std::vector<ai>& ais, const bool verbose)
{
  while (!g.has_winner())
  {
    const int active_player_index{g.get_player_index()};
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
    assert(!actions.empty());
    const action& a = ais[active_player_index].pick_action(
      actions,
      g.get_played_pile(),
      const_cast<const game&>(g).get_active_hand()
    );
    if (verbose)
    {
      std::cout << "Do action: " << a << '\n';
    }
    g.do_action(a);
  }
}
