#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    long long n; cin >> n;
    long long k; cin >> k;

    for (long long r=0; r<=n-r; ++r){
        if (2*r*(n-r) >= k){

            vector<int> ans(n);
            for (int i=0; i<n; ++i){
                ans[i] = (i-r+n)%n + 1;
            }
            int p = (n-1+r) % n;
            long long c = 2*r*(n-r);
            while (p+1 < n && c > k){
                swap(ans[p], ans[p+1]);
                ++p;
                c -= 2;
            }

            if (c == k){
                cout << "Yes\n";
                for (int i=0; i<n; ++i){
                    cout << ans[i] << ' ';
                }
                cout << '\n';
                return;
            } else {
                break;
            }

        }
    }

    cout << "No\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}