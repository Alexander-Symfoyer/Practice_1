#include <iostream>

using namespace std;

int main() {
    int x = 5;
    int y = 0;
    
    y = ++x;     // postfix increment
    cout << y << " " << x << endl;

    x = 5;
    y = 0;
    y = x++;     // prefix increment
    cout << y << " " << x << endl;
    
    x = 5;
    y = 0;
    y = --x;     // postix decrement
    cout << y << " " << x << endl;
    
    x = 5;
    y = 0;
    y = x--;     // prefix decrement
    cout << y << " " << x << endl;
    
}

// postfix, function-call : priority = 1 
// prefix : priority = 2 