#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    for (int i=n-1; i>=0; --i){
        if (s[i] == '1'){
            if (i+1==n ){
                ++ans;
            } else if (s[i+1] == '0'){
                ans += 2;
            }
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