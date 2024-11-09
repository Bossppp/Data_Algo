#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"

template <typename T>
void CP::queue<T>::reverse() {
  if(!aux){
    aux = 1; //reverse!!
  }else{
    aux = 0;
  }

}

template <typename T>
const T& CP::queue<T>::front() const {
  if(aux){
    //เอาตัวหลัง
    return mData[(mFront+mSize-1) % mCap];
  }else{
    return mData[mFront];
  }
  
}

template <typename T>
const T& CP::queue<T>::back() const {
  if(aux){
    //เอาตัวหน้า
    return mData[mFront];
  }else{
    return mData[(mFront + mSize - 1) % mCap];
  }
}

template <typename T>
void CP::queue<T>::push(const T& element) {
  ensureCapacity(mSize + 1);
  if(aux){
    //push ข้างหน้า front
    mData[(mFront - 1 + mCap) % mCap] = element;
    mFront = (mFront + mCap - 1)%mCap;
  }else{
    mData[(mFront + mSize) % mCap] = element;
  }

  mSize++;
}

template <typename T>
void CP::queue<T>::pop() {
  if(!aux){
    //pop ข้างหน้า
    mFront = (mFront + 1) % mCap;
  }
  mSize--;
}

#endif