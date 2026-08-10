#include <iostream>
#include <string>
#include <set>
#include <queue>
using namespace std;

namespace CP {      

    template <typename T1, typename T2>     
    class pair{
        public:             //* Operator 
            T1 first;       // a.oparator==(b)
            T2 second;      // operator==(a,b)
            
            bool operator==(const pair<T1,T2> &other ) const {          //* parametor
                return (first == other.first && second == other.second);    
            }
                    // const& : pass by reference , don't modify other
                    // const : don't modify object

            bool operator<(const pair<T1,T2> &other) const {
                return (first < other.first) ||
                        (first == other.first && second < other.second);
            }
    };

}



int main() {
    
    CP::pair<int, string> p1, p2;
    p1.first = 40;
    p1.second = "Leonard";

    CP::pair<int, string> a(p1);    //? Copy constructor
    p2 = p1;                        //? Copy assignment

    cout << (p1 == p2) << '\n';     //* '\n' is faster than endl;
    cout << (p1 < a) << '\n';

    set<CP::pair<int,int>> s;
    s.insert({10,20});

    cout << s.begin()->second << '\n';  //! begin() = iterator

    p2.first = 30;
    p2.second = "Brown";

    return 0;

}