#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    uint64_t n; cin >> n;

    uint64_t x = n;
    vector<uint64_t> t;
    for (uint64_t p = 1ULL<<63; p; p>>=1){
        if (p <= x){
            t.push_back(p);
            x -= p;
        }
    }

    if (t.size() == 1){
        cout << "1\n" << t[0] << '\n';
        return;
    }

    cout << t.size()+1 << '\n';
    for (int i=0; i<t.size(); ++i){
        cout << n-t[i] << ' ';
    }
    cout << n << '\n';




}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}