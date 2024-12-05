#include <iostream>

using namespace std;
int mod = 1e8+7;
int r,c;
int board[505][505];
int dp[505][505][3]; //บนขวา 0 , กลางขวา 1 , ล่างขวา 2
// 0 mean i-1,j+1
// 1 mean i,j+1
// 2 mean i+1,j+1

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> r >> c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> board[i][j];
        }
    }

    //base case
    for(int i=1;i<=r;i++){
        if(board[i][1] == 0){
            if(i-1 >= 0 && board[i-1][2] == 0){
                dp[i-1][2][0]++;
            }
            if(board[i][2] == 0){
                dp[i][2][1]++;
            }
            if(i+1 <= r && board[i+1][2] == 0){
                dp[i+1][2][2]++;
            }
        }
    }

    //dp
    for(int j=2;j<c;j++){
        for(int i=1;i<=r;i++){
            if(board[i][j] == 0){
                if(i-1 >= 0 && board[i-1][j+1] == 0){
                    dp[i-1][j+1][0] = (dp[i-1][j+1][0] + dp[i][j][1] + dp[i][j][2])%mod;
                }
                if(board[i][j+1] == 0){
                    dp[i][j+1][1] = (dp[i][j+1][1] + dp[i][j][0] + dp[i][j][2])%mod;
                }
                if(i+1 <= r && board[i+1][j+1] == 0){
                    dp[i+1][j+1][2] = (dp[i+1][j+1][2] + dp[i][j][0] + dp[i][j][1])%mod;
                }
            }
        }
    }
    
    int ans = 0;
    for(int i=1;i<=r;i++){
        ans = (ans + dp[i][c][0] + dp[i][c][1] + dp[i][c][2])%mod;
    }
    cout << ans;
    return 0;

}
