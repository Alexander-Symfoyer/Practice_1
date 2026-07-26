#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;


// Breadth-first search
// also called exhuastive search
// systematically enumerate all possible somethings
// generate all possible sequences

// ===========================================================
// Idea:
// Explore all possible states level by level.
//
// Start state : 1
// Operations  : *3 or /2
//
// Data Structures
// - queue : states waiting to be explored
// - map(prev) : remember each state's parent
//
// Goal:
// Find the shortest sequence of operations from 1 to target.
// ===========================================================

void showsolution(int v, map<int, int> prev);
void m3d2(int target);

int main() {

    int input;
    cin >> input;

    m3d2(input);
    
    return 0;

}


void m3d2(int target) {
    
    map<int, int> prev;     //? Parent table
    queue<int> q;           //? BFS frontier
    int v = 1;              //? Current state

    q.push(1);              //* Initial state
    prev[1] = -1;           //* Root (1 has no parents)

    while (!q.empty()) {

        v = q.front();      // front state
        q.pop();

        if (v == target) break;     // check goal

        int v2 = v / 2;             // generate next state
        int v3 = v * 3;

        if (prev.find(v2) == prev.end()) {    //* check for duplicates
            q.push(v2); 
            prev[v2] = v;                       // Child -> Parent
                                                // Used later to reconstruct the solution.                      
        }
        
        if (prev.find(v3) == prev.end()) {      // push unseen state into queue
            q.push(v3); 
            prev[v3] = v;
        }

    }

    if (v == target) showsolution(v, prev);

}


void showsolution(int v, map<int, int> prev) {

    string output = "";

    while (prev[v] != -1) {         //! Trace back

        if (prev[v] * 3 == v) {
            output = "x3 " + output;
        }
        
        else {
            output = "/2 " + output;
        }

        v = prev[v];            //* Move one step toward the root

    }

    output = "1 " + output;

    cout << output << endl;

}