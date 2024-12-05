#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> virus;

bool checkvirus(int start,int end,bool reverse){
    int n = end - start;
    //terminate case {0,1} or {1,0}
    if(n == 2){
        if(!reverse){
            return virus[start] == 0 && virus[start+1] == 1;
        }else{
            return virus[start] == 1 && virus[start+1] == 0;
        }
    }
    //divide
    int mid = (start+end)/2;
    //conquer
    if(!reverse){
        return (checkvirus(start,mid,false) || checkvirus(start,mid,true)) && checkvirus(mid,end,false);
    }else{
        return (checkvirus(mid,end,false) || checkvirus(mid,end,true)) && checkvirus(start,mid,true);
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    virus = vector<int>(pow(2,k));
    while(n--){
        for(int i=0;i<pow(2,k);i++){
            cin >> virus[i];
        }
        if(checkvirus(0,pow(2,k),false)){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
}