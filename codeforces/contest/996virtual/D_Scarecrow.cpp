#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, k, l; cin >> n >> k >> l;
    l *= 2;
    k *= 2;
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
        a[i] *= 2;
    }
    sort(a.begin(), a.end());

    int p = k;
    int t = a[0];
    for (int i=1; i<n; ++i){
        if (a[i]-t > p){
            int dt = (a[i]-t-p)/2;
            t += dt;
            p += k + dt;
        } else if (a[i]+t < p){
            p = max(p, a[i]+t+k);
        } else {
            p += k;
        }
        if (p >= l){
            break;
        }
    }

    cout << t + max(0, l-p) << '\n';

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}