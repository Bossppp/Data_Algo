#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
typedef pair<int,int> pii;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n , cost12;
    cin >> n >> cost12;
    vector<vector<pii> > way(n+1);
    //iniaitlize following problem
    way[1].push_back(make_pair(2,cost12));
    way[2].push_back(make_pair(1,cost12));

    for(int i=3;i<=n;i++){
        int motorway;
        cin >> motorway;
        while(motorway--){
            int v,fee;
            cin >> v >> fee;
            way[i].push_back(make_pair(v,fee));
            way[v].push_back(make_pair(i,fee));
        }
        priority_queue<pii,vector<pii>,greater<pii> > pq;
        vector<int> distance(i+1,INT_MAX);
        pq.push(make_pair(0,1));
        distance[1] = 0;

        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            for(auto e : way[u]){
                int v = e.first;
                int w = e.second;
                if(distance[v] > distance[u] + w){
                    distance[v] = distance[u] + w;
                    pq.push(make_pair(distance[v],v));
                }
            }
        }
        cout << distance[2] << " ";
    }
}