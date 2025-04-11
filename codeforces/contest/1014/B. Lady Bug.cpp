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
    string t; cin >> t;

    int z1=0, z2=0;
    for (int i=0; i<n; ++i){
        if (i%2){
            z1 += (s[i]=='0');
        } else {
            z1 += (t[i]=='0');
        }
    }
    for (int i=0; i<n; ++i){
        if (i%2==0){
            z2 += (s[i]=='0');
        } else {
            z2 += (t[i]=='0');
        }
    }

    if (z2>=(n+1)/2 && z1>=n/2){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
