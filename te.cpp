#include <iostream>
#include <vector>

using namespace std;

vector<string> recur(vector<vector<int> > &grid, int sr, int sc, int r, int c , string text){
    
    vector<string> ans;
    if(sr == r && sc == c) {
        ans.push_back(text);
        return ans;
    } 

    grid[sr][sc] = 1;
    if(sc < c && grid[sr][sc+1] != 1) {
        vector<string> movea = recur(grid,sr,sc+1,r,c,text+"A");
        ans.insert(ans.end(),movea.begin(),movea.end());
    }
    if(sr < r && grid[sr+1][sc] != 1) {
        vector<string> moveb = recur(grid,sr+1,sc,r,c,text+"B");
        ans.insert(ans.end(),moveb.begin(),moveb.end());
    }
    if(sr > 1 && grid[sr-1][sc] != 1){
        vector<string> movec = recur(grid,sr-1,sc,r,c,text+"C");
        ans.insert(ans.end(),movec.begin(),movec.end());
    }
    grid[sr][sc] = 0;

    return ans;
    
}

int main(){
    int r,c;
    cin >> r >> c;

    vector<vector<int> > grid(r+1, vector<int>(c+1));
    for(int i=1; i<=r ; i++){
        for(int j=1; j<=c ; j++){
            cin >> grid[i][j];
        }
    }

    // Start the recursion from the top-left corner (1, 1)
    vector<string> result = recur(grid, 1, 1, r, c, "");

    // Print all the paths found
    for (const auto& path : result) {
        cout << path << endl;
    }

    cout << "DONE" << endl;

    return 0;
    


}