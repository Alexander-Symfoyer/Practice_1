#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    
    auto compare = [](const string& lhs, const string& rhs) {       //! No class needed
        return lhs.size() < rhs.size();
    };

    cout << "Result of compare funcion = " << compare("xxx", "z") << endl;

    priority_queue< string,
                    vector<string>,
                    decltype(compare) >     //? ask for type
                    pq(compare);
    pq.push("somchai");
    pq.push("saran");
    pq.push("yu");
    
    while(!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }

}