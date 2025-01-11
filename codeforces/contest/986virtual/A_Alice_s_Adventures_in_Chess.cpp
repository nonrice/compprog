#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;

    int r=0, c=0;
    int p = 0;
    for (int i=0; i<=max(a, b)*n*10; ++i){
        if (r==b && c==a){
            cout << "YES\n";
            return;
        }
        char ch = s[p];
        if (ch == 'N'){
            ++r;
        } else if (ch == 'E'){
            ++c;
        } else if (ch == 'S'){
            --r;
        } else {
            --c;
        }

        p = (p+1)%n;

    }
    cout << "NO\n";
    return;
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}