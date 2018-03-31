#ifndef HAND_H
#define HAND_H

#include "card.h"

#include <set>
#include <string>

using hand = std::set<card>;

///Sum the points of a hand
int sum_points(const hand& h) noexcept;

std::string to_str(const hand& h) noexcept;


#endif // HAND_H
