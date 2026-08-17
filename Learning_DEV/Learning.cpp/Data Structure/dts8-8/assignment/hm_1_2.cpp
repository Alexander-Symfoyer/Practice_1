#include <iostream>
#include <vector>


using namespace std;


namespace CP {

    template<typename T1, typename T2>
    class pair {
        public:
            T1 first;
            T2 second;

            pair() : first(), second() { }              
            pair(const T1 &a, const T2 &b) : first(a), second(b) { }

            
            bool operator==(const pair<T1,T2> &other ) const {         
                return (first == other.first && second == other.second);    
            }

            bool operator<(const pair<T1,T2> &other) const {        //! compare second before first
                return (second < other.second) ||
                        (second == other.second && first < other.first);
            }
            
            bool operator!=(const pair<T1,T2> &other) const {       // new
                return !(*this == other);
            }

            bool operator >=(const pair<T1,T2> &other) const {      // new
                return !(*this < other);
            }
    };

}


int main() {

    CP::pair<int, int> a(1,2);
    CP::pair<int, int> b(0,2);

    cout << (a < b) << '\n';
    cout << (a != b) << '\n';
    cout << (a >= b) << '\n';

}