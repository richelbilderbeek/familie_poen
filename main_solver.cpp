#include "game.h"

#include <cassert>
#include <iostream>

int main()
{
  const int n_players{2};
  const int rng_seed{42};
  game g(n_players, rng_seed);

  for (int i=0; i!=2; ++i)
  {
    std::cout << g << '\n';
    const auto actions = g.actions();
    const int n_actions = actions.size();
    for (int i=0; i!=n_actions; ++i)
    {
      std::cout << '[' << i << "] " << actions[i] << '\n';
    }
    assert(!actions.empty());
    const action a = actions.back();
    std::cout << "Do action: " << a << '\n';
    g.do_action(a);
    std::cout << '\n';
  }
}
