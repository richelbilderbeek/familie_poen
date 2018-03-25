#ifndef HAND_H
#define HAND_H

#include "card.h"

#include <set>
#include <string>

using hand = std::set<card>;

std::string to_str(const hand& h) noexcept;

#endif // HAND_H
