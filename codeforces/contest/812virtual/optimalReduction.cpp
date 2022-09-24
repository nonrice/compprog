#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int& v : a) cin >> v;

    int mxi = max_element(a.begin(), a.end()) - a.begin();

    for (int i=mxi-1; i>=0; --i){
        if (a[i] > a[i+1]){
            cout << "NO\n";
            return;
        }
    }

    for (int i=mxi+1; i<n; ++i){
        if (a[i] > a[i-1]){
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
