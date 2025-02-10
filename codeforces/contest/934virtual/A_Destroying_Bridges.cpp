#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

int s[101];

void solve(){
    int n, k; cin >> n >> k;

    if (k >= n-1){
        cout << "1\n";
    } else {
        cout << n << '\n';
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    for (int i=1; i<=100; ++i){
        s[i] = s[i-1] + i;
    }

    int t; cin >> t;
    while (t--){
        solve();
    }
}