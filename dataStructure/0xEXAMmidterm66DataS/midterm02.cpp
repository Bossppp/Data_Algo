#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    queue<int> node;
    node.push(m);

    vector<int> child;
    child.push_back(m);

    //create child heap
    while(!node.empty()){
        int node1 = node.front();
        node.pop();

        int left = node1*2+1;
        int right = node1*2+2;
        if(left < n){
            node.push(left);
            child.push_back(left);
        }
        if(right < n){
            node.push(right);
            child.push_back(right);
        }
    }

    //print parent heap
    size_t parenSi = n - child.size();
    cout << parenSi << endl;
    for(int j=0,i=0;i<n;i++){
        if(child[j] == i){
            j++;
            continue;
        }else{
            cout << i << " ";
        }
    }
}