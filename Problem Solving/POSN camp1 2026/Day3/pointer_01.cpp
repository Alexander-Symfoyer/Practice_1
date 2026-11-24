#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a = 67;
    int *p,*q,*r;

    p = &a;
    q = &a;
    r = &a;

    cout << "value of a : " << a << '\n';
    cout << "Address of a : " << &a << '\n';

    cout << "ad P : " << p << '\n';
    cout << "Value P : " << *p;

}