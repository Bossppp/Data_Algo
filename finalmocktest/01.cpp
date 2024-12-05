#include <iostream>
#include <vector>
#include <climits>
#include <tuple>

using namespace std;

int minkey(int vertex,vector<int> &cost,vector<bool> &visited){
    int min = INT_MAX;
    int min_index = -1;
    for(int i=0;i<vertex;i++){
        if(!visited[i] && cost[i] < min){
            min = cost[i];
            min_index = i;
        }
    }
    return min_index;
}

int primMST(int vertex ,vector<vector<int> > &edge, vector<tuple<int, int, int>> &mst_edges){
    vector<int> cost(vertex,INT_MAX);
    vector<bool> visited(vertex,false);
    vector<int> parent(vertex,-1);

    cost[0] = 0;
    parent[0] = -1;
    
    int totalcost = 0;

    for(int i=0;i<vertex;i++){
        int u = minkey(vertex,cost,visited);
        visited[u] = true;
        totalcost += cost[u];
        for(int v=0;v<vertex;v++){
            if(edge[u][v] && !visited[v] && edge[u][v] < cost[v]){
                cost[v] = edge[u][v];
                parent[v] = u; //ก่อนจะ v คือ u
            }
        }
    }

    //สร้าง edge ที่ทำให้ mst แล้วใส่เข้ามา
    for (int v = 1; v < vertex; v++) {
        if (parent[v] != -1) {
            mst_edges.push_back({parent[v]+1, v+1, edge[parent[v]][v]}); // Adjust to 1-based indexing
        }
    }

    return totalcost;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int> > adj(n,vector<int>(n,INT_MAX));
    for(int i=0;i<m;i++){
        int w,a,b;
        cin >> w >> a >> b;
        a--,b--;
        adj[a][b] = w;
        adj[b][a] = w;
    }
    vector<tuple<int, int, int>> mst_edges;

    cout << primMST(n,adj,mst_edges) << endl;

}