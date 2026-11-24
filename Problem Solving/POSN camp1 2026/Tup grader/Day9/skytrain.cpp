#include <bits/stdc++.h>
using namespace std;
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    set<int> st = {0,n};
    multiset<int> gaps = {n};
    
    for (int i = 0; i < k; i++) {
        int p;
        cin >> p;
        
        auto it = st.lower_bound(p);
        
        int r = *it;
        int l = *prev(it);
        
        gaps.erase(gaps.find(r - l));
        gaps.insert(p - l);
        gaps.insert(r - p);
        st.insert(p);
        
        cout << *gaps.rbegin() << " ";
    }
    
    cout << '\n';
    return 0;
    
}