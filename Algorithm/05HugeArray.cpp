#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void test(vector<pair<int, int>> v) {
  for (auto e : v)
    cout << e.first << " " << e.second;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> arr;
    // input
    for (int i = 0; i < n; i++) {
        int num, count;
        cin >> num >> count;
        arr.push_back({num, count});
    }
    sort(arr.begin(), arr.end());

    // test(arr);
    // cout << endl;

    //fill it with sum frequency 
    //{(3,2),(4,1),(5,4)} -> {(3,2),(4,3),(5,7)}
    vector<int> frq;
    int countfrq = 0;
    for (int i = 0; i < n; i++) {
        countfrq += arr[i].second;
        frq.push_back(countfrq);
    }

    // search
    while (q--) {
        int idx;
        cin >> idx;
        int idex = lower_bound(frq.begin(), frq.end(), idx) - frq.begin();
        cout << arr[idex].first << endl;
    }
}