#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"
#include <iterator>
template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  int count = 0;
  for(int i=0;i<pos.size();i++){
    auto itr = begin() + pos[i] - count;
    erase(itr);
    count ++;
  }
  
}

#endif
