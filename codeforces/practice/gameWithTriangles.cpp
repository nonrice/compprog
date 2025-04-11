#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    for (int i=0; i<m; ++i){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    vector<long long> g(1), h(1);
    for (int i=0; n-i-1>i; ++i){
        g.push_back(g.back() - a[i] + a[n-i-1]);
    }
    for (int i=0; m-i-1>i; ++i){
        h.push_back(h.back() - b[i] + b[m-i-1]);
    }
    
    vector<long long> ans;
    for (int k=1; k<=n+m && m-k>=2*k-n && m-k>=0; ++k){
        // c + d = k
        // n-d >= 2c
        // m-c >= 2d

        // c = k-d
        // n-d >= 2k - 2d
        // m-k+d >= 2d

        // 2k-n <= d <= m-k

        long long y = -1;
        int d = max(0, 2*k-n);
        for (int s = m-k-d; s>=1; s/=2){
            while (d+s<=m-k && k-(d+s)>=0 && g[k-(d+s)] + h[d+s] > g[k-(d+s-1)] + h[d-1+s]){
                d += s;
            }
        }
        ans.push_back(g[k-d] + h[d]);
    }

    cout << ans.size() << '\n';
    for (auto y : ans){
        cout << y << ' ';
    }
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
