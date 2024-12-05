#include <iostream>
#include <vector>
#include <tuple>
#include <utility>

using namespace std;
typedef pair<int,int> pii;



bool dfs (int vertex,int target,int sum,vector<vector<pii> > &graph,vector<bool> &visit){
    if(sum == target){
        return true;
    }
    visit[vertex] = true;
    for(auto e : graph[vertex]){
        int v = e.first;
        int w = e.second;
        if(!visit[v]){
            if(dfs(v,target,sum+w,graph,visit)){
                return true;
            }
        }
    }
    visit[vertex] = false;
    return false;
}

int main(){
    int n,m;
    cin >> n >> m;

    vector<int> ki(8);
    for(int i=0;i<8;i++){
        cin >> ki[i];
    }
    vector<vector<pii> > grapgadj(n);
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        grapgadj[a].push_back(make_pair(b,w));
        grapgadj[b].push_back(make_pair(a,w));
    }

    //isSimplepath sum weight equal ki
    vector<bool> visit(n,false);
    for(int i=0;i<ki.size();i++){
        bool found = false;
        for(int node =0 ; node < n;node++){
            if(dfs(node,ki[i],0,grapgadj,visit)){
                found = true;
                break;
            }
        }
        cout << (found ? "YES" : "NO") << endl;
    }
}