#include <bits/stdc++.h>
using namespace std;

// calculates series 0 0 2 4 4 6 8 8 10 ...
inline int sum(int n){
    int k = n/3;
    //cout << k*k*2 << '\n';
    //cout << ((n-k)/2 + 1)*4*k << '\n';
    //cout << (2-n%3)*4*k << '\n';
    return k*k*2 + (1 + n/3)*4*k - (2-n%3)*4*k;
    // ^ simplifies to k*k*2 + 4*k*(n%3 - 1)
}

void solve(){
    int x; cin >> x;
    int cur = 38731;
    for (int s=38729; s>=1; s/=2){
        while (cur-s>0 && sum(cur-s) >= x) cur -= s;
    }
    cout << cur-1 << '\n';
}

int main(){
    //cout << sum(11) << '\n';
    //cout << sum(10) << '\n';
    //cout << sum(38731) << '\n';
    //return 0;
    int cases; cin >> cases;
    while (cases--) solve();
}

