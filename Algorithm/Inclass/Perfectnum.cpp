#include <iostream>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    for(int x=a; x<= b;x++){
        int sum = 0;
        for(int j=1;j<x;j++){
            if(x%j == 0){
                sum += j;
            }
        }
        if(sum == x){
            cout << "x = " << x << " ";
        }
    }
}