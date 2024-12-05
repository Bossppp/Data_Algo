#include <iostream>
#include <vector>

using namespace std;

void dfscc(int vertex,vector<vector<int> > &adj,vector<bool> &visited){
    visited[vertex] = true;
    for(auto e : adj[vertex]){
        if(!visited[e]){
            dfscc(e,adj,visited);
        }
    }
}

int concomcnt(int vertex,vector<vector<int> > &adj){
    vector<bool> visited(vertex+5,false);
    int concomcount = 0;
    for(int i=1;i<=vertex;i++){
        if(!visited[i]){
            dfscc(i,adj,visited);
            concomcount++;
        }
    }
    return concomcount;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int vertex , edge;
    cin >> vertex >> edge;
    vector<vector<int> > adj(vertex+5);
    for(int i=0;i<edge;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    cout << concomcnt(vertex,adj);

}