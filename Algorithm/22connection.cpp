#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <queue>
#include <set>

using namespace std;

int bfsmaxadj(int vertex,map<int,vector<int> > &adj,int k){
    queue<pair<int,int> > q;
    set<int> visited;
    visited.insert(vertex);
    q.push(make_pair(vertex,0));
    int maxadj = 0;
    while(!q.empty()){
        int node = q.front().first;
        int depth = q.front().second;
        q.pop();
        if(depth < k){
           for(auto e : adj[node]){
                if(visited.find(e) == visited.end()){
                    visited.insert(e);
                    q.push(make_pair(e,depth+1));
                }
            } 
        }
        maxadj++;
    }
    return maxadj;
}

int main(){
    int v,e,k;
    cin >> v >> e >> k;
    map<int,vector<int> > nodeadj;
    for(int i=0;i<e;i++){
        int a , b;
        cin >> a >> b;
        nodeadj[a].push_back(b);
        nodeadj[b].push_back(a);
    }


    int maxadj = 0;
    for(int i=0;i<v;i++){
        maxadj = max(maxadj,bfsmaxadj(i,nodeadj,k));
    }
    cout << maxadj;
}