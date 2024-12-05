#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > v;

void infectatday(int r,int c,int day){
    queue<pair<int,int> > pikatone;
    vector<pair<int,int> > direction = {{-1,0},{1,0},{0,-1},{0,1}};
    
    //collect 1 as พิกัด(i,j)
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(v[i][j] == 1){
                pikatone.push(make_pair(i,j));
            }
        }
    }

    //pandemic
    while(!pikatone.empty() && day--){
        int size = pikatone.size();
        for(int i=0;i<size;i++){
            auto x = pikatone.front().first;
            auto y = pikatone.front().second;
            pikatone.pop();
            for(auto di : direction){
                auto newx = x + di.first;
                auto newy = y + di.second;

                if(newx < 0 || newy < 0 || newx >= r || newy >= c || v[newx][newy] != 0){
                    continue;
                }
                
                v[newx][newy] = 1;
                pikatone.push(make_pair(newx,newy));

            }
        }
    }
}

int countinfect(int r,int c){
    int countinf = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(v[i][j] == 1){
                countinf++;
            }
        }
    }
    return countinf;
}

//0 is nothing,1 is infect,2 is immune
int main(){
    //input
    int r,c,day;
    cin >> r >> c >> day;
    v.resize(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> v[i][j];
        }
    }

    //process
    infectatday(r,c,day);

    //test
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    //output
    cout << countinfect(r,c) << endl;

}