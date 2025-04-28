#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

constexpr int B = 447;

struct trie {
    struct node {
        int l=-1, r=-1, x=-1;
    };

    //node t[B*30];
    node* t;
    int e=0;

    void add(int x){
        int i=0;
        for (int d=30; d>=0; --d){
            debug(i);
            if ((x>>d) & 1){
                if (t[i].r != -1){
                    i = t[i].r;
                    continue;
                }
                i = (t[i].r = ++e);
                t[i].r = -1;
                t[i].l = -1;
            } else {
                if (t[i].l != -1){
                    i = t[i].l;
                    continue;
                }
                i = (t[i].l = ++e);
                debug(i, t[i].l);
                t[i].r = -1;
                t[i].l = -1;
            }
        }
        t[i].x = x;
    }

    int xor_comp(int y){
        int i=0;
        for (int d=30; d>=0; --d){
            if (t[i].l==-1 || t[i].r==-1){
                if (t[i].l!=-1){
                    i = t[i].l;
                } else {
                    i = t[i].r;
                }
                continue;
            }

            if ((y>>d) & 1){
                i = t[i].l;
            } else {
                i = t[i].r;
            }
        }
        return t[i].x;
    }
};

trie t[200000/B];
int a[200000];

int query(int l, int r, int x){
    int ans = 0;
    int i = l;

    while (i <= r && (i % B != 0 || i + B - 1 > r)){
        ans = max(ans, a[i] ^ x);
        ++i;
    }

    for (; i + B - 1 <= r; i += B){
        ans = max(ans, x ^ t[i / B].xor_comp(x));
    }

    for (; i <= r; ++i){
        ans = max(ans, a[i] ^ x);
    }

    return ans;
};

void solve(){
    int n, k; cin >> n >> k;

    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    if (k == 0){
        cout << 1 << '\n';
        return;
    }
    debug(k);

    for (int i=0; i<(n+B-1)/B; ++i){
        t[i].e = 0;
        t[i].t[0].l = -1;
        t[i].t[0].r = -1;
    }
    for (int i=0; i<n; ++i){
        t[i/B].add(a[i]);
    }

    int ans = n+1;
    for (int i=0; i<n-1; ++i){
        int j = min(n-1, i+ans-2); 
        if (j<=i){
            break;
        }
        debug(i, j, ans);
        if (query(i+1, j, a[i]) < k){
            continue;
        }

        for (int s = ans-1; s>=1; s/=2){
            while (j-s > i && query(i+1, j-s, a[i]) >= k){
                j -= s;
            }
        }
        debug(i, j, query(i, j, a[i]));
        ans = min(ans, j-i+1);
    }

    if (ans == n+1){
        cout << "-1\n";
    } else {
        cout << ans << '\n';
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);   
    
    for (int i=0; i<200000/B; ++i){
        t[i].t = new trie::node[B*30];
    }

    int t; cin >> t;
    while (t--){
        solve();
    }
}
