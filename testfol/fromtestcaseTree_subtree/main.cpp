#include <iostream>
#include "map_bst.h"
#include "student.h"
#include <set>

std::set<int> destroyed;

template <typename T1,typename T2,typename T3>
void run_test(CP::map_bst<T1,T2,T3> &m,CP::map_bst<T1,T2,T3> &left, CP::map_bst<T1,T2,T3> &right) {
  auto t = m.subtree(left,right);
  std::cout << "return: " << t.first << ":" << t.second << "\n";
  std::cout << "main tree:  "; m.print();
  std::cout << "left tree:  "; left.print();
  std::cout << "right tree: "; right.print();
  if (!m.checkParent() || !left.checkParent() || !right.checkParent()) {
    std::cout << "parent error" << "\n";
  }
  if (!m.checkInorder() || !left.checkInorder() || !right.checkInorder()) {
    std::cout << "order error" << "\n";
  }
}

template <typename T1,typename T2,typename T3>
void super_run(CP::map_bst<T1,T2,T3> &m) {
  if (m.empty()) return ;
  CP::map_bst<T1,T2,T3> left,right;
  auto t = m.subtree(left,right);
  super_run(left);
  super_run(right);
}

int main() {
  std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);
  int mode,n;
  std::cin >> mode;
  switch (mode) {
    case 1: //input from file
      {
        CP::map_bst<int,int> m,left,right;
        std::cin >> n;
        int k;
        for (int i = 0;i < n;i++) {
          std::cin >> k;
          m[k] = i;
        }
        run_test(m,left,right);
      }
      break;
    case 2:
      {
        CP::map_bst<int,std::string> m,left,right;
        int l,r,prefix_size,repeat;
        std::cin >> n >> l >> r >> prefix_size >> repeat;
        std::string tmp(prefix_size,'*');
        std::vector<int> md(n),ld(l),rd(r);
        for (int i = 0;i < n;i++) { std::cin >> md[i]; }
        for (int i = 0;i < l;i++) { std::cin >> ld[i]; }
        for (int i = 0;i < r;i++) { std::cin >> rd[i]; }
        while (repeat > 0) {
          m.clear();
          left.clear();
          right.clear();
          for (int i = 0;i < n;i++) { m[md[i]] = tmp + std::to_string(i); }
          for (int i = 0;i < l;i++) { left[ld[i]] = tmp + std::to_string(i); }
          for (int i = 0;i < r;i++) { right[rd[i]] = tmp + std::to_string(i); }
          if (repeat == 1) {
            run_test(m,left,right);
          } else {
            super_run(m);
          }
          repeat--;
        }
      }
      break;
  }
}
