#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[1000];

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n; cin >> n;
    for (int i=0; i<n; ++i){
        cin >> a[i];
        if (i&1) a[i] *= -1;
    }

    ll ans = 0;
    for (int i=0; i<n; i+=2){
        ll min_p = LLONG_MAX-1;
        ll p = 0;
        for (int j=i+1; j<n; j+=2){
            p += a[j]+a[j-1];
            if (p<0){
                ans += max(0LL, min(min_p+1, min(a[i], -1*(a[j]-p))));
                break;
            } else {
                ans += max(0LL, min(min_p+1-p, min(a[i]-p, -1*a[j])));
            }
            min_p = min(p, min_p);
        }
    }

    cout << ans << '\n';
}
