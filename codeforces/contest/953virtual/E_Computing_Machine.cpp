#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

constexpr int B = 447; // sqrt 2*10^5
struct query {
    int l, r, i;

    bool operator<(query o) const {
        return make_pair(l/B, r) < make_pair(o.l/B, o.r);
    }
};

void print(query q){
    cerr << '(' << q.l << ' ' << q.r << ' ' << q.i << ')';
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    string t; cin >> t;

    int q; cin >> q;
    vector<query> qs(q);
    for (int i=0; i<q; ++i){
        cin >> qs[i].l >> qs[i].r;
        --qs[i].l;
        --qs[i].r;
        qs[i].i = i;
    }

    // HAIL MO
    sort(qs.begin(), qs.end());


    int l=0, r=0;
    int ans = (s[0] == '1');

    vector<bool> c(n);
    c[0] = (t[0] == '1');
    vector<bool> d(n);
    d[0] = (s[0] == '1');

    vector<int> y(q);
    for (int i=0; i<q; ++i){

        while (l > qs[i].l){
            --l;
            if (s[l] == '1'){
                d[l] = true;
                ++ans;
            }
            if (s[l] == '0' && r-l+1 > 2 && s[l+2] == '0'){
                c[l+1] = true;
                if (r-l+1 > 3 && c[l+3] && !d[l+2]){
                    d[l+2] = true;
                    ++ans;
                }
            }
            if (t[l] == '1'){
                c[l] = true;
                if (r-l+1 > 2 && c[l+2] && !d[l+1]){
                    d[l+1] = true;
                    ++ans;
                }
            }
        }

        while (r < qs[i].r){
            ++r;
            if (s[r] == '1'){
                d[r] = true;
                ++ans;
            }
            if (s[r] == '0' && r-l+1 > 2 && s[r-2] == '0'){
                c[r-1] = true;
                if (r-l+1 > 3 && c[r-3] && !d[r-2]){
                    d[r-2] = true;
                    ++ans;
                }
            }
            if (t[r] == '1'){
                c[r] = true;
                if (r-l+1 > 2 && c[r-2] && !d[r-1]){
                    d[r-1] = true;
                    ++ans;
                }
            }
        }

        while (l < qs[i].l){
            if (s[l] == '1'){
                d[l] = false;
                --ans;
            }
            if (s[l] == '0' && r-l+1 > 2 && s[l+2] == '0'){
                if (t[l+1] == '0'){
                    c[l+1] = false;
                    if (r-l+1 > 3 && c[l+3]){
                        d[l+2] = false;
                        --ans;
                    }
                }
            }
            if (t[l] == '1'){
                c[l] = false;
                if (r-l+1 > 2 && c[l+2] && s[l+1] == '0'){
                    d[l+1] = false;
                    --ans;
                }
            }
            ++l;
        }

        while (r > qs[i].r){
            if (s[r] == '1'){
                d[r] = false;
                --ans;
            }
            if (s[r] == '0' && r-l+1 > 2 && s[r-2] == '0'){
                if (t[r-1] == '0'){
                    c[r-1] = false;
                    if (r-l+1 > 3 && c[r-3]){
                        d[r-2] = false;
                        --ans;
                    }
                }
            }
            if (t[r] == '1'){
                c[r] = false;
                if (r-l+1 > 2 && c[r-2] && s[r-1] == '0'){
                    d[r-1] = false;
                    --ans;
                }
            }
            --r;
        }

        debug(c);

        y[qs[i].i] = ans;
    }

    for (int i=0; i<q; ++i){
        cout << y[i] << '\n';
    }

    debug(y);
    debug(qs);
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}