#include <iostream>
#include <vector>
typedef long long ll;

using namespace std;

ll mod = 1e9+7;
ll n;


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    
    ll prevprev = 1;
    ll prev = 3;

    ll a_n = 0;
    for(int i=3;i<=n;i++){
        a_n = (prevprev*2 + prev) % mod;
        prevprev = prev;
        prev = a_n;
    }
    cout << a_n;

}

//n = 1 : 1
//n = 2 : 3
//n = 3 : 5
//n = 4 : 11
//n = 5 : 21