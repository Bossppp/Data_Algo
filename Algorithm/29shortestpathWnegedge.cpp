#include <iostream>
#include <vector>
#include <climits>

using namespace std;
typedef pair<int,int> pii;

bool hasnegativecycle = false;

void bellman(int vertex,vector<vector<pii> > &graph,int start,vector<int> &distance){
    distance[start] = 0;
    for(int i=0;i<vertex-1;i++){
        for(int j=0;j<vertex;j++){
            for(auto e : graph[j]){
                int v = e.first;
                int w = e.second;
                if(distance[j] != INT_MAX && distance[v] > distance[j] + w){
                    distance[v] = distance[j] + w;
                }
            }
        }
    }
    for(int i=0;i<vertex;i++){
        for(auto e : graph[i]){
            int v = e.first;
            int w = e.second;
            if(distance[v] > distance[i] + w){
                hasnegativecycle = true;
            }
        }
    }
}

int main(){
    int vertex,edge,start;
    cin >> vertex >> edge >> start;
    vector<vector<pii> > adjgraph(vertex);
    for(int i=0;i<edge;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adjgraph[u].push_back(make_pair(v,w));
    }
    vector<int> distance(vertex,INT_MAX);

    bellman(vertex,adjgraph,start,distance);

    if(hasnegativecycle){
        cout << "-1";
    }else{
        for(auto e : distance){
            if(e != INT_MAX){
                cout << e << " ";
            }
        }
    }

}
