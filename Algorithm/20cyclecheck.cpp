#include <iostream>
#include <vector>

using namespace std;

bool dfscycle(int vertex,int parent,vector<vector<int> > &graph,vector<bool> visit){
    visit[vertex] =true;
    for(auto e : graph[vertex]){
        if(!visit[e]){
            if(dfscycle(e,vertex,graph,visit)){
                return true;
            }
        }else{
            if(e != parent){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    
    for(int i=0;i<t;i++){
        int node , edge;
        cin >> node >> edge;
        vector<vector<int> > adj(node);
        for(int e =0;e<edge;e++){
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool> visit(node,false);
        bool iscycle = false;
        for(int i=0;i<node;i++){
            if(!visit[i] && dfscycle(i,-1,adj,visit)){
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