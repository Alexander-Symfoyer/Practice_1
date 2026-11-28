#include <iostream>
#include <vector>
using namespace std;
int main() {

    vector<int> nums = {4,1,2,1,2};     //* ^ = Bitwise XOR
    int ans = 0;                        //? 4 ^ 4 = 0
    for (int x : nums) {                //? 4 ^ 0 = 4
        ans ^= x;
    }
    cout << ans;
}