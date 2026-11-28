
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Point {
    ll x, y;
};

ll dist2(const Point& a, const Point& b) {
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy;
}

bool cmpX(const Point& a, const Point& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool cmpY(const Point& a, const Point& b) {
    return a.y < b.y;
}

vector<Point> p, temp;

ll closestPair(int l, int r) {
    // Base case: brute force for at most 3 points
    if (r - l <= 2) {
        ll best = LLONG_MAX;

        for (int i = l; i <= r; i++) {
            for (int j = i + 1; j <= r; j++) {
                best = min(best, dist2(p[i], p[j]));
            }
        }

        sort(p.begin() + l, p.begin() + r + 1, cmpY);
        return best;
    }

    int mid = (l + r) / 2;
    ll midX = p[mid].x;

    // Divide
    ll leftBest = closestPair(l, mid);
    ll rightBest = closestPair(mid + 1, r);

    // Best distance from left and right
    ll best = min(leftBest, rightBest);

    if (best == 0) return 0;

    // Merge both halves by y-coordinate
    merge(
        p.begin() + l, p.begin() + mid + 1,
        p.begin() + mid + 1, p.begin() + r + 1,
        temp.begin() + l, cmpY
    );

    copy(temp.begin() + l, temp.begin() + r + 1,
        p.begin() + l);

    // Build strip
    vector<Point> strip;

    for (int i = l; i <= r; i++) {
        ll dx = p[i].x - midX;

        if (dx * dx < best) {
            strip.push_back(p[i]);
        }
    }

    // Check nearby points in y-sorted strip
    for (int i = 0; i < (int)strip.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            ll dy = strip[i].y - strip[j].y;

            if (dy * dy >= best) break;

            best = min(best, dist2(strip[i], strip[j]));
        }
    }

    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    p.resize(n);
    temp.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    sort(p.begin(), p.end(), cmpX);

    ll ans2 = closestPair(0, n - 1);

    cout << fixed << setprecision(6)
        << sqrtl((long double)ans2) << '\n';
}
