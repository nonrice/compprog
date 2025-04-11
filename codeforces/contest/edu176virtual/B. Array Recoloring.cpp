#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    
    long long ans = 0;
    for (int i=0; i<n; ++i){
        vector<int> l, r;
        for (int j=0; j<n; ++j){
            if (j < i){
                l.push_back(a[j]);
            } else if (j > i) {
                r.push_back(a[j]);
            }
        }
        sort(l.rbegin(), l.rend());
        sort(r.rbegin(), r.rend());
    
        int p1=0, p2=0;
        long long y = a[i];
        int m = k;
        if (i > 0){
            y += l[p1++];
            --m;
        }
        if (i < n-1){
            y += r[p2++];
            --m;
        }
        if (m < 0){
            continue;
        }
        while (m-- > 0){
            int t1 = (p1<l.size()) ? l[p1] : 0;
            int t2 = (p2<r.size()) ? r[p2] : 0;
            debug(t1, t2);
            if (t1 >= t2){
                y += l[p1++];
            } else {
                y += r[p2++];
            }
        }
        debug(i, y);
        ans = max(ans, y);
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
