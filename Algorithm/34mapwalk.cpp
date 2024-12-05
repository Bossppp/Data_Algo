#include <iostream>
#include <vector>

using namespace std;

int R,C;
vector<vector<int> > table;
vector<vector<bool> > visited;

void walknattee(int r,int c,vector<char> &path){
    //cout << "r: " << r << " c: " << c << " depth : " << path.size() << endl;
    if(r == R && c == C){
        for(auto &p : path){
            cout << p;
        }
        cout << endl;
        return;
    }

    int newR,newC;
    vector<vector<int> > direction = {{0,1},{1,0},{-1,0}};
    vector<char> action = {'A','B','C'};

    for(int i=0;i<direction.size();i++){
        newR = r + direction[i][0];
        newC = c + direction[i][1];
        if(!visited[newR][newC] && table[newR][newC] == 0){
            visited[newR][newC] = true;
            path.push_back(action[i]);
            walknattee(newR,newC,path);
            path.pop_back();
            visited[newR][newC] = false;
        }
    }


}

int main(){
    cin >> R >> C;
    table.resize(R+2,vector<int>(C+2));
    visited.resize(R+2,vector<bool>(C+2,false));
    
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin >> table[i][j];
        }
    }
    for(int i=0;i<=R+1;i++){
        table[i][0] = 1;
        table[i][C+1] = 1;
    }
    for(int i=0;i<=C+1;i++){
        table[0][i] = 1;
        table[R+1][i] = 1;
    }

    vector<char> path;
    visited[1][1] = true;
    walknattee(1,1,path);
    cout << "DONE";
}