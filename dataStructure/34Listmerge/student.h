#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  for(auto &l : ls){
    if(l.empty()) continue;

    mHeader->prev->next = l.mHeader->next;
    l.mHeader->next->prev = mHeader->prev;

    l.mHeader->prev->next = mHeader;
    mHeader->prev = l.mHeader->prev;

    mSize += l.size(); //expand list with ls size

    //make ls empty
    l.mHeader->next = l.mHeader;
    l.mHeader->prev = l.mHeader;
    l.mSize = 0;
  }

}

#endif
