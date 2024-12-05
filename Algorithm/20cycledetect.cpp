#include <vector>
#include <iostream>

using namespace std;

bool dfscheck(int vertex,vector<vector<int> > &adj,vector<bool> &visited,int parent){
    visited[vertex] = true;
    for(auto e : adj[vertex]){
        if(!visited[e]){
            if(dfscheck(e,adj,visited,vertex)){
                return true;
            }
        }else if(e != parent){
            return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    int vertex,edge,edconA,edconB;
    for(int i=0;i<t;i++){
        cin >> vertex >> edge;
        vector<vector<int> > edcon(vertex);
        for(int e=0;e<edge;e++){
            cin >> edconA >> edconB;
            //undirected a-b must have b-a;
            edcon[edconA].push_back(edconB);
            edcon[edconB].push_back(edconA);
        } 

        vector<bool> visited(vertex,false);
        bool iscycle = false;
        for(int v=0;v<vertex;v++){
            if(!visited[v] && dfscheck(v,edcon,visited,-1)){
                iscycle = true;
                break;
            }
        }

        if(iscycle){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
        
    }
}