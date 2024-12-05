//k = 3 : 1 2 4 7 13
//k = 2 : 1 2 3 5 8
//num dif = 1 such 1 2 3

//k = 3 : 1 1 2 3 4 6 10 15
//num dif != 1 such 1 3 7

#include <iostream>
#include <set>

using namespace std;

int mod = 1000003;

int main(){
    int n,k;
    cin >> n >> k;
    set<int> numset;
    for(int i=0;i<k;i++){
        int num;
        cin >> num;
        numset.insert(num);
    }

    long long dp[n+1];
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        dp[i] = 0;
        for(auto num : numset){
            if(i-num >= 0){
                //cout << "i : " << i << " num : " << num << endl;
                //cout << "->dp[i](before) : " << dp[i] << " dp[i-num] : " << dp[i-num] << endl;
                dp[i] += (dp[i-num]);
                //cout << "->>dp[i](after) : " << dp[i] << endl;
                dp[i] %= mod;
            }
        }
    }

    cout << dp[n] << endl;
    
}
