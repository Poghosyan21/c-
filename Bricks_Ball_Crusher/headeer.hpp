#ifndef HEADER_HPP
#define HEADER_HPP

#include <ulimit.h> //pair
#include <string>
#define BALL_CHAR "o"


using Position = std::pair <int, int>;
using String = std::string;
constexpr int Key_Space = 32;
constexpr int MAP_HEIGHT = 28;
constexpr int MAP_WITH = 30;
constexpr int Key_Enter = 10;
const String choices[2] = {"-START-", "-EXIT-"};

#endif //HEAEDER_HPP