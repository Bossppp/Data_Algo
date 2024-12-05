#include <iostream>
#include <vector>
using namespace std;

int bstnear(vector<int> &numsp,int query,int left,int right){
    if(left == right){
        if(query < numsp[left]){
            return -1;
        }else{
            return numsp[left];
        }
    }else{
        int mid = (left+right+1)/2;
        if(query > numsp[mid]){
            return bstnear(numsp,query,mid,right);
        }else if(query < numsp[mid]){
            return bstnear(numsp,query,left,mid-1);
        }else{
            return numsp[mid];
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> numspare;
    vector<int> numquery;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        numspare.push_back(temp);
    }
    for(int i=0;i<m;i++){
        int temp;
        cin >> temp;
        numquery.push_back(temp);
    }

    for(int i=0;i<numquery.size();i++){
        cout << bstnear(numspare,numquery[i],0,numspare.size()-1) << endl;
    }
}