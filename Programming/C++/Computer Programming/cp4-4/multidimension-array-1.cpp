#include <iostream>
using namespace std;

void print(int c[], int n) {
    for (int i = 0; i < n; i++)
        cout << c[i] << " ";
    cout << endl;
}

void print2d(int a[][3], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {
    int d[6];
    int a[3] = {1,2,3};
    int b[5] = {1,2};
    int c[] = {11,22,33,44};
    
    print(d,6);
    print(a,3);
    print(b,5);
    print(c,4);

    int x[5][3];
    int y[2][3];
    int z[5][7];

    print2d(x,5,3);
    print2d(y,2,3);
   
}