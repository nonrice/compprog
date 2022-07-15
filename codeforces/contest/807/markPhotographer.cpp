#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, x; cin >> n >> x;
    vector<int> a(2*n);
    for (int& v : a) cin >> v;

    sort(a.begin(), a.end());
    for (int i=0; i<n; ++i){
        if (a[i+n]-a[i] < x){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
