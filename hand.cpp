#include "hand.h"

#include <numeric>
#include <iterator>
#include <sstream>

int sum_points(const hand& h) noexcept
{
  return std::accumulate(
    std::begin(h),
    std::end(h),
    0,
    [](const int init, const card& c)
    {
      return init + c.get_value();
    }
  );
}

std::string to_str(const hand& h) noexcept
{
  std::stringstream s;
  std::copy(std::begin(h), std::end(h),
    std::ostream_iterator<card>(s, " ")
  );
  return s.str();
}
