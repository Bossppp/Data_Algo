#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main(){
    int n , elecNeed;
    cin >> n >> elecNeed;
    map<string,int> mem2score;

    for(int i=0;i<n;i++){
        string sorsor;
        cin >> sorsor;
        mem2score[sorsor]++;
    }

    //push to q
    priority_queue<pair<int,string>> scoreorder;
    for(auto e : mem2score){
        scoreorder.push({e.second,e.first});
    }

    while(elecNeed > 1 && !scoreorder.empty()){
        scoreorder.pop();
        elecNeed--;
    }
    cout << scoreorder.top().first;

    
}