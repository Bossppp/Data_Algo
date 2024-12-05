#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <utility>
#include <set>
#include <map>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

typedef pair<int,int> pii;

int main(){
    //dijkstra
    int vertex,edge,start;
    cin >> vertex >> edge >> start;
    vector<vector<pii>> adjgraph(vertex);
    for(int i=0;i<edge;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adjgraph[u].push_back({v,w});
        adjgraph[v].push_back({u,w});
    }

    vector<int> dist(vertex,INT_MAX);
    vector<int> prev(vertex,-1);
    vector<bool> visited(vertex,false);

    dist[start] = 0; //สมมติว่าโหนดแรกไม่เริ่มที่ 0 (มีให้ใส่ start) ถ้าไม่มี ก็ dist[0] = 0;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push({0,start});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(visited[u]){
            continue;
        }
        visited[u] = true;
        for(auto e : adjgraph[u]){
            int v = e.first;
            int w = e.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push({dist[v],v});
                
            }
        }
    }

    //dfs
    stack<int> s;
    int startnode = 0;
    s.push(startnode);
    vector<bool> visitedDFS(vertex,false);
    visitedDFS[startnode] = true;
    while(!s.empty()){
        int u = s.top();
        s.pop();
        for(auto e : adjgraph[u]){
            int v = e.first;
            if(!visitedDFS[v]){
                visitedDFS[v] = true;
                s.push(v);
            }
        }
    }

    //bfs
    queue<int> q;
    q.push(startnode);
    vector<bool> visitedBFS(vertex,false);
    visitedBFS[startnode] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto e : adjgraph[u]){
            int v = e.first;
            if(!visitedBFS[v]){
                visitedBFS[v] = true;
                q.push(v);
            }
        }
    }

    //binarysearch
    int left = 0 ,right = n-1;
    while(left < right){
        int mid = (left+right)/2;
        if(arr[mid] < target){
            left = mid+1;
        }else if(arr[mid] > target){
            right = mid-1;
        }else {
            left = right = mid;
        }
    }

    bool floydWarshallMatrix(vector<vector<int>>& graph) {
    int n = graph.size();

    // Convert -1 to INT_MAX for unreachable paths
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == -1) graph[i][j] = INT_MAX;
            if (i == j) graph[i][j] = 0;
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Check to avoid integer overflow
                if (graph[i][k] != INT_MAX && 
                    graph[k][j] != INT_MAX && 
                    graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    // Check for negative cycles
    for (int i = 0; i < n; i++) {
        if (graph[i][i] < 0) {
            return true; // Negative cycle detected
        }
    }

    bool floydWarshallList(int n, vector<vector<Edge>>& graph) {

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    // Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
        for (auto& edge : graph[i]) {
            dist[i][edge.to] = min(dist[i][edge.to], edge.weight);
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Check to avoid integer overflow
                if (dist[i][k] != INT_MAX && 
                    dist[k][j] != INT_MAX && 
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Check for negative cycles
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            return true; // Negative cycle detected
        }
    }

    struct Edge {
        int to, weight;
    };



}