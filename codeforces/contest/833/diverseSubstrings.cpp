#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    
    int ans = 0;
    for (int t=1; t<=min(100, n); ++t){
        int c[10] = {};
        int u = 0;

        for (int i=0; i<t; ++i) if (c[s[i]-'0']++ == 0) ++u;
        if (*max_element(c, c+10) <= u) ++ans;

        for (int i=0; i<n-t; ++i){
            if (--c[s[i]-'0'] == 0) --u;
            if (c[s[i+t]-'0']++ == 0) ++u;
            if (*max_element(c, c+10) <= u) ++ans;
        }
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
