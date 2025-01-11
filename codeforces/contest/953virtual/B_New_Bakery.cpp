#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    long long n, a, b; cin >> n >> a >> b;  
    
    long long k = min(n, max(0LL, b-a+1));

    cout << (b + b-k+1)*k/2 + a*(n-k) << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}