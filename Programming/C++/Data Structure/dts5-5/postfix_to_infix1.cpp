#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

int main() {
    
    stack<string> s;
    string postfix;

    getline(cin, postfix);          //* cin stop when see a space
                                    //* but not with getline
    stringstream ss(postfix);       //! Use stringstream to tokenizer
    string token;

    while (ss >> token) {
        
        if (token == "+" || token == "-" ||
        token == "*" || token == "/") {

            string op2 = s.top();
            s.pop();

            string op1 = s.top();
            s.pop();

            string output  = "(" + op1 + token + op2 + ")";
            s.push(output);

        }
        else {
            s.push(token);
        }

    }

    cout << s.top() << endl;
    return 0;

}