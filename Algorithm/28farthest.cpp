#include <climits>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int bellman(int vertex,vector<vector<int> > &v,int start){
    vector<int> distance(vertex,INT_MAX);
    vector<int> prev(vertex,-1);
    distance[start] = 0;
    for(int i=0;i<vertex-1;i++){
        for(int j=0;j<vertex;j++){
            for(int k=0;k<vertex;k++){
                if(v[j][k] != -1 && distance[j] != INT_MAX){
                    if(distance[k] > distance[j] + v[j][k]){
                        distance[k] = distance[j] + v[j][k];
                        prev[k] = j;
                    }
                } 
            }
        }
    }
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            if(v[i][j] != -1 && distance[i] != INT_MAX ){
                if(distance[j] > distance[i] + v[i][j]){
                return -1; 
                }
            }
        }
    }
    //find เมืองไกลสุด
    int maxdis = 0;
    for(auto d : distance){
        if(d != INT_MAX){
            maxdis = max(maxdis,d);
        }else{
            return -1; 
        }
    }
    return maxdis;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int> > v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int w;
            cin >> w;
            v[i][j] = w;
        }
    }

    cout << bellman(n,v,0) << endl;

}