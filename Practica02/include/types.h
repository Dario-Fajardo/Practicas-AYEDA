#ifndef TYPES_H
#define TYPES_H

#include <utility>

typedef std::pair<int, int> Position;

enum State : int {
  zero = 0,
  one = 1
};

enum Frontier : int {
  periodic = 0,
  fixed_hot = 1,
  fixed_cold = 2
};

struct Neighbourhood {
  Cell* up_left;
  Cell* up;
  Cell* up_right;
  Cell* left;
  Cell* right;
  Cell* down_left;
  Cell* down;
  Cell* down_right;
};


#endif