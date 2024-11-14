#include <iostream>
#include <vector>

using namespace std;
int n,r;

void combi(int n,vector<int> &sol,int len,int r,int choose){
    if(len < n){
        if(len - choose < n-r){
            sol[len] = 0;
            combi(n,sol,len+1,r,choose);
        }
        if(choose < r){
            sol[len] = 1;
            combi(n,sol,len+1,r,choose+1);
        }
    }else{
        for(auto &e : sol){
            cout << e;
        }
        cout << endl;
    }
}

//put 0,1 in sol[step]
//recursive untill all n are filled
void combiV1Bynatte (vector<int> &sol,int step){
    if(step == n){
        int one = 0;
        for(auto &e : sol) if(e == 1)  one++;
        if(one != r) return;

        for(auto &e:sol) cout << e;
        cout << endl;
    }else{
        sol[step] = 0;
        combiV1Bynatte(sol,step+1);
        sol[step] = 1;
        combiV1Bynatte(sol,step+1);
    }
}

void combiV2Bynatte (vector<int> &sol,int step,int one){
    if(step == n){
        // int one = 0;
        // for(auto &e : sol) if(e == 1)  one++;
        // if(one != r) return;

        for(auto &e:sol) cout << e;
        cout << endl;
    }else{
        int zero=step-one;
        int zero_quota = n-r;
        if(step - one < n-r){
            sol[step] = 0;
            combiV2Bynatte(sol,step+1,one);
        }
        if(one < r){
            sol[step] = 1;
            combiV2Bynatte(sol,step+1,one+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> r >> n;
    vector<int> sol(n);
    //combi(n,sol,0,r,0);
    //combiV1Bynatte(sol,0);
    combiV2Bynatte(sol,0,0);
}