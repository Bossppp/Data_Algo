#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>
#include "queue.h"

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    size_t currentPos = (mFront+pos) % mCap;
    T temp = mData[currentPos];

    for(size_t i = pos; i > 0; i--){
        mData[currentPos] = mData[(currentPos+ mCap - 1) % mCap]; //เอาตัวก่อนหน้ามาใส่ตัวนี้้
        currentPos = (currentPos-1 + mCap) % mCap; //update
    }
    mData[mFront] = temp;
}

#endif
