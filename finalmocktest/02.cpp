#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
typedef pair<int,int> pii;

struct pikatcost
{
    int i,j,k;
};


//0 ห้ามเดิน 1 เดินได้ 2 มีสมบัติต้องเก็บ
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int r,c;
    cin >> r >> c;
    vector<vector<int> > v(r,vector<int>(c));
    int treasure = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> v[i][j];
            if(v[i][j] == 2){
                treasure++;
            }
        }
    }

    queue<pikatcost> q;
    q.push({0,0,0});
    vector<vector<bool> > visited(r,vector<bool>(c,false));
    int ans = 0;

    vector<pii> direction = 
    {
        {1,0},{-1,0},
        {0,1},{0,-1}
    };

    while(!q.empty()){
        int x = q.front().i;
        int y = q.front().j;
        int cost = q.front().k;
        q.pop();
        
        if(visited[x][y]){
            continue;
        }

        visited[x][y] = true;
        if(v[x][y] == 2){ //เจอสมบัติต้องวิ่งไปกลับ
            ans += cost*2;
            treasure--;
        }
        if(treasure == 0){ //สมบัติหมดละ
            break;
        }

        for(int dir =0;dir<4;dir++){
            int newx = x + direction[dir].first; //move row
            int newy = y + direction[dir].second; //move col
            if(newx < 0 || newx >= r || newy < 0 || newy >= c || visited[newx][newy] || v[newx][newy] == 0){
                continue;
            }
            q.push({newx,newy,cost+1});
        }
    }
    cout << ans;

}