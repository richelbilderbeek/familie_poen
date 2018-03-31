#include <console_game.h>

int main()
{
  const int n_players{2};
  const int rng_seed{42};
  console_game c(n_players, rng_seed);
  c.execute();
}
