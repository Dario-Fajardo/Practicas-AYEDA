#ifndef TYPES_H
#define TYPES_H

typedef int Position;

enum State : int {
  zero = 0,
  one = 1
};

enum Frontier : int {
  periodic = 0,
  fixed_hot = 1,
  fixed_cold = 2
};

#endif