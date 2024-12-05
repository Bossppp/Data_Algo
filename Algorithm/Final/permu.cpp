#include <iostream>
#include <vector>
using namespace std;

int n;

void gen(string s,int ia,int jb,int kc,vector<string> &sol,int cnt){
    if(cnt == n){
        sol.push_back(s);
        return;
    }
    if(ia > 0) gen(s+"A",ia-1,jb,kc,sol,cnt+1);
    if(jb > 0) gen(s+"B",ia,jb-1,kc,sol,cnt+1);
    if(kc > 0) gen(s+"C",ia,jb,kc-1,sol,cnt+1);
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int i,j,k;
    cin >> n >> i >> j >> k;
    //sol.resize(n);
    //i is a,j is b,k is c
    vector<string> sol;
    gen("",i,j,k,sol,0);
    cout << sol.size() << endl;
    for(auto &e : sol){
        cout << e << endl;
    }   
    

}