#include <iostream>
#include <vector>
#include <limits.h>

typedef unsigned long long ull;
using namespace std;

ull finmaxXOR(int n,vector<int> &road,vector<bool> &visited,vector<ull> &maxw){
    ull maxsuay = 0;
    for(int i=1;i<n;i++){
        maxw[i] = road[0] ^ road[i];
    }

    visited[0] = true;
    for(int e =0;e<n-1;e++){
        ull maxedge = 0;
        ull nextnode = -1;
        for(int i=0;i<n;i++){
            if(!visited[i] && maxw[i] > maxedge){
                maxedge = maxw[i];
                nextnode = i;
            }
        }
        visited[nextnode] = true;
        maxsuay += maxedge;
        //cout << "maxedge: " << maxedge << endl;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                ull newmaxw = road[nextnode] ^ road[i];
                maxw[i] = max(maxw[i],newmaxw);
            }
        }
    }

    
    return maxsuay;
}

int main(){
    int n;
    cin >> n;
    vector<int> road(n);
    for(int i=0;i<n;i++){
        cin >> road[i];
    }
    vector<bool> visited(n,false);
    vector<ull> maxw(n,INT_MIN);

    cout << finmaxXOR(n,road,visited,maxw) << endl;

}