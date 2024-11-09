#include <set>
#include <iostream>
using namespace std;

int main(){
    multiset<int> sn;
    int m,n;
    cin >> n >> m;
    //cout << n << " " << m;
    int num,mum;
    for(int i=0;i<n;i++){
        cin >> num;
        sn.insert(num);
    }
    while(m--){
        bool found = false;
        cin >> mum;
        //cout << m << endl;
        for(auto s : sn){
            if(sn.find(mum-s) != sn.end() && (mum-s != s)){
                //cout << mum << endl;
                found = true;
                break;
            }
        }
            if(found){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
    }
}
