#include <bits/stdc++.h>
using namespace std;

int a[100000], b[100000];

map<int, int> chg;

signed main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

#ifndef LOCAL
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
#endif

    int n; cin >> n;
    for (int i=0; i<n; ++i){
        cin >> a[i] >> b[i];

        const int dist = abs(b[i] - a[i]);

        if (abs(a[i]) < dist){
            chg[b[i]] -= 2;
            ++chg[b[i]-(dist-abs(a[i]))];
            ++chg[b[i]+(dist-abs(a[i]))];
        }
    }

    long long inc = 0;
    long long mx = 0, cur = 0;
    int mx_idx;
    int prev;
    for (auto [x, d] : chg){
        cur += (x-prev)*inc;
        if (cur > mx){
            mx = cur;
            mx_idx = x;
        }
        inc += d;
        prev = x;
    }

    long long ans = 0;

    for (int i=0; i<n; ++i){
        ans += min(abs(a[i]-b[i]), abs(a[i])+abs(b[i]-mx_idx));
    }

    cout << ans << '\n';
}
