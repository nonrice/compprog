#include <bits/stdc++.h>
using namespace std;

int a[100000];

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

#ifndef LOCAL
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
#endif

    int n; cin >> n;
    for (int i=0; i<n; ++i) cin >> a[i];
    sort(a, a+n);

    int mn=INT_MAX, mx=INT_MIN;
    for (int i=0; i<2; ++i){
        int r=0;
        for (int l=0; l<n; ++l){
            while (r+1<n && a[r+1]-a[l]<=n-1) ++r;
            if (r==n-1 && a[r]-a[l]<n-1) break;
            mn = min(mn, n-(r-l+1));
            mx = max(mx, n-(r-l+1)+1 - (r==n-1 ? 1 : a[r+1]-a[r]==n));
            //cout << l << ' ' << r << ' ' << mn << ' ' << mx << '\n';
        }
        reverse(a, a+n);
        for (int j=0; j<n; ++j) a[j] = 1000000000-a[j];
    }

    cout << mn << '\n' << mx << '\n';
}
