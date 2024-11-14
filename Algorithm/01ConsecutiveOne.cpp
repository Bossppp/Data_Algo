#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;
size_t n,k;
vector<string> ans;

bool checking(const string &sol,int k){
    size_t tidone = 0;
    for(size_t i=0;i<n;i++){
        if(sol[i] == '1'){
            tidone++;
            if(tidone >= k){
                return true;
            }
        }else{
            tidone = 0;
        }
    }
    return false;
}


void combi(size_t &n,string& sol,size_t len){
    if(len < n){
        sol[len] = '0';
        combi(n,sol,len+1);
        sol[len] = '1';
        combi(n,sol,len+1);
    }else{
        if(checking(sol,k)){
            ans.push_back(sol);
        }
    }
}

int main(){
    cin >> n >> k;
    string sol = "";
    for(int i=0;i<n;i++){
        sol += '0';
    }
    combi(n,sol,0);

    for(auto &e : ans){
        cout << e << endl;
    }

}