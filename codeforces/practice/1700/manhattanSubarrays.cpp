#include <bits/stdc++.h>
using namespace std;

int a[200000];

inline bool check3(int x, int y, int z) noexcept {
    if (a[x] > a[z]) swap(x, z);
    return a[y] < a[x] || a[y] > a[z];
}

void solve(){
    int n; cin >> n;
    for (int i=0; i<n; ++i) cin >> a[i];

    int ans = n+n-1;
    for (int i=0; i<n-2; ++i){
        ans += check3(i, i+1, i+2);
    }

    for (int i=0; i<n-3; ++i){
        ans += (
            check3(i, i+1, i+2) &&
            check3(i, i+1, i+3) &&
            check3(i, i+2, i+3) &&
            check3(i+1, i+2, i+3)
        );
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
