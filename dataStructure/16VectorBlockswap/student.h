#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "vector.h"
#include <algorithm>

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  auto range_a = a + (m-1);
  auto range_b = b + (m-1);

  if(m == 0) return false;

  if(a < begin() || a >= end() || b < begin() || b >= end()) return false;

  if(range_a > end() || range_b > end()) return false;

  if(!(range_a < b || range_b < a)) return false;

  for(size_t i = 0; i < m; i++) {
    std::swap(*a++, *b++);
  }

  return true;
  
}


#endif
