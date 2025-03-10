#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, q; cin >> n >> q;
    vector<int> w(n);
    for (int i=0; i<n; ++i){
        cin >> w[i];
    }
    reverse(w.begin(), w.end());

    vector<vector<int>> b(30);
    vector<int> p(n+1);
    for (int i=0; i<n; ++i){
        p[i+1] = w[i] ^ p[i];

        for (int h=0; h<30; ++h){
            if ((w[i]>>h) & 1){
                b[h].push_back(i);
            }
        }
    }

    debug(w);
    debug(b);

    while (q--){
        debug(q);
        int x; cin >> x;
        int i=-1;
        while (x){
            int j = n-1;
            int h = 31-__builtin_clz(x);
            for (int k=29; k>=h; --k){
                auto it = upper_bound(b[k].begin(), b[k].end(), i);
                if (it != b[k].end()){
                    if ((x ^ (p[i+1] ^ p[*it])) < w[*it]){
                        debug(x, x^p[i+1]^p[*it], w[*it], "less");
                        j = min(j, *it-1);
                    } else {
                        j = min(j, *it);
                    }
                }
            }

            if (j == i){
                break;
            }

            x ^= (p[j+1] ^ p[i+1]);
            debug(j);
            i = j;
        }

        cout << i+1 << ' ';
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