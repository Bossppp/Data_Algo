#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    std::stack<std::vector<std::queue<int>>> alltemp;
    while(!a.empty()){
        std::vector<std::queue<int>> vectortemp;
        for(auto q : a.top()){
            std::queue<int> temp;
            while(!q.empty()){
                if(q.front() == from){
                    temp.push(to);
                    q.pop();
                }else{
                    temp.push(q.front());
                    q.pop();
                }
            }
            vectortemp.push_back(temp);
        }
        a.pop();
        alltemp.push(vectortemp);
    }
    while(!alltemp.empty()){
        a.push(alltemp.top());
        alltemp.pop();
    }
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    std::map<string, std::pair<std::priority_queue<int>, int>> alltemp;
    for(auto keyval : a){ //keyval.fisrt = string : keyval.second = pair<pq,int>
        std::priority_queue<int> pqtemp;
        int inttemp;
        while(!keyval.second.first.empty()){
            if(keyval.second.first.top() == from){
                pqtemp.push(to);
                keyval.second.first.pop();
            }else{
                pqtemp.push(keyval.second.first.top());
                keyval.second.first.pop();
            }
        }
        if(keyval.second.second == from){
            inttemp = to;
        }else{
            inttemp = keyval.second.second;
        }

        alltemp[keyval.first] = {pqtemp,inttemp};
    }
    a.clear();
    for(auto m : alltemp){
        a[m.first] = m.second;
    }
    
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
    std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> alltemp;
    for(auto pair : a){
        std::list<int> listtemp;
        for(auto l : pair.first){
            if(l == from){
                listtemp.push_back(to);
            }else{
                listtemp.push_back(l);
            }
        }
        std::map<int,std::pair<int,string>> maptemp;
        for(auto m : pair.second){
            int key = m.first;
            if(key == from){
                key = to;
            }
            if(m.second.first == from){
                maptemp[key] = {to,m.second.second};
            }
        }
        alltemp.insert({listtemp,maptemp});
    }
    a.clear();
    for(auto t : alltemp){
        a.insert(t);
    }
}

#endif
