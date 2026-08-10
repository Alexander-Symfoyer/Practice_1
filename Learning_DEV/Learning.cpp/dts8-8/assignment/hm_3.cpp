#include <iostream>
#include <vector>
#include <algorithm>


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

            bool operator<(const pair<T1,T2> &other) const {        //! new sort from max to min
                return (first > other.first) ||
                        (first == other.first && second > other.second);
            }
            
            bool operator!=(const pair<T1,T2> &other) const {      
                return !(*this == other);
            }

            bool operator >=(const pair<T1,T2> &other) const {      
                return !(*this < other);
            }
    };

}


void print(const vector<CP::pair<int,int>> &v) {
    
    for(const auto x : v) {
        
        cout << "{" << x.first << "," << x.second << "}" << " ";

    }

    cout << '\n';

}


int main() {

    CP::pair<int, int> a(1,2);
    CP::pair<int, int> b(0,2);

    cout << (a < b) << '\n';

    vector<CP::pair<int,int>> v;

    v.push_back({6,7});
    v.push_back({4,8});
    v.push_back({3,9});
    v.push_back({4,6});

    sort(v.begin(), v.end());

    print(v);

}