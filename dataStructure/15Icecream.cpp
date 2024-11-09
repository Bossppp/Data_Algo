#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,start;
    cin >> n >> m >> start;
    vector<pair<int,int> > changecol;
    while(n--){
        //ตัดสินใจเปลี่ยนเงินเก็บ
        int dayindex,money;
        cin >> dayindex >> money;
        changecol.push_back(make_pair(dayindex,money));
    }
    sort(changecol.begin(),changecol.end()); 

    vector<int> changemoney(100005);
    long long sum = 0;
    int changeindex = 0;
    int currentMoney = start;
    for(int i=0;i<100005;i++){
        if(changeindex < changecol.size() && i == changecol[changeindex].first){
            currentMoney = changecol[changeindex].second;
            changeindex++;
        }
        sum += currentMoney;
        changemoney[i] = sum;
        //cout << changemoney[i] << " ";
    }

    while(m--){
        //วันโดนหลอกกับราคาไอติม
        int scam,icePrice;
        cin >> icePrice >> scam;
        
        if(changemoney[scam] >= icePrice){
            //cout << "value1: "<<changemoney[scam] << endl;
            //cout << *lower_bound(changemoney.begin(),changemoney.begin()+scam+1,icePrice) << " " << *changemoney.begin() << endl;
            cout << lower_bound(changemoney.begin(),changemoney.begin()+scam+1,icePrice) - changemoney.begin() << " ";
        }else{
            //cout << "value2: "<<changemoney[scam] << endl;
            //cout << *lower_bound(changemoney.begin()+scam,changemoney.end(),icePrice+changemoney[scam]) << " " << *changemoney.begin() << endl;
            cout << lower_bound(changemoney.begin()+scam,changemoney.end(),icePrice+changemoney[scam]) -changemoney.begin() << " ";
        }
    }
}