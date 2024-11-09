#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"
#include <iostream>
template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
    size_t pos = position-begin();
    size_t ins_amount = last - first;
    size_t ttsize = mSize + ins_amount;
    T *arr = new T[ttsize];

    for(size_t i=0;i<pos;i++){
        arr[i] = mData[i];
    } //แยก arr ตั้งแต่ตัวที่ 0 ถึง pos

    for(size_t i=0;i<ins_amount;i++){
        arr[pos] = *first;
        pos++;
        first++; 
    } //เอาค่าตั้งแต่ตัว first ใส่ไปใน arr ตั้งแต่ตำแน่ง pos

    for(size_t i=pos;i<ttsize;i++){
        arr[i] = mData[i-ins_amount];
    } //ใส่ต่อท้ายที่เหลือ

    delete [] mData;
    mData = arr;
    mSize += ins_amount;

    

}

#endif
