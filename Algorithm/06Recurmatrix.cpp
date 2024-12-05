#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> recurmatrix(int a,int b){
    if(a == 0){
        return {{b}};
    }
    vector<vector<int>> topelf = recurmatrix(a-1,b);
    vector<vector<int>> toprt  = recurmatrix(a-1,b-1);
    vector<vector<int>> botlf = recurmatrix(a-1,b+1);
    vector<vector<int>> botrt = recurmatrix(a-1,b);

    int size = pow(2,a);
    vector<vector<int>> res(size,vector<int>(size));

    int matrixpos = size/2;
    for(int i = 0; i < matrixpos ;i++){
        for(int j = 0; j < matrixpos ;j++){
            res[i][j] = topelf[i][j];
            res[i][j+ matrixpos] = toprt[i][j];
            res[i+matrixpos][j] = botlf[i][j];
            res[i+matrixpos][j+matrixpos] = botrt[i][j];
        }
    }
    return res;
}

int main(){
    int a,b;
    cin >> a >> b;
    vector<vector<int>> matrix = recurmatrix(a,b);
    for(const auto &i : matrix){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}