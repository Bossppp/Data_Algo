#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int k,n;
    cin >> k;
    while(k--){
        cin >> n;
        vector<vector<double> > graph(n,vector<double>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> graph[i][j];
            }
        }
        //floyd because หาทุกคู่สกุลเงิน
        bool hasinfinite = false;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){ //use max and multiple เพราะเราต้องการค่ามากสุดและเงินมันต้องคูณเพราะเป็น"อัตรา"การแลกเปลี่ยน
                    graph[i][j] = max(graph[i][j] , graph[i][k] * graph[k][j]);
                    if(graph[j][j] > 1){
                        hasinfinite = true;
                        break;
                    }
                }
                if(hasinfinite){
                    break;
                }
            }
            if(hasinfinite){
                break;
            }
        }
        if(hasinfinite){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}