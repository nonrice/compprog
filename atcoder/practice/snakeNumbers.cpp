#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

long long intpow(int a, int b){
    long long ans = 1;
    while (b--){
        ans *= a;
    }
    return ans;
}

long long cnt(long long x){
    vector<int> d;
    while (x){
        d.push_back(x%10);
        x /= 10;
    }
    const int n = d.size();

    long long ans = 1;
    debug(ans);
    for (int i=0; i<n-1; ++i){
        for (int l=1; l<=9; ++l){
            ans += intpow(l, i);
        }
    }

    debug(ans);

    for (int l=1; l<d[n-1]; ++l){
        ans += intpow(l, n-1);
    }

    debug(ans);
    long long c = 1;
    bool f = true;
    for (int i=n-2; i>=0; --i){

        ans += min(d[i], d[n-1]) * intpow(d[n-1], i);
        if (d[i] >= d[n-1]){
            f = false;
            break;
        }
    }   
    ans += f;

    debug(ans);
    return ans;
}

void solve(){
    long long l, r; cin >> l >> r;
    
    cout << cnt(r) - cnt(l-1) << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    solve();
}