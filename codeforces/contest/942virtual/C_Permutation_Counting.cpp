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
    long long k; cin >> k;
    vector<long long> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    auto chk = [&](long long h){
        long long r = k;
        for (int i=0; i<n; ++i){
            r -= max(0LL, h-a[i]);
        }
        return r;
    }; 

    long long h = 0;
    for (long long s=1e13; s>=1; s/=2){
        while (chk(h+s) >= 0){
            h += s;
        }
    }


    long long e = chk(h);
    for (int i=0; i<n; ++i){
        if (a[i] > h){
            ++e;
        }
    }
    
    cout << h*n - n +  1 + e << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}