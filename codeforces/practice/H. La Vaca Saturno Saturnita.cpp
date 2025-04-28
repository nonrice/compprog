#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

constexpr int N = 1e5;

vector<int> s[N+1];

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    map<int, vector<int>> p;
    for (int i=0; i<n; ++i){
        p[a[i]].push_back(i);
    }

    while (q--){
        int k, l, r; cin >> k >> l >> r;
        --l, --r;
        
        long long ans = -k;
        int u=l-1;
        
        while (u != r){
            int v = r;
            for (int f : s[k]){
                auto it = upper_bound(p[f].begin(), p[f].end(), u);
                if (it != p[f].end()){
                    v = min(v, *it);
                }
            }
            ans += 1LL*(v-u)*k;
            while (k % a[v] == 0){
                k /= a[v];
            }
            u = v;
        }

        ans += k;
        
        cout << ans << '\n';
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    
    for (int f=2; f<=N; ++f){
        for (int x=f; x<=N; x+=f){
            s[x].push_back(f);
        }
    }

    int t; cin >> t;
    while (t--){
        solve();
    }
}
