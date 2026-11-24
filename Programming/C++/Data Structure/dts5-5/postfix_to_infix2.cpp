#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int main() {
    
    stack<int> s;
    
    string postfix;
    getline(cin, postfix);

    stringstream ss(postfix);
    string token;

    while (ss >> token) {

        if (token == "+" || token == "-" ||
        token == "*" || token == "/") {

            int y = s.top();
            s.pop();

            int x = s.top();
            s.pop();

            if (token == "+") 
                s.push(x + y);

            else if (token == "-")
                s.push(x - y);
            
            else if (token == "*")
                s.push(x * y);

            else
                s.push(x / y);

        }
        else {
            s.push(stoi(token));
        }
    }

    cout << "Answer is : " << s.top() << endl;

}