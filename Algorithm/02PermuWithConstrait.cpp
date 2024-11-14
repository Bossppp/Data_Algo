#include <iostream>
#include <vector>
using namespace std;

void genPermu(int n,vector<int> &sol,int len,vector<bool> &used , vector<int> &before){
  if(len < n){
    for(int i=0;i<n;i++){
        if(used[i] == false && (before[i] == -1 || used[before[i]])){
            used[i] = true;
            sol[len] = i;
            genPermu(n,sol,len+1,used,before);
            used[i] = false;
        }
    }
  }else{
    for(auto &e : sol){
        cout << e << " ";
    }
    cout << endl;
  }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n , m;
    cin >> n >> m;
    vector<int> sol(n);
    vector<bool> used(n,false);
    vector<int> before(n,-1);
    while(m--){
        int a,b;
        cin >> a >> b;
        before[b] = a;
    }
    genPermu(n,sol,0,used,before);
}