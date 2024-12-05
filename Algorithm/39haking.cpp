#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;
typedef pair<int,int> pii;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> hackfirst;
    for(int i=0;i<k;i++){
        int s;
        cin >> s;
        hackfirst.push_back(s);
    }
    vector<int> hacktime;
    for(int i=0;i<n;i++){
        int time;
        cin >> time;
        hacktime.push_back(time);
    }
    vector<vector<int> > serveredge(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        serveredge[a].push_back(b);
        serveredge[b].push_back(a);
    }
    vector<int> mindist(n,INT_MAX);
    priority_queue<pii,vector<pii>,greater<pii> > pq;

    //initial hackfirst
    for(auto hf : hackfirst){
        mindist[hf] = hacktime[hf];
        pq.push(make_pair(hacktime[hf],hf));
    }

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(auto v : serveredge[u]){
            if(mindist[v] > mindist[u] + hacktime[v]){
                mindist[v] = mindist[u] + hacktime[v];
                pq.push(make_pair(mindist[v],v));
            }
        }
    }

    int earliest = 0;
    for(auto e : mindist){
        earliest = max(earliest,e); //ทุกอันโดน hack แสดงว่ามันคือเวลา"สุดท้าย"ที่น้อยที่สุด
    }
    cout << earliest;

}