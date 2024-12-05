#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
    // ensureCapacity(mSize+1);
    // for(size_t i=0; i< pos;i++){
    //   mData[mSize-i] = mData[mSize-i-1];  //stack มันก้เอาจากตัวท้ายไง เลยบอก mSize-i
    // }
    // mData[mSize-pos] = value;
    // mSize++;

    CP::stack<T> st;
    for(size_t i=0;i<pos;i++){
        st.push(top());
        pop();
    }
    push(value);

    while(!st.empty()){
      push(st.top());
      st.pop();
    }

}

#endif
