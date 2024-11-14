#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

// SOL1: insertion sort every k O(mn^2) -> 20P
// int insertion_sort(vector<int> &A, int k)
// {
//     int ans = 0;
//     for (int pos = A.size() - 2; pos >= 0; pos--)
//     {
//         int tmp = A[pos];
//         size_t i = pos + 1;
//         while (i < A.size() && A[i] < tmp)
//         {
//             if (A[i] == k)
//             {
//                 ans++;
//             }
//             A[i - 1] = A[i];
//             i++;
//         }
//         A[i - 1] = tmp;
//     }
//     return ans;
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int n, m, k;
//     cin >> n >> m;

//     vector<int> A(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> A[i];
//     }
//     for (int i = 0; i < m; i++)
//     {
//         cin >> k;
//         vector<int> tmp = A;
//         cout << insertion_sort(tmp, k) << "\n";
//     }
// }
// --------------------------------------------------------
// SOL2: insertion sort 1 times using map to count O(n^2logn) -> 20P
// int insertion_sort(vector<int> &A, map<int, int> &result)
// {
//     int ans = 0;
//     for (int pos = A.size() - 2; pos >= 0; pos--)
//     {
//         int tmp = A[pos];
//         size_t i = pos + 1;
//         while (i < A.size() && A[i] < tmp)
//         {
//             if (result.count(A[i]) == 0)
//             {
//                 result[A[i]] = 1;
//             }
//             else
//             {
//                 result[A[i]]++;
//             }

//             A[i - 1] = A[i];
//             i++;
//         }
//         A[i - 1] = tmp;
//     }
//     return ans;
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int n, m, k;
//     cin >> n >> m;

//     vector<int> A(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> A[i];
//     }

//     map<int, int> result;
//     insertion_sort(A, result);

//     for (int i = 0; i < m; i++)
//     {
//         cin >> k;
//         cout << result[k] << "\n";
//     }
// }
// --------------------------------------------------------
// // SOL3: insertion sort 1 times using vector to count O(n^2) -> 50P
// int insertion_sort(vector<int> &A, vector<int> &result)
// {
//     int ans = 0;
//     for (int pos = A.size() - 2; pos >= 0; pos--)
//     {
//         int tmp = A[pos];
//         size_t i = pos + 1;
//         while (i < A.size() && A[i] < tmp)
//         {
//             result[A[i]]++;
//             A[i - 1] = A[i];
//             i++;
//         }
//         A[i - 1] = tmp;
//     }
//     return ans;
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int n, m, k;
//     cin >> n >> m;

//     vector<int> A(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> A[i];
//     }

//     vector<int> result(n, 0);
//     insertion_sort(A, result);

//     for (int i = 0; i < m; i++)
//     {
//         cin >> k;
//         cout << result[k] << "\n";
//     }
// }
// --------------------------------------------------------
// SOL4: count more on left -> 100P

int main() {
  int n, m, k;
  cin >> n >> m;
  int v[n];
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  while (m--) {
    cin >> k;
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] == k) {
        break;
      } else if (v[i] > k) {
        count++;
      }
    }
    cout << count << endl;
  }
}