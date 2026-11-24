#include <iostream>
#include <string>
using namespace std;

namespace CP {      //! CP::pair

    template <typename T1, typename T2>     //* T1 type of first T2 type of second
    class pair{
        public:
            T1 first;       //* First value
            T2 second;      //* Second value
    };

}



int main() {
    
    CP::pair<int, string> p1, p2;
    p1.first = 40;
    p1.second = "Leonard";

    CP::pair<int, string> a(p1);    //? Copy constructor
    p2 = p1;

    cout << p2.first << " " << p2.second << endl;

}