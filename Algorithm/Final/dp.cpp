#include <iostream>
using namespace std;

int mod = 1e8+7;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    long long dp[1000005];
    dp[1] = 3;
    dp[2] = 7;
    dp[3] = 15;
    for(int i=4;i<=n;i++){
        dp[i] = (dp[i-1]*2) + dp[i-3];
        dp[i] %= mod;
    }
    cout << dp[n];

}
//3 7 15 33 73