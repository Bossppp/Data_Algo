#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int bsearch3(int left,int right,int query,vector<int> &v){
    if(left == right){
        if(query < v[left]){
            return -1; //ไม่มีตัวที่น้อยกว่ามัน
        }else{
            return left;
        }
    }else{
        int mid = (left+right+1)/2;
        if(query < v[mid]){
            return bsearch3(left,mid-1,query,v);
        }else {
            int res = bsearch3(mid,right,query,v); //check ทางขวาว่ามีตัวที่ได้เหมือนกันมั้ย ถ้ามีก้เอาไม่มีก้คืน mid มา
            return (res != -1) ? res : mid; 
        }
    }
}

int main(){
    int n , m;
    cin >> n >> m;
    vector<int> v;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());

    while(m--){
        int query;
        cin >> query;

        cout << bsearch3(0,v.size()-1,query,v) << endl;

    }
}