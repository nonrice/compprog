#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

set<int> sq;

void solve(){
    int n; cin >> n;
    vector<int> a(n);

    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    int s = 0;
    int ans = 0;
    for (int i=0; i<n; ++i){
        s += a[i];
        if (sq.count(s)){
            ++ans;
        }
    }

    cout << ans << '\n';

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    for (int i=1; i<=100; i+=2){
        sq.insert(i*i);
    }

    int t; cin >> t;
    while (t--){
        solve();
    }
}