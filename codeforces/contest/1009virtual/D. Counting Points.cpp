#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

struct circ {
    int x, r;
};

void solve(){
    int n, m; cin >> n >> m;
    vector<circ> p(n);
    for (int i=0; i<n; ++i){
        cin >> p[i].x;
    }
    for (int i=0; i<n; ++i){
        cin >> p[i].r;
    }
    
    sort(p.begin(), p.end(), [&](const circ& a, const circ& b){
        return a.r > b.r;
    });
    int h = 0;
    int j = n-1;
    long long a = 0;
    long long a0 = 0;
    while (j>=0){
        vector<pair<int, int>> g;
        for (int i=0; i<=j; ++i){
            int d = 0;
            for (int t=p[i].r; t>=1; t/=2){
                while (1LL*h*h + 1LL*(d+t)*(d+t) <= 1LL*p[i].r*p[i].r){
                    d += t;
                }
            }
            g.emplace_back(p[i].x - d, p[i].x + d);
        }

        sort(g.begin(), g.end());
        int e = g[0].first-1;
        for (auto [u, v] : g){
            if (u > e){
                a += v-u+1;
                e = v;
            } else {
                a += max(0, v-e);
                e = max(e, v);
            }
        }
        debug(g);
        debug(a);

        if (h == 0){
            a0 = a;
        }
        ++h;
        while (j>=0 && p[j].r < h){
            --j;
        }
    }

    cout << 2*a - a0 << '\n';

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
