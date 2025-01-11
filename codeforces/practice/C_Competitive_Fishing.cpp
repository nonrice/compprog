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
    string a; cin >> a;

    vector<int> s(n+1);
    for (int i=n-1; i>=1; --i){
        if (a[i] == '0'){
            s[i] = s[i+1]-1;
        } else {
            s[i] = s[i+1]+1;
        }
    }

    sort(s.rbegin(), s.rend());
    int p = 0; 
    for (int ans = 0; ans < n; ++ans){
        p += s[ans];
        if (p >= k){
            cout << ans+2 << '\n';
            return;
        }
    }
    cout << "-1\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}