#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {

    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int minprice = prices[0];
    int maxprofit = 0;

    for (int i = 1; i < prices.size(); i++) {

        if (prices[i] < minprice) {
            minprice = prices[i];
        }
        maxprofit = max(maxprofit, prices[i] - minprice);

    }

    cout << maxprofit;

}