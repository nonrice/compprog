#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, k; cin >> n >> k;

    vector<int> ans;

    int s = 0;
    for (int p=1; s+p<=k-1; p<<=1){
        ans.push_back(p);
        s += p;
    }
    ans.push_back(k-1-s);
    ans.push_back(k+1);

    s += k+1;
    
    debug(s); // s = 2k
    for (int p=2*k; s+p<=n; p<<=1){
        ans.push_back(p);
        s += p;
    }
    ans.push_back(2*k+1);
    ans.push_back(2*k+1);

    cout << ans.size() << '\n';
    for (auto x : ans){
        cout << x << ' ';
    }
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}