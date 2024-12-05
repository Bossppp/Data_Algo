#include <iostream>

using namespace std;

int arr[500][500];
void genrecur(int a,int b,int r,int c){
    if(a == 0){
        arr[r][c] = b;
        return;
    }
    int halfsize = (1<<a)>>1;
    genrecur(a-1,b,r,c);
    genrecur(a-1,b-1,r,c+halfsize);
    genrecur(a-1,b+1,r+halfsize,c);
    genrecur(a-1,b,r+halfsize,c+halfsize);
    
}
int main(){
    int a,b;
    cin >> a >> b;
    genrecur(a,b,0,0);
    int s = 1<<a;
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}