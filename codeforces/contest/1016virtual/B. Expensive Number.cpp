#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    string s; cin >> s;
    const int n = s.size();
    reverse(s.begin(), s.end());

    int ans = n-1;
    int t = 0;
    for (int i=0; i<n; ++i){
        if (t >= 1 && s[i] == '0'){
            --ans;
        }
        if (s[i] != '0'){
            ++t;
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
