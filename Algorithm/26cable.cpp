#include <iostream>
#include <vector>
#include <limits.h>
#include <utility>
#include <set>

using namespace std;

int findmincostWithPrim(int N,vector<vector<int> > &cost,vector<int> &dist,vector<bool> &visited){
    dist[0] = 0;
    int totalcost = 0;
    set<pair<int,int> > s;
    s.insert(make_pair(0,0));

    while(!s.empty()){
        pair<int,int> p = *s.begin();
        s.erase(s.begin());
        int u = p.second;
        visited[u] = true;
        totalcost += p.first;

        for(int i=0;i<N;i++){
            if(!visited[i] && dist[i] > cost[u][i]){
                s.erase(make_pair(dist[i],i));
                dist[i] = cost[u][i];
                s.insert(make_pair(dist[i],i));
            }
        }
    }

    return totalcost;
}

int main(){
    int N;
    cin >> N;
    vector<vector<int> > v(N,vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j = i+1;j<N;j++){
            int a;
            cin >> a;
            v[i][j] = a;
            v[j][i] = a;
        }
    }
    vector<int> dist(N,INT_MAX);
    vector<bool> visited(N,false);

    cout << findmincostWithPrim(N,v,dist,visited) << endl;
}

