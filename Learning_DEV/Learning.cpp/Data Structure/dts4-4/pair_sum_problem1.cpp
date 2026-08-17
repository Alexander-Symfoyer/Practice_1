#include <iostream>
#include <vector>
using namespace std; 

int main() {        // brute force method
    
    vector<int> arr = {2,3,9,7,5,6,1};
    int X = 10;

    bool found = false;

    for (int i = 0; i < arr.size(); i++) {
        
        for (int j = i + 1; j < arr.size(); j++) {
            
            if (arr[i] + arr[j] == X) {
                found = true;
                break;
            }

        }
        if (found)
        break;
    }

    if (found) {
        cout << "YES" << endl;  
    }   
    else {
        cout << "NO" << endl;
    }

    return 0;
}