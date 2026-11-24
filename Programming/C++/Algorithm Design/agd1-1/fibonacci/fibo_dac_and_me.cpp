#include <iostream>
#include <vector>

using namespace std;

// นิยามชนิดข้อมูล Matrix เพื่อความสะดวกในการใช้งาน
typedef vector<vector<long long>> Matrix;

// ฟังก์ชันสำหรับคูณเมทริกซ์ขนาด 2x2
Matrix multiply(const Matrix& A, const Matrix& B) {
    Matrix C(2, vector<long long>(2, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// ฟังก์ชันยกกำลังเมทริกซ์ด้วยวิธี Divide and Conquer O(log n)
Matrix matrix_expo(const Matrix& A, int exp) {
    if (exp == 1) return A;
    
    Matrix half = matrix_expo(A, exp / 2);
    Matrix result = multiply(half, half);
    
    if (exp % 2 != 0) {
        result = multiply(result, A);
    }
    return result;
}

// ฟังก์ชันหลักในการหาเลขฟีโบนัชชีตัวที่ n
long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // เมทริกซ์ฐานสำหรับการคำนวณฟีโบนัชชี
    Matrix base = {{1, 1}, {1, 0}};
    
    // ยกกำลังเมทริกซ์ฐานไปที่ n-1
    Matrix result = matrix_expo(base, n - 1);
    
    // ค่า Fn จะอยู่ที่ตำแหน่ง [0][0] ของเมทริกซ์ผลลัพธ์
    return result[0][0];
}

int main() {
    int n;
    cout << "--- Fibonacci Calculation using Matrix Exponentiation ---" << endl;
    cout << "Enter n: ";
    if (!(cin >> n) || n < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return 1;
    }

    long long result = fibonacci(n);
    cout << "Fibonacci number at position " << n << " is: " << result << endl;

    return 0;
}
