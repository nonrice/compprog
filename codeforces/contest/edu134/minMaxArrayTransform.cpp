#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int& v : a) cin >> v;
    for (int& v : b) cin >> v;

    for (int v : a) cout << *lower_bound(b.begin(), b.end(), v)-v << ' ';
    cout << '\n';

    vector<int> p(n);
    for (int i=1; i<n; ++i) p[i] = p[i-1] + !(a[i]<=b[i-1]);
    //for (int v : p) cout << v << ' ';
    
    for (int i=0; i<n; ++i){
        cout << b[(--upper_bound(p.begin()+i, p.end(), p[i])) - p.begin()] - a[i] << ' ';
    }
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
