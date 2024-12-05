#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> pig(m);
    for(int i=0;i<m;i++){
        cin >> pig[i];
    }

    //search time that pig can found truffle equal n
    ll left = 0;
    ll right = INFINITY;
    ll mintime = 0;
    while(left < right){
        ll mid = (left+right)/2;
        ll counttruffle = 0;
        for(int i=0;i<m;i++){
            counttruffle += (mid/pig[i]);
            if(counttruffle >= n){
                break; //prevent overflow
            }
        }
        if(counttruffle >= n){
            mintime = mid;
            right = mid; //ลดขอบขวา
        }else{
            left = mid+1; //เพิ่มขอบซ้าย
        }
    }
    cout << mintime;
}