#include <iostream>
#include <vector>

using namespace std;

long long mod = 100000007;
long long dp[10000000];

//----------bruteforce_Sol----------

// vector<vector<int> > table;
// int m;
// long long cnt = 0;

// bool checkNo11(){
//     for(int i=0;i<m-1;i++){
//         if(table[0][i] == 1 && table[0][i+1] == 1) return false; //check row 0
//         if(table[1][i] == 1 && table[1][i+1] == 1) return false; //check row 1
//         if(table[0][i] == 1 && table[1][i] == 1) return false; //check col i
//     }
//     if(table[0][m-1] == 1 && table[1][m-1] == 1) return false; //check col m-1
//     return true;
// }

// void bruteforce(int row,int col){
//     if(col == m){
//         if(checkNo11()){
//             cnt++;
//             cnt = cnt % mod;

//             // cout << "finish fill :)" << endl;
//             // for(int i=0;i<col;i++) cout << table[0][i] << " ";
//             // cout << endl;
//             // for(int i=0;i<col;i++) cout << table[1][i] << " ";
//             // cout << endl;
//         }
        
//     }else{
//         int next_row,next_col;
//         if(row == 0){
//             next_row = 1;
//             next_col = col;
//         }
//         if(row == 1){
//             next_row = 0;
//             next_col = col+1;
//         }
//         table[row][col] = 0;
//         bruteforce(next_row,next_col);
//         table[row][col] = 1;
//         bruteforce(next_row,next_col);
//     }
// }

// int main(){
//     cin >> m;
//     table.resize(2,vector<int>(m,0));
//     bruteforce(0,0);
//     cout << cnt << endl;
// }

//----------dp_Sol----------


int main(){
    dp[1] = 3;
    dp[2] = 7;
    dp[3] = 17;
    int n;
    cin >> n;
    
    for(int i=3; i<=n;i++){
        dp[i] = (2*dp[i-1] + dp[i-2]) % mod;
    }
    cout << dp[n];
}