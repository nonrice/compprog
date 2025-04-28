#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

int msb(int n){
    return 1<<(31 - __builtin_clz(n));
}

int k;

vector<int> ans(int n){
    if (msb(n) == n){
        return vector<int>(msb(n), k);
    }
    vector<int> s(msb(n)<<1);
    
    vector<int> r = ans(n - msb(n));
    debug(r, n, s.size());
    copy(r.begin(), r.end(), s.begin());
    copy(r.begin(), r.end(), s.begin()+msb(n));
    return s;
}

void solve(){
    int n; cin >> n >> k;

    auto s = ans(n);

    for (int i=0; i<n; ++i){
        cout << s[i] << ' ';
    }
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
