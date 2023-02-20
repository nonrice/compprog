#include <bits/stdc++.h>
using namespace std;

int a[200000];

void solve(){
    int n, c; cin >> n >> c;
    int start = INT_MAX;
    int start_i;
    for (int i=0; i<n; ++i){
        cin >> a[i];
        if (a[i]+i+1 < start){
            start = a[i]+i+1;
            start_i = i;
        }
        a[i] = min(a[i] + i+1, a[i] + n-i);
        cout << a[i] << ' ';
    }
    cout << '\n';

    c -= start;
    a[start_i] = -1;
    sort(a, a+n);
    int ans = 0;
    if (c >= 0) ans = 1;
    for (int i=0; i<n; ++i){
        if (c - a[i] >= 0){
            if (a[i] != -1){
                c -= a[i];
                ++ans;
            }
        } else {
            break;
        }
        cout << c << '\n';
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();
}
