#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int vertex;
    cin >> vertex;
    map<int,int> cntdeg;
    int maxdeg = 0;
    vector<vector<int> > adj(vertex,vector<int>(vertex));
    for(int i=0;i<vertex;i++){
        int countdeg = 0;
        for(int j=0;j<vertex;j++){
            int deg;
            cin >> deg;
            if(deg == 1) countdeg++;
        }
        cntdeg[countdeg]++;
        maxdeg = max(maxdeg,countdeg);
    }
    for(int i=0;i<=maxdeg;i++){
        cout << cntdeg[i] << " ";
    }


}