#include <bits/stdc++.h>
using namespace std;

int a[200000];

void solve(){
    int n, h; cin >> n >> h;
    for (int i=0; i<n; ++i) cin >> a[i];

    sort(a, a+n);
    int ans = 0;
    for (int i=0; i<3; ++i){
        long long p=h;
        int s=0;
        int cur=0;
        for (int j=0; j<n; ++j){
            if (p <= a[j]){
                if (s==3) break;
                for (; s<3 && p<=a[j]; ++s) p *= (s==i ? 3 : 2);
                if (p<=a[j]) break;
            }
            p += a[j]/2;
            ++cur;
        }
        ans = max(ans, cur);
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
