#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int vertex,edge;

bool islinegraph(const vector<vector<int> > &adj,const vector<int> &component){
    int leafcount = 0; //count leaf
    for(int n : component){
        int deg = adj[n].size();
        if(deg == 1){
            leafcount++;
        }
        if(deg > 2){
            return false;
        }
    }
    return leafcount == 2 || component.size() == 1; //ใบต้องมีแค่ 2 อัน ถ้าไม่มี edge เชื่อมเลยต้องมีแค่ 1 อัน
}

void bfs(int vertex,vector<vector<int> > &adj,vector<bool> &visited,vector<int> &component){
    queue<int> q;
    q.push(vertex);
    visited[vertex] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        component.push_back(v);
        for(auto u : adj[v]){
            if(!visited[u]){
                visited[u] = true;
                q.push(u);
            }
        }
    }
}


int main(){
    cin >> vertex >> edge;
    vector<vector<int> > adj(vertex);
    for(int e=0;e<edge;e++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(vertex,false);
    int countLine = 0;
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            vector<int> component;
            bfs(i,adj,visited,component);
            if(islinegraph(adj,component)){
                countLine++;
            }
        }
    }
    cout << countLine << endl;
}