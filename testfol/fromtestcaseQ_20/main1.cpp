#include "queue.h"
#include "student.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

template <typename T>
void grader_primitive() {
  int mCap, mSize, mFront;
  cin >> mCap >> mSize >> mFront;

  T* data = new T[mCap];
  for (int i = 0; i < mCap; ++i)
    cin >> data[i];

  CP::queue<T> q(data, mCap, mSize, mFront);

  int t, op;
  cin >> t;
  while (t--) {
    cin >> op;
    if (op == 1) {
      T val;
      cin >> val;
      q.push(val);
    }
    if (op == 2)
      q.reverse();
    if (op == 3)
      q.pop();
    if (op == 4)
      cout << q.back() << "\n";
    if (op == 5)
      cout << q.front() << "\n";
  }
  size_t sz = q.size();
  for (int i = 0; i < sz; ++i) {
    T val = q.front();

    cout << val << " ";

    q.pop();
    q.push(val);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int type;
  std::cin >> type;

  if (type == 1)
    grader_primitive<int>();
  if (type == 2)
    grader_primitive<std::string>();
}