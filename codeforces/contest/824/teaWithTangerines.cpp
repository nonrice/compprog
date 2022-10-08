#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int& v : a) cin >> v;

    int m = *min_element(a.begin(), a.end()) * 2 - 1;
    int ans = 0;
    for (int v : a){
        ans += max(0, (v+m-1)/m - 1);
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}

