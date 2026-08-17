#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    int x;
    
    for (int i = 0; i < 3; i++) {
        cin >> x;
        s.push(x);
    }
    cout << s.size() << endl;

    cout << "Top of s is " << s.top() << endl;
    s.pop();
    cout << "Now top is " << s.top() << endl;
    
    cout << s.empty() << endl;


}