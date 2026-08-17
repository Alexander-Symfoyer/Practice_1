#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    
    stack<char> s;
    string text;
    cin >> text;

    for (char c : text) {
        
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        } 
        else {
            
            if (s.empty()) {
                cout << "Incorrect" << endl;
                return 0;
            }
            
            else {
                if (c == ')' && s.top() != '(' ) {
                    cout << "Incorrect" << endl;
                    return 0;    
                }
                
                if (c == ']' && s.top() != '[') {
                    cout << "Incorrect" << endl;
                    return 0;   
                }

                if (c == '}' && s.top() != '{') {
                    cout << "Incorrect" << endl;
                    return 0;
                }

                s.pop();

                }
            }
        }
    
    if (s.empty()) {
        cout << "Correct" << endl;
    }
    else {
        cout << "Incorrect" << endl;
    }
    
}

