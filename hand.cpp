#include "hand.h"

#include <iterator>
#include <sstream>

std::string to_str(const hand& h) noexcept
{
  std::stringstream s;
  std::copy(std::begin(h), std::end(h),
    std::ostream_iterator<card>(s, " ")
  );
  return s.str();
}
