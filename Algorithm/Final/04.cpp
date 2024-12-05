#include <iostream>
#include <vector>
#include <climits>

using namespace std;
typedef pair<int,int> pii;

int main(){
    int n,m,t;
    cin >> n >> m >> t;
    vector<int> tt(t);
    vector<vector<pii> > graph(n);
    for(int i=0;i<t;i++){ 
        cin >> tt[i];
        tt[i]--;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--,b--;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }

    vector<vector<int> > dist(n,vector<int>(n,INT_MAX));
    for(int i=0;i<n;i++){
        dist[i][i] = 0;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j] > (dist[i][k] + dist[k][j]) && dist[i][k] != INT_MAX && dist[k][j] != INT_MIN){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int res = INT_MAX;
    for(auto e : dist){
        res = min(res,e[tt[0]]);
    }
    cout << res;

}