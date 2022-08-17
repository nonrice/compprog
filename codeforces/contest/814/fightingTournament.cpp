#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    vector<int> pos(n+1);
    for (int i=0; i<n; ++i){
        cin >> a[i];
        pos[a[i]] = i;
    }
    
    vector<int> next(n);
    stack<int> s; s.push(0);
    for (int i=1; i<n; ++i){
        while (!s.empty() && a[s.top()] < a[i]){
            next[s.top()] = pos[a[i]];
            s.pop();
        }
        s.push(i);
    }
    
    for (int v : next) cout << v << ' ';
    cout << '\n';

    while (q--){
        int i, k; cin >> i >> k;
        cout << min(next[i-1]-(i-1), k) << '\n';
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
