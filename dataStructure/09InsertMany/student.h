#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

#include "vector.h"
template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  sort(data.begin(),data.end());
  int count = 0;
  for (auto d : data){
    auto pos = begin() + d.first + count;
    insert(pos,d.second);
    count++;
  }

  
}

#endif
