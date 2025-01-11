#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

struct seg {
    int l, r, i;
};

void solve(){
    int n; cin >> n;
    vector<seg> s(n);
    for (int i=0; i<n; ++i){
        cin >> s[i].l >> s[i].r;
        s[i].i = i;
    }

    sort(s.begin(), s.end(), [&](const seg& a, const seg& b){
        if (a.l != b.l){
            return a.l < b.l;
        }
        return a.r > b.r;
    });
    vector<int> sr(n);
    set<int> cr;
    for (int i=0; i<n; ++i){
        if (i<n-1 && s[i+1].r == s[i].r && s[i+1].l == s[i].l){
            cr.insert(s[i+1].r);
        }
        auto it = cr.lower_bound(s[i].r);
        if (it != cr.end()){
            sr[s[i].i] = *it;
        }
        cr.insert(s[i].r);
    }

    sort(s.begin(), s.end(), [&](const seg& a, const seg& b){
        if (a.r != b.r){
            return a.r > b.r;
        }
        return a.l < b.l;
    });
    vector<int> sl(n);
    set<int> cl;
    vector<int> ans(n);
    for (int i=0; i<n; ++i){
        if (i<n-1 && s[i+1].l == s[i].l && s[i+1].r == s[i].r){
            cl.insert(s[i+1].l);
        }
        auto it = cl.upper_bound(s[i].l);
        if (it != cl.begin()){
            sl[s[i].i] = *(--it);
        }
        cl.insert(s[i].l);

        if (sl[s[i].i] != 0 && sr[s[i].i] != 0){
            ans[s[i].i] = (sr[s[i].i] - sl[s[i].i]) - (s[i].r - s[i].l);
        }
    }

    for (int i=0; i<n; ++i){
        cout << ans[i] << '\n';
    }
    // debug(sl);
    // debug(sr);
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}