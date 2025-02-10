#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){

    vector<int> a(4);
    for (int i=0; i<4; ++i){
        cin >> a[i];
    }


    int ans = 0;
    for (int k=-300; k<300; ++k){
        ans = max(ans, (a[0]+a[1]==k) + (a[1]+k==a[2]) + (k+a[2]==a[3]));
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