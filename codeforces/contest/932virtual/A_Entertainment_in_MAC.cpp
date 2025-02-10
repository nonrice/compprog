#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int k; cin >> k;
    string s; cin >> s;

    string t(s.rbegin(), s.rend());

    bool f = s<=t;

    stringstream ans;
    if (f){
        if (k%2){
            ans << s << t;
        } else {
            ans << s;
        }
    } else {
        if (k%2){
            ans << t;
        } else {
            ans << t << s;
        }
    }

    cout << ans.str() << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}