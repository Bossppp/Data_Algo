#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool sortspecial (pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main(){
    std::ios::sync_with_stdio(false); cin.tie(0);
    int ep,ask;
    cin >> ep >> ask;
    vector<pair<int,int> > epDate;
    while(ep--){
        int ye,me;
        cin >> ye >> me;
        epDate.push_back(make_pair(ye,me));
    }
    sort(epDate.begin(),epDate.end(),sortspecial);

    vector<pair<int,int> > askDate;
    for(int i=0;i<ask;i++){
        int ya,ma;
        cin >> ya >> ma;
        askDate.push_back(make_pair(ya,ma));
    }

    //checking && output
    // for(int i=0;i<ask;i++){
    //     int j = 0;
    //     while(j < epDate.size() && epDate[j] < askDate[i]){
    //         j++;
    //     }
    //     if(j < epDate.size() && epDate[j] == askDate[i]){
    //         cout << "0 0" << " "; //found
    //     }else{
    //         if(j == 0){
    //             cout << "-1 -1" << " ";
    //         }
    //         for(int k=j-1;k>=0;k--){
    //             if(epDate[k] < askDate[i]){
    //                 cout << epDate[k].first << " " << epDate[k].second << " ";
    //                 break;
    //             }
    //         }
    //     }
    // }

    
    for(int i=0;i<ask;i++){
        //binary search checking ค่อยๆหั่นทีละครึ่งๆ
        int lf = 0, rt = epDate.size();
        while(lf < rt){
            int mid = (lf+rt)/2;
            if(askDate[i] > epDate[mid]){
                lf = mid+1;
            }else if(askDate[i] < epDate[mid]){
                rt = mid;
            }else{
                lf = rt = mid;
            }
            //cout << "lf: " << lf << " rt: " << rt << endl;
        }

        //output
        if(epDate[rt] == askDate[i]){
            cout << "0 0" << " ";
        }else{
            //หาไม่เจอไรเลย
            if(lf == 0){
                cout << "-1 -1" << " ";
            }else{
                //เจอแต่ตัวก่อนหน้า
                cout << epDate[lf-1].first << " " << epDate[lf-1].second << " ";
            }
        }
    }
    
}