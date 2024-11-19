#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int& v : a) cin >> v;

    vector<int> b(n+1);
    b[0] = a[0];
    b.back() = a.back();
    for (int i=1; i<n; ++i){
        b[i] = lcm(a[i-1], a[i]);
    }

    for (int i=0; i<n; ++i){
        if (a[i] != gcd(b[i], b[i+1])){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
