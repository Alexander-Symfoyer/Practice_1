#include <iostream>
#include <vector>


using namespace std;            //! Visited + Recursion + Backtracking


bool find_path(

    const vector<vector<char>> &graph,
    char current,                           //* Current node
    char target,                            //* Target(goal) node
    vector<bool> &visited,                  //* Visited node
    vector<char> &path                      //* current path

) {

    if (current == target) {                //* Target reached --> path founded!
        path.push_back(target);
        return true;
    }

    int index = current - 'A';              //* Convert A B C to 0 1 2 (convert char to index(int))
                                            //? A - A = 0, B - A = 1

    visited[index] = true;                  //* Mark current node as visited
    path.push_back(current);                //* Add current node to the path

    for (char next : graph[index]) {        //* Try every neighbor

        if (visited[next - 'A']) continue;      //* Skip visited node

        if (find_path(graph, next, target, visited, path)) return true;     //* Try going to this neighbor
                                                                            //* Recursion

    }

    path.pop_back();            //* Dead end --> Backtrack
    return false;

}


int main() {

    vector<vector<char>> graph = {
        {'B', 'C'}, 
        {'A', 'C', 'D'},
        {'A', 'B'},
        {'B', 'E'},
        {'D'}
    };

    char p = 'A';       //* Start node
    char q = 'E';       //* Target node

    vector<bool> visited(5, false);         //* Track visited nodes (vector(size, value)) 
    vector<char> path;                      //* Stores the path

    if (find_path(graph, p, q, visited, path)) {        //* Find a path from p to q

        cout << "Path : ";

        for (char node : path) {            //* Print the path
            cout << node << " ";
        }
        cout << '\n';

    } else {
        cout << "No path\n";
    }


}