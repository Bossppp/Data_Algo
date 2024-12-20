#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>
#include "queue.h"

template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  T temp = mData[(mFront+pos) % mCap];
  
  for(size_t i = mFront+pos; i<mSize+mFront; i++){
    //shift ตัวหลังมาข้างหน้า
    mData[i%mCap] = mData[(i+1)%mCap];
  }

  mData[(mFront+mSize-1)%mCap] = temp;
}

#endif