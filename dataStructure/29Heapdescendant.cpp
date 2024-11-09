#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n,descend;
    cin >> n >> descend;
    queue<int> nodes;
    nodes.push(descend);
    
    //count the number of descendants
    int countdes = 0;
    while(!nodes.empty()){
        int node = nodes.front();
        countdes++;
        nodes.pop();

        int leftnode = node*2+1;
        int rightnode = node*2+2;

        if(leftnode < n){
            nodes.push(leftnode);
        }
        if(rightnode < n){
            nodes.push(rightnode);
        }
    }

    cout << countdes << endl;

    nodes.push(descend);
    // Print the descendants
    while(!nodes.empty()){
        int node = nodes.front();
        nodes.pop();
        cout << node << " ";
        int leftnode = node*2+1;
        int rightnode = node*2+2;

        if(leftnode < n){
            nodes.push(leftnode);
        }
        if(rightnode < n){
            nodes.push(rightnode);
        }
    }


}