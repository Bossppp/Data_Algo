#include <iostream>

using namespace std;
int R,C;
int board[15][15];
bool visit[15][15];

void walking(int r,int c,string path){
    if(r == R-1 && c == C-1){ //found destination!
        cout << path << endl;
        return;
    }

    visit[r][c] = true;
    //A move c+1
    if(!visit[r][c+1] && c+1 < C && board[r][c+1] == 0) {
        walking(r,c+1,path + 'A');
    }
    //B move r+1
    if(!visit[r+1][c] && r+1 < R && board[r+1][c] == 0) {
        walking(r+1,c,path + 'B');
    }
    //C move r-1
    if(!visit[r-1][c] && r-1 >= 0 && board[r-1][c] == 0) {
        walking(r-1,c,path + 'C');
    }

    visit[r][c] = false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> board[i][j];
        }
    }

    walking(0,0,"");
    cout << "DONE" << endl;

}