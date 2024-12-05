#include <vector>
#include <iostream>
using namespace std;

//bottom up
int fibo(int n){
    vector<int> dp(n+5);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}


//top down
vector<int> dp;
int fibodp(int n){
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    dp[n] = fibodp(n-1) + fibodp(n-2);
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    dp.resize(n+1, -1);
    //cout << fibo(n);
    cout << fibodp(n);
}