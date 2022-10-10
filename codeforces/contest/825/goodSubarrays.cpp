#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int& v : a) cin >> v;

    int p2 = 0;
    long long ans = 0;
    for (int i=0; i<n; ++i){
        while (p2<n && a[p2] > p2-i){
            ++p2;
        }
        ans += p2-i;
    }
    
    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}

