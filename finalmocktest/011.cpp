#include <iostream>
#include <iostream>
#include <vector>
#include <tuple>
#include <set>

using namespace std;

class DSU {
    int *parent;
    int *rank;

public:
    DSU(int n){
        parent = new int[n]; 
        rank = new int[n];

        for(int i=0;i<n;i++){
            parent[i] = -1; //initialize array
            rank[i] = 1;
        }
    }

    int findset(int x){
        if(parent[x] == -1){
            return x;
        }
        return parent[x] = findset(parent[x]);
    }

    void unionset(int x,int y){
        int setx = findset(x);
        int sety = findset(y);

        if(setx != sety){
            if(rank[setx] < rank[sety]){
                parent[setx] = sety;
            }else if(rank[setx] > rank[sety]){
                parent[sety] = setx;
            }else{
                parent[sety] = setx;
                rank[setx]++; //increase high
            }
        }
    }
};

int kruskalminW(int vertex ,  set<tuple<int,int,int> > &edge){
    DSU dsu(vertex+5);
    int cost =0 ;
    for(auto e : edge){
        int w,a,b;
        w = get<0>(e);
        a = get<1>(e);
        b = get<2>(e);
        if(dsu.findset(a) != dsu.findset(b)){
            dsu.unionset(a,b);
            cost += w;
        }
    }
    return cost;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin >> n >> m;
    set<tuple<int,int,int> > edge;
    for(int i=0;i<m;i++){
        int w,a,b;
        cin >> w >> a >> b;
        a--,b--; //ให้เริ่มที่ 0
        //พวกโจทย์ให้เริ่มที่ 1 ทำให้ต้อง"จอง"อาเรย์ n+1 ช่อง 
        //แต่เราทำงี้ทำให้จองแค่ n ช่องได้ ​​​
        edge.insert({w,a,b});
    }

    cout << kruskalminW(n,edge);

}