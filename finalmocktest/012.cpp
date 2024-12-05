#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;
typedef pair<int,int> pii;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<pii> > adj(n);
    for(int i=0;i<m;i++){
        int w,a,b;
        cin >> w >> a >> b;
        a--,b--;
        adj[a].push_back(make_pair(b,w));
        adj[b].push_back(make_pair(a,w));
    }

    vector<bool> vis(n,false);
    vector<int> mstw(n,INT_MAX);
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push(make_pair(0,0));
    mstw[0] = 0;
    int totalcost = 0;
    while(!pq.empty()){
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        totalcost += w;
        for(auto vw : adj[u]){
            int ww = vw.second;
            int v = vw.first;
            if(!vis[v] && mstw[v] > ww){
                mstw[v] = ww;
                pq.push(make_pair(ww,v));
            }
        }
    }
    cout << totalcost;
}