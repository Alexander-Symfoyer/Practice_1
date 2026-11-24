#include <iostream>
using namespace std;

int test3d(int a[][5][10], int n1, int n2, int n3) {
    int sum = 0;
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            for (int k = 0; k < n3; k++)
                sum += a[i][j][k];

    cout << "size a[][] " << sizeof(a[1][1]) << endl;  //1D
    cout << "size a[] " << sizeof(a[1]) << endl;       //2D
    return sum;
}

int main() {
    int p[4][5][10];
    int q[100][5][10];
    int r[4][99][10];
    int s[4][5][99];

    cout << test3d(p, 4, 5, 10) << endl;
    cout << test3d(q, 100, 5, 10) << endl;
    //cout << test3d(r, 4, 99, 10);
    //cout << test3d(s, 4, 5, 99);
    return 0;
}