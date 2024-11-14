#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include "queue.h"
#include <algorithm>

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  //sol1
  std::sort(pos.begin(), pos.end());
  T *arr = new T[mCap];
  int Ndata = 0;
  int PosIdx = 0;
  for(size_t i=0;i<mSize;i++){
    if(i == pos[PosIdx]){
      PosIdx++;

    }else{
      arr[Ndata] = mData[(mFront+i)%mCap];
      Ndata++;
    }
  }
  delete[] mData;
  mData = arr;
  mSize = Ndata;
  mFront = 0;
  
  //sol2
  queue<int> q;
  std::sort(pos.begin(),pos.end());
  auto it = pos.begin();
  for(int i=0;i<mSize;i++){
    if(i == *it){
      it++;
    }else{
      q.push(mData[(mFront+i)%mCap]);
    }
  }
  *this = q

}

#endif
