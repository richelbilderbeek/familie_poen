#include "solver.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(playing_a_round)
{
  auto ais = create_ais( { ai_strategy::highest_value, ai_strategy::highest_value } );
  const int rng_seed{314};
  game g(ais.size(), rng_seed);
  play_round(g, ais);
  BOOST_CHECK_EQUAL(g.has_winner(), true);
}

BOOST_AUTO_TEST_CASE(no_action_when_there_is_a_winner)
{
  auto ais = create_ais( { ai_strategy::highest_value, ai_strategy::highest_value } );
  const int rng_seed{314};
  game g(ais.size(), rng_seed);
  play_round(g, ais);
  assert(g.has_winner());
  BOOST_CHECK_EQUAL(g.get_actions().empty(), true);
}

BOOST_AUTO_TEST_CASE(new_actions_in_next_round)
{
  auto ais = create_ais( { ai_strategy::highest_value, ai_strategy::highest_value } );
  const int rng_seed{314};
  game g(ais.size(), rng_seed);
  play_round(g, ais);
  assert(g.has_winner());
  assert(g.get_actions().empty());
  g.start_next_round();
  BOOST_CHECK_EQUAL(g.get_actions().empty(), false);
}

BOOST_AUTO_TEST_CASE(winner_receives_points)
{
  auto ais = create_ais( { ai_strategy::highest_value, ai_strategy::highest_value } );
  const int rng_seed{314};
  game g(ais.size(), rng_seed);
  play_round(g, ais);
  assert(g.has_winner());
  assert(g.get_actions().empty());
  const int winner_index = g.get_winner_index();
  assert(g.get_n_points(winner_index) == 112);
  g.start_next_round();
  BOOST_CHECK_GT(g.get_n_points(winner_index), 112);
}
