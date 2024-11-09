#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"
#include <unordered_set>

template <typename T>
void CP::vector<T>::uniq() {
  std::unordered_set<T> us;
  CP::vector<T> temp;

  for(size_t i=0;i<mSize;i++){
    if(us.find(mData[i]) == us.end()){
      us.insert(mData[i]);
      temp.push_back(mData[i]);
    }
  }
  *this = temp;

}

#endif
