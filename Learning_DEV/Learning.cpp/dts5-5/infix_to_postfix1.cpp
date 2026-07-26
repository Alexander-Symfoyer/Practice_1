#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <map>
using namespace std;


string infix2postfix(string &infix) {
    
    stack<char> s;

    string postfix = "";

    stringstream ss(infix);         //! String is incomparable so we use char in map
    char token;

    map<char, int> outpriority = {                  //* '(' has the highest priority so it is always pushed.
                                                    //* ')' has the lowest priority so operators are popped until '('.

        {'^', 8}, {'*', 5}, {'/', 5}, {'+', 3}, {'-', 3}, {'(', 9 }, {')', 1}       //* '^' has higher out-priority than in-priority,
    };                                                                              //* so consecutive '^' are always pushed
                                                                                    //! because '^' evaluated from right to left

    map<char, int> inpriority = {                   //* '(' has the lowest priority inside the stack,
                                                    //* so operators after '(' are pushed without popping '('.
        
        {'^', 7}, {'*', 5}, {'/', 5}, {'+', 3}, {'-', 3}, {'(', 0}      
    };

    while (ss >> token) {

        if (outpriority.find(token) == outpriority.end()) {
            postfix += token;
            postfix += ' ';
        }
        else {

            int pout = outpriority[token];
            
            while (!s.empty() && inpriority[s.top()] >= pout) {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            if (token == ')') {         //! Always pop "(" and ")"
                if (s.top() == '(')
                    s.pop();
            } else {
                s.push(token);
            }

        }

    }
    while (!s.empty()) {    //! Last check
        postfix += s.top();
        postfix += ' ';
        s.pop();
    }

    postfix.pop_back();     // pop space
    
    return postfix;

}


int main() {

    string infix;
    getline(cin, infix);

    string answer = infix2postfix(infix);
    cout << answer << endl;
    
}
