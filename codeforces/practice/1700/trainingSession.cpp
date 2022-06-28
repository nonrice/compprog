#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n+1), b(n+1);
    vector<pair<int, int>> ps(n);
    for (int i=0; i<n; ++i){
        int x, y; cin >> x >> y;
        ++a[x];
        ++b[y];
        ps[i] = {x, y};
    }
    
    unsigned long long ans = 1LL*n*(n-1)*(n-2)/6;
    for (auto& [x, y] : ps){
        ans -= 1LL*(a[x]-1)*(b[y]-1); 
    }

    cout << ans << '\n';
}


int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
