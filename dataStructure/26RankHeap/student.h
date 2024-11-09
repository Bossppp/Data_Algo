#ifndef __STUDENT_H_
#define __STUDENT_H_

using namespace std;
#include "priority_queue.h"

template <typename T,typename Comp>
size_t CP::priority_queue<T,Comp>::get_rank(size_t pos) const {
  size_t count = 0;
  for(size_t i=0;i<mSize;i++){
    if(!mLess(mData[i],mData[pos]) && i!=pos && mData[i]!=mData[pos]){
      count++;
    }
  }
  return count;

}

#endif
