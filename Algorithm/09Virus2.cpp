#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int count_1(string viruscode){
    int count = 0;
    for(char e : viruscode){
        if(e == '1'){
            count++;
        }
    }
    return count;
}

bool viruscheck(string covid){
    if(covid.size() == 1) return true;
    
    int mid = covid.size()/2;
    string a = covid.substr(0,mid);
    string b = covid.substr(mid);

    if(abs(count_1(a) - count_1(b)) > 1){
        return false;
    }else{
        return viruscheck(a) && viruscheck(b);
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    while(n--){
        string viruscode(pow(2,k),'0');
        for(int i=0;i<pow(2,k);i++){
            cin >> viruscode[i];
        }

        if(viruscheck(viruscode)){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
    }
}