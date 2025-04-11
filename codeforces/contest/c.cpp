#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long x, y; cin >> x >> y;

    if (x == y){
        cout << "-1\n";
        return;
    }

    if (y>x){
        swap(x, y);
    }
    long long p = 1;
    while (p < x){
        p <<= 1;
    }

    long long k = p-x;


    cout << k << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
