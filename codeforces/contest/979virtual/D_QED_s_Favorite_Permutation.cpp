#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

constexpr long long M = 999999667;

constexpr long long B = 200005;

constexpr int MAXN = 200000;
long long p[MAXN+1], ps[MAXN+1];
int a[MAXN];

long long binpow(long long a, long long b, long long m){
    long long ans = 1;
    while (b){
        if (b&1) ans = ans*a%m;
        a = a*a%m;
        b >>= 1;
    }
    return ans;
}

struct seg {
    int l, r;

    seg() {}

    seg(int l, int r) : l(l), r(r) {}

    bool operator<(const seg& o) const {
        return l<o.l;
    }

    bool chk() const{
        return p[r+1]*binpow(p[l], M-2, M)%M == ps[r+1]*binpow(ps[l], M-2, M)%M;
    }
};

void print(seg s){
    cerr << '(' << s.l << ',' << s.r << ',' << s.chk() << ") ";
}

void solve(){
    int n, q; cin >> n >> q;
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    p[0] = 1;
    for (int i=1; i<=n; ++i){
        p[i] = p[i-1]*(B-a[i-1]) % M;
    }

    string s; cin >> s;
    int l = 0;
    set<seg> g;
    for (int i=1; i<=n; ++i){
        if (i==n || (s[i] == 'R' && s[i-1] == 'L')){
            g.emplace(l, i-1);
            l = i;
        }
    }

    int b = 0;
    for (auto v : g){
        b += !v.chk();
    }

    while (q--){
        int x; cin >> x;
        --x;
        debug(x);
        debug(g);
        debug(b);

        if ((x<n-1 && s[x]=='R' && s[x+1]=='R') || (x>0 && s[x]=='L' && s[x-1]=='L')){
            auto it = --g.upper_bound(seg(x, x));

            auto [l, r] = *it;
            b -= (!it->chk());
            g.erase(it);

            seg u, v;
            if (s[x] == 'R'){
                u = seg(l, x);
                v = seg(x+1, r);
            } else {
                u = seg(l, x-1);
                v = seg(x, r);
            }
            b += (!u.chk()) + (!v.chk());
            g.insert(u);
            g.insert(v);
        } 
        if ((x<n-1 && s[x]=='L' && s[x+1]=='R') || (x>0 && s[x]=='R' && s[x-1]=='L')){
            set<seg>::iterator it_l, it_r;

            if (s[x] == 'L'){
                it_r = g.lower_bound(seg(x+1, x+1));
                it_l = --g.lower_bound(seg(x+1, x+1));
            } else {
                it_r = g.lower_bound(seg(x, x));
                it_l = --g.lower_bound(seg(x, x));
            }

            b -= (!(it_l->chk())) + (!(it_r->chk()));
            seg u(it_l->l, it_r->r);
            b += (!u.chk());

            g.erase(it_l);
            g.erase(it_r);
            g.insert(u);
        }

        if (s[x] == 'R'){
            s[x] = 'L';
        } else {
            s[x] = 'R';
        }


        if (b == 0){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    ps[0] = 1;
    for (int i=1; i<=MAXN; ++i){
        ps[i] = ps[i-1]*(B-i) % M;
    }

    int t; cin >> t;
    while (t--){
        solve();
    }
}