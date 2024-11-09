#include <iostream>
#include <string>

namespace CP {
    template<typename T1,typename T2>
    class pair{
        public:
        T1 first;
        T2 second;

        bool operator>(const pair<T1,T2> &other) const{
            return (first > other.first) || (first == other.first && second > other.second);
        }
    };

}
int main(){
    CP::pair<int,std::string> p1;
    CP::pair<int,std::string> p2;
    p1.first = 10; p2.first = 20;
    p1.second = "boss"; p2.second = "somchai";

    if(p1>p2){
        std::cout << "yes";
    }else {
        std::cout << "no";
    }
}