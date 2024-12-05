#include <iostream>
#include <vector>

using namespace std;

int n,k;

int dpCof[35][35] = {0};
int dpCof2[35][35] = {0};

//memo {topdown}
int binomialCo(int n,int k){
    if(k == 0 || k == n) return 1;
    if(dpCof[n][k] != 0) {
        return dpCof[n][k]; 
        //have it before
    }
    int res = binomialCo(n-1,k-1) + binomialCo(n-1,k);
    dpCof[n][k] = res;
    
    return res;
}

//turbulization {bottomup}
int binomialCof(int n,int k){
    for(int i=0;i<=n;i++){
        dpCof2[i][0] = 1;
        dpCof2[i][i] = 1;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            dpCof2[i][j] = dpCof2[i-1][j-1] + dpCof2[i-1][j];
        }
    }
    return dpCof2[n][k];
}

int main(){
    cin >> n >> k;
    //cout << binomialCo(n,k);
    cout << binomialCof(n,k);
}