#include <iostream>
#include <queue>

using namespace std;


namespace CP {

    template<typename T1, typename T2>
    class pair {
        public:
            T1 first;
            T2 second;

            //* Custom constructor, using intializer list
            pair(const T1 &a, const T2 &b) : first(a), second(b) { }

            
            bool operator==(const pair<T1,T2> &other ) const {         
                return (first == other.first && second == other.second);    
            }

            bool operator<(const pair<T1,T2> &other) const {
                return (first < other.first) ||
                        (first == other.first && second < other.second);
            }
    };
}


int main() {

    CP::pair<int, bool> p(90, false);
    CP::pair<string, int> q("cony",42), r("james",0);

    cout << (q < r) << '\n';

    priority_queue<CP::pair<string, int>> pq;
    pq.push(r);
    pq.push(q);
    cout << pq.top().second << '\n';

    CP::pair<string, int> x(q);
    cout << x.first << '\n';

    CP::pair<string, int> y = x;
    cout << y.first << '\n';

}