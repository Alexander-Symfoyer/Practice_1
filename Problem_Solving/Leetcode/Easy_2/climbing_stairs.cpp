#include <iostream>
using namespace std;
int main() {                    //* ways(n) = ways(n-1) + ways(n-2)
                                //* Fibonacci
    int n;
    cin >> n;

    if (n == 1) cout << 1;      //* Base case
    if (n == 2) cout << 2;

    int prev1 = 2;      //* ways(2)
    int prev2 = 1;      //* ways(1)

    for (int i = 3; i <= n; i++) {

        int current = prev1 + prev2;    //* previous two ways combined
        prev2 = prev1;                  //* Move the values forward
        prev1 = current;

    }

    cout << prev1;      //* Contains ways(n)

}