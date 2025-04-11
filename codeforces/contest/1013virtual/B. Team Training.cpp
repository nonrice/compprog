#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    
    int ans = 0;
    sort(a.begin(), a.end(), greater<int>());
    int l = 0;
    for (int i=0; i<n; ++i){
        if (1LL*(i-l+1)*a[i] >= x){
            l = i+1;
            ++ans;
        }
    }
    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
