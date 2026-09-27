#include <iostream>
#include <cstdint>
using namespace std;
int main() {

    uint32_t n = 43261596;
    uint32_t ans = 0;           //* Stores the reverse bits

    for (int i = 0; i < 32; i++) {      //* A 32-bit integers
        
        uint32_t bit = n & 1;           //* Get the rightmost bit of n
        ans = (ans << 1) | bit;         //* Shift ans left and add the extracted bit
        n >>= 1;                        //* Shift n right to get the next bit

    }

    cout << ans;

}