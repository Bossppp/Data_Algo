#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <algorithm>
#include <vector>
template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  int n = std::min((size_t)7,mSize);
  std::vector<T> v;
  for(int i = 0; i < n; i++) {
    v.push_back(mData[i]);
  }
  std::sort(v.begin(),v.end(),mLess);
  return *(v.end() -k); // แสดงค่าตำแหน่ง k
}
#endif
