#include <iostream>
#include <vector>

using namespace  std;

int mod = 32717;

//DP METHOD

//top Down
vector<int> c,a;
vector<int> dpjum;
int n,k;

int calc(int n){
    if(n<k){
        return a[n];
    }

    //lookup with vector
    if(dpjum[n] != -1){
        return dpjum[n];
    }

    int sum =0;
    for(int i=1;i<=k;i++){
        sum += calc(n-i) * c[i];
        sum %= mod;
    }

    dpjum[n] = sum;//save subproblem
    return dpjum[n];
}

int main(){
    cin >> k >> n;
    c.resize(k+5);
    a.resize(k+5);
    dpjum.resize(n+5,-1);

    for(int i=1;i<=k;i++){ //beware การรับค่าเริ่มที่ไหน!!
        cin >> c[i];
    }
    for(int i=0;i<k;i++){
        cin >> a[i];
    }

    cout << calc(n);
}

//bottom Up
// int n,k;
// int dp[1005];
// int consKeep[1005];

// int main(){
//     cin >> k >> n;
//     for(int i=1;i<=k;i++){
//         cin >> consKeep[i];
//     }
//     for(int i=0;i<k;i++){
//         cin >> dp[i];
//     }

//     for(int i=k;i<=n;i++){
//         for(int j=1;j<=k;j++){
//             dp[i] = (dp[i] + consKeep[j]*dp[i-j]) % mod;
//         }
//     }
//     cout << dp[n];
// }

//brute force method
// int recur(int n,int k,vector<int> &c,vector<int> &a){
//     if(n < k){
//         return a[n];
//     }
//     int sum =0 ;
//     for(int i=1;i<=k;i++){
//         sum = (sum + c[i-1]*recur(n-i,k,c,a)) % mod;
//     }
//     return sum;
// }

// int main(){
//     int n,k;
//     cin >> k >> n;
//     vector<int> c;
//     vector<int> a;
//     for(int i=1;i<=k;i++){
//         int x;
//         cin >> x;
//         c.push_back(x);
//     }
//     for(int i=0;i<k;i++){
//         int x;
//         cin >> x;
//         a.push_back(x);
//     }
//     cout << recur(n,k,c,a);
// }