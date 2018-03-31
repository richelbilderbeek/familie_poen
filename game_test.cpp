#include "game.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(construct_game)
{
  const int n_players{3};
  const int rng_seed{314};
  game g(n_players, rng_seed);
  BOOST_CHECK_EQUAL(g.get_n_players(), n_players);
  BOOST_CHECK_EQUAL(g.get_rng_seed(), rng_seed);
}
