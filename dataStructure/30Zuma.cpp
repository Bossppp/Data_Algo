#include <iostream>
#include <list>

using namespace std;

void printlist(list<int> l){
    for(auto i : l){
        cout << i << " ";
    }
    cout << endl;
}

int checkzuma(list<int> &l, list<int>::iterator &it, int v){
    auto itback = it;
    int j = 0;
    while(itback!=l.end()&&*itback==v){
        j++;
        itback--;
    }
    auto itfor = it;
    itfor++;
    while(itfor!=l.end()&&*itfor==v){
        j++;
        itfor++;
    }
    if(j>=3){
        itback++;
        it = l.erase(itback,itfor);
        return 1;
    }
    return 0;
}

int main(){
    int n,inserIdx,ball;
    cin >> n >> inserIdx >> ball;
    list<int> ball_list;
    while(n--){
        int color;
        cin >> color;
        ball_list.push_back(color);
    }

    auto it = ball_list.begin();
    for(int i=0;i<inserIdx;i++){
        it++;
    }
    ball_list.insert(it,ball);
    it--;
    int check = checkzuma(ball_list,it,ball);

    while(check){
        it--;
        if(it != ball_list.end()){
            check = checkzuma(ball_list,it,*it);
        }else{
            check = 0;
        }
    }

    //printlist(ball_list);

    printlist(ball_list);
        

}