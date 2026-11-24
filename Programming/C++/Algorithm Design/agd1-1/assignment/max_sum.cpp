#include <iostream>
#include <queue>


using namespace std;


void max_sum(vector<int> &v) {

    priority_queue<int> pq;
    
    for(int &x : v) {
        pq.push(x);
    }

    int pos1 = pq.top();
    pq.pop();
    int pos2 = pq.top();

    cout << "Maximum value in array is : " << pos1 << " + " << pos2 << " = " << pos1 + pos2 << '\n';

}



int main() {

    vector<int> v;
    int n;
    cout << "Enter number of member in array : ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        int x;
        cout << "Enter number " << i << " : ";
        cin >> x;
        v.push_back(x);

    }

    max_sum(v);

}