#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    unordered_set<int> set;
    int n;
    cin >> n;
    vector<int> temp(n);

    for(int i=0;i<n;i++){
        cin >> temp[i];
        if(temp[i] < 1 || temp[i] > n){ 
            continue;
        }
        set.insert(temp[i]);
    }

    if(set.size() == n){
        cout << "YES";
    }else{
        cout << "NO";
    }
}
