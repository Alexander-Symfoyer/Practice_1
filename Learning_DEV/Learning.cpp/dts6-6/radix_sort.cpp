#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>


//? Radix sort
// 115 15 42 305 21 8 463
// step 1 digit(0) to queue
// 21 42 463 115 12 305 8 
// step 2 digit(1) to queue
// 8 305 12 115 21 42 463
// step 3 digit(2) to queue
// 8 12 21 42 115 305 463


using namespace std;
#define base 10


int getdigit(int v, int k);
void radixsort(vector<int> &data, int d);
void print(vector<int> data);


int main() {        // Fast sorting with no application

    string line;
    getline(cin, line);
    stringstream ss(line);

    vector<int> data;
    int x;

    while (ss >> x) {
        data.push_back(x);
    }

    int mx = *max_element(data.begin(), data.end());

    radixsort(data, mx);

    print(data);

}


int getdigit(int v, int k) {

    int i;
    for (i = 0; i < k; i++) {
        v /= base;
    }    
    return v % 10;

}


void radixsort(vector<int> &data, int d) {

    queue<int> q[base];

    for (int k = 0; k < d; k++) {

        for (auto &x : data) {

            q[getdigit(x,k)].push(x);

        }

        for (int i = 0, j = 0; i < base; i++) {
            
            while (!q[i].empty()) {
                
                data[j++] = q[i].front();
                q[i].pop();

            }

        }

    }


}


void print(vector<int> data) {
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}