#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, x;
    long long k;
    cin >> n >> x >> k;
    string s; cin >> s;

    int p = x;
    for (int i=0; i<n; ++i){
        if (s[i] == 'L'){
            --p;
        } else {
            ++p;
        }
        --k;
        if (p == 0){
            for (int j=0; j<n; ++j){
                if (s[j] == 'L'){
                    --p;
                } else {
                    ++p;
                }
                if (p == 0){
                    cout << 1+k/(j+1) << '\n';
                    return;
                }
            }
            cout << "1\n";
            return;
        }
    }
    cout << "0\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
