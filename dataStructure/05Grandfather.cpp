#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<long long,long long> relationmap;

long long samegrandfather(long long ch){
    if(relationmap.find(ch) == relationmap.end()) return 0;
    if(relationmap.find(relationmap[ch]) == relationmap.end()) return 0;
    return relationmap[relationmap[ch]];
}

int main(){
    int relnum,ask;
    cin >> relnum >> ask;

    long long father,child;
    while(relnum--){
        cin >> father >> child;
        
        relationmap[child] = father;
    }

    long long a,b;
    while(ask--){
        cin >> a >> b;
        long long grapaA = samegrandfather(a);
        long long grapaB = samegrandfather(b);
        if(a != b && grapaA == grapaB && (grapaA != 0 || grapaB != 0)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}