#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

struct node {
    node *l=nullptr, *r=nullptr;
    int x = -1;
    int d;
    
    node () {}

    node (int x, int d) : x(x), d(d) {}

    void add(int x){
        if (d == -1){
            this->x = x;
            return;
        }
        if ((x>>d) & 1){
            if (r){
                r->add(x);
                return;
            }
            (r = new node(x, d-1))->add(x);
        } else {
            if (l){
                l->add(x);
                return;
            }
            (l = new node(x, d-1))->add(x);
        }
    }

    int xor_comp(int y){
        if (d == -1){
            return x;
        }
        if (l==nullptr || r==nullptr){
            if (l!=nullptr){
                return l->xor_comp(y);
            } else {
                return r->xor_comp(y);
            }
        }

        if ((y>>d) & 1){
            return l->xor_comp(y);
        } else {
            return r->xor_comp(y);
        }
    }

    /*
    ~node(){
        delete l;
        delete r;
    }
    */
};

constexpr int B = 447;

node t[200000/B];
int a[200000];

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
        t[i] = *new node(0, 30);
    }
    for (int i=0; i<n; ++i){
        t[i/B].add(a[i]);
    }

    auto query = [&](int l, int r, int x){
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
    int t; cin >> t;
    while (t--){
        solve();
    }
}
