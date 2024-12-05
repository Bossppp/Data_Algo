#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    map<int,int> degcout;
    while(n--){
        string node;
        getline(cin,node);
        int deg =0;
        for(auto d : node){
            if(d == '1') deg++;
        }

        degcout[deg]++;
    }

    int maxdeg = 0;
    for(auto d : degcout){
        if(maxdeg < d.first){
            maxdeg = d.first;
        }
    }

    vector<int> storingdeg(maxdeg+1,0);
    for(auto d : degcout){
        storingdeg[d.first] = d.second;
    }

    for(int i=0;i<storingdeg.size();i++){
        cout << storingdeg[i] << " ";
    }
}