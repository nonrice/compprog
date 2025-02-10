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
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    // long long ans = n + (n/2)*(n/2-1)/2 + ((n+1)/2)*((n+1)/2-1)/2;
    long long ans = 0;
    debug(ans);

    for (int k=1; k<=10; ++k){
        vector<int> p1(n), p2(n);
        for (int i=0; i<n; ++i){
            int t=0, c=0;
            if (a[i] < k){
                for (int j=i; j>=0; --j){
                    p2[j] += 1;
                }
            } else {
                for (int j=i; j>=0; --j){
                    p2[j] -= 1;
                }
            }

            if (a[i] > k){
                for (int j=i; j>=0; --j){
                    p1[j] += 1;
                }
            } else {
                for (int j=i; j>=0; --j){
                    p1[j] -= 1;
                }
            }

            for (int j=i; j>=0; --j){
                if (p2[j] < 0 && p1[j] < 0){
                    ++ans;
                }
            }
        }
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