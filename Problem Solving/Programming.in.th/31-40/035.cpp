#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {

    int n; cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    long long max_area2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {

                int x1 = p[i].first;
                int y1 = p[i].second;
                int x2 = p[j].first;
                int y2 = p[j].second;
                int x3 = p[k].first;
                int y3 = p[k].second;

                long long area2 = abs(x1*y2 + x2*y3 + x3*y1 - y1*x2 - y2*x3 - y3*x1);
                if (area2 > max_area2) {
                    max_area2 = area2;
                }

            }
        }
    }

    cout << fixed << setprecision(3)
    << max_area2 / 2.0 << '\n';

}