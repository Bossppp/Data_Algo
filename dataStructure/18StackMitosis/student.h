#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    CP::stack<T> temp , mito;

    for(int i = 0; i<=b;i++){
        //pos < a ย้ายไป stack ใหม่ก่อน
        if(i < a){
            temp.push(mData[size()-1]);
            pop();
        }else if(i <= b){
        //pos อยู่ในช่วง a,b เก็บเข้า stack ใหม่
            mito.push(mData[size()-1]);
            pop();
        }
    }

    while(!mito.empty()){
        push(mito.top());
        push(mito.top());
        mito.pop();
    }

    while(!temp.empty()){
        push(temp.top());
        temp.pop();
    }
}

#endif