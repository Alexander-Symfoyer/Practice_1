#include <bits/stdc++.h>
using namespace std;
int main() {

   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   
   int w,h;
   cin >> w >> h;
   long long area = w * h;
   long long perimeter = (2*w) + (2*h);
   cout << area << " " << perimeter;
   return 0;

}