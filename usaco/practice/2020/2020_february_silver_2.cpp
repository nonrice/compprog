#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

struct line_sum {
    long long val = 0;
    int i = 0;
    vector<int> p;

    void next(){
        if (i+1<p.size()) val += (p[i+1]-p[i]) * (2*(i+1) - p.size());
        ++i;
    }

    void init(){
        sort(p.begin(), p.end());
        for (auto x : p) val = (val + x - p[0]) % MOD;
    }
};

map<int, line_sum> rs, cs;

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

#ifndef LOCAL
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
#endif

    int n; cin >> n;
    for (int i=0; i<n; ++i){
        int r, c; cin >> r >> c;
        rs[r].p.push_back(c);
        cs[c].p.push_back(r);
    }

    for (auto& [r, s] : rs) s.init();
    for (auto& [c, s] : cs) s.init();

    long long ans = 0;
    for (auto& [r, s] : rs){
        for (auto c : s.p){
            ans = (ans + (s.val * cs[c].val)%MOD) % MOD;
            s.next();
            cs[c].next();
        }
    }

    cout << ans << '\n';
}
