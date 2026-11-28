
#include <bits/stdc++.h>
using namespace std;

using Matrix = vector<vector<long long>>;

// Matrix Addition
Matrix add(Matrix A, Matrix B) {
    int n = A.size();
    Matrix C(n, vector<long long>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

// Matrix Subtraction
Matrix sub(Matrix A, Matrix B) {
    int n = A.size();
    Matrix C(n, vector<long long>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    return C;
}

// Strassen Multiplication
Matrix multiply(Matrix A, Matrix B) {
    int n = A.size();

    // Base Case
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int k = n / 2;

    // Divide A into 4 parts
    Matrix A11(k, vector<long long>(k));
    Matrix A12(k, vector<long long>(k));
    Matrix A21(k, vector<long long>(k));
    Matrix A22(k, vector<long long>(k));

    // Divide B into 4 parts
    Matrix B11(k, vector<long long>(k));
    Matrix B12(k, vector<long long>(k));
    Matrix B21(k, vector<long long>(k));
    Matrix B22(k, vector<long long>(k));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // Calculate 7 products
    Matrix M1 = multiply(
        add(A11, A22),
        add(B11, B22)
    );

    Matrix M2 = multiply(
        add(A21, A22),
        B11
    );

    Matrix M3 = multiply(
        A11,
        sub(B12, B22)
    );

    Matrix M4 = multiply(
        A22,
        sub(B21, B11)
    );

    Matrix M5 = multiply(
        add(A11, A12),
        B22
    );

    Matrix M6 = multiply(
        sub(A21, A11),
        add(B11, B12)
    );

    Matrix M7 = multiply(
        sub(A12, A22),
        add(B21, B22)
    );

    // Calculate C quadrants
    Matrix C11 = add(sub(add(M1, M4), M5), M7);
    Matrix C12 = add(M3, M5);
    Matrix C21 = add(M2, M4);
    Matrix C22 = add(add(sub(M1, M2), M3), M6);

    // Combine 4 quadrants
    Matrix C(n, vector<long long>(n));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }

    return C;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Matrix A(n, vector<long long>(n));
    Matrix B(n, vector<long long>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    Matrix C = multiply(A, B);

    for (auto& row : C) {
        for (auto x : row)
            cout << x << " ";
        cout << '\n';
    }
}
