#include <bits/stdc++.h>
using namespace std;

constexpr long long M = 1000000007;

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    
    int n, t; cin >> n >> t;
    int u, v; cin >> u >> v;
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int m = u;
    vector<int> d(m);
    for (int i=0; i<u; ++i){
        d[i] = a[i+n-u] - a[i+n-u-1];
    }

    int w = u-v;
    for (int ct=0; ct<t; ++ct){
        --d[w];
        ++d[0];
    
        if (d[w] == -1){
            int l=w-1;
            while (l>=0 && d[l]==0){
                --l;
            }
            int r=w+1;
            while (r<m && d[r]==0){
                ++r;
            }
            d[w] = 0;
            d[l + (r-w)] = 1;

            if (l>=0){
                --d[l];
            }
            if (r<m){
                --d[r];
            }
        }
    }

    long long ans = 0;
    for (int i=0; i<n-u; ++i){
        ans = (ans + 1LL*a[i]*a[i]%M) % M;
    }
    long long x = a[n-u-1];
    for (int i=0; i<m; ++i){
        x += d[i];
        ans = (ans + x*x%M) % M;
    }
    cout << ans << '\n';
}


