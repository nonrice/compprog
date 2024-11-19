#include <bits/stdc++.h>
using namespace std;

int p[3001], m[3001];
bool a[3000];

void solve(){
    int n; cin >> n;
    for (int i=0; i<n; ++i){
        char v; cin >> v;
        a[i] = (v=='+');
        p[i+1] = p[i] + (v=='+');
        m[i+1] = m[i] + (v=='-');
    }

    int ans = 0;
    for (int i=0; i<n; ++i){
        for (int j=i+1; j<=n; ++j){
            int diff = m[j]-m[i] - (p[j]-p[i]);
            ans += (diff>=0 && diff%3 == 0);
        }
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
