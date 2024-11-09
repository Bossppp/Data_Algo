#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void printset(set<int> s){
    for(auto it = s.begin();it != s.end();it++){
        cout << *it << " ";
    }
    cout << endl;
}

void printvector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    //1.input phase
    int n,m,k;
    cin >> n >> m >> k;
    int num,mum;
    vector<int> nV;
    vector<int> mV;
    while(n--){
        cin >> num;
        nV.push_back(num);
    }
    //printset(nS);
    sort(nV.begin(),nV.end());

    while(m--){
        cin >> mum;
        mV.push_back(mum);
    }
    //printvector(mV);
    
    //2.Process
    //st=1,en=3 find in set(nS) [1,3]
    for(int i=0;i<mV.size();i++){
        int stIdx = mV[i]-k;
        int enIdx = mV[i]+k;
        auto lower = lower_bound(nV.begin(),nV.end(),stIdx);
        auto upper = upper_bound(nV.begin(),nV.end(),enIdx);
        int count = upper - lower;
        cout << count << " ";
    }
}