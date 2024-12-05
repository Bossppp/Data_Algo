#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tpiii;

int main(){
    int R,C;
    cin >> R >> C;
    vector<vector<int> > gridfee(R,vector<int>(C));
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> gridfee[i][j];
        }
    }
    vector<pii> direnction = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int> > distance(R,vector<int>(C,INT_MAX));
    vector<vector<bool> > visited(R,vector<bool>(C,false));

    distance[0][0] = 0; //initialize
    
    priority_queue<tpiii,vector<tpiii>,greater<tpiii> > pq;
    pq.push({0,0,0}); //initialize
    while(!pq.empty()){
        int x = get<0>(pq.top());
        int y = get<1>(pq.top());
        int fee = get<2>(pq.top());
        pq.pop();
        
        for(int i=0;i<4;i++){
            int newx = x + direnction[i].first;
            int newy = y + direnction[i].second;
            if(newx < 0 || newx >= R || newy < 0 || newy >= C || visited[newx][newy]){
                continue;
            }
            if(distance[newx][newy] > fee + gridfee[newx][newy]){
                distance[newx][newy] = fee + gridfee[newx][newy];
                pq.push({newx,newy,distance[newx][newy]});
            }
        }
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout << distance[i][j] << " ";
        }
        cout << endl;
    }
    
}