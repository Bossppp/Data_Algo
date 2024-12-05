#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> ans;
int n,k;

bool checktidone(const string &sol,int k){
    int tidone = 0;
    for(int i=0;i<n;i++){
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

void genbit (int &n, string &bit,int len){
    if(len == n){
        if(checktidone(bit,k)){
             ans.push_back(bit);
        }
    }else{
        bit[len] =  '0';
        genbit(n,bit,len+1);
        bit[len] = '1';
        genbit(n,bit,len+1);
    }
}

int main(){
    cin >> n >> k;
    string bit = "";
    for(int i=0;i<n;i++){
        bit += '0';
    }
    genbit(n,bit,0);

    for(auto &e : ans){
        cout << e << endl;
    }

}