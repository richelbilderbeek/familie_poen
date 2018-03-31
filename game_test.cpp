#include "game.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(game_constructor_must_copy_arguments)
{
  const int n_players{3};
  const int rng_seed{314};
  game g(n_players, rng_seed);
  BOOST_CHECK_EQUAL(g.get_n_players(), n_players);
  BOOST_CHECK_EQUAL(g.get_rng_seed(), rng_seed);
}

BOOST_AUTO_TEST_CASE(all_players_start_with_112_points)
{
  const int n_players{4};
  const int rng_seed{314};
  const game g(n_players, rng_seed);
  BOOST_CHECK_EQUAL(g.get_n_points(0), 112);
  BOOST_CHECK_EQUAL(g.get_n_points(1), 112);
  BOOST_CHECK_EQUAL(g.get_n_points(2), 112);
  BOOST_CHECK_EQUAL(g.get_n_points(3), 112);
}
