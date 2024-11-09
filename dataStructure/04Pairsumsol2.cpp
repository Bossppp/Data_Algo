#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    multiset<pair<int, int>> A;
    for (int i = 0; i < N; ++i) {
        int value;
        cin >> value;
        A.insert({value, i});
    }

    vector<int> targets(M);
    for (int i = 0; i < M; ++i) {
        cin >> targets[i];
    }

    for (int target : targets) {
        bool found = false;
        auto left = A.begin();
        auto right = prev(A.end());
        while (left != right) {
            int sum = left->first + right->first;
            if (sum == target) {
                if (left->second != right->second) {
                    found = true;
                    cout << "YES" << endl;
                    break;
                } else {
                    left++;
                }
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        if (!found) {
            cout << "NO" << endl;
        }
    }

}
