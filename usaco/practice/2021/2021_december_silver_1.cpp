#include <bits/stdc++.h>
using namespace std;

#define int long long

struct seg {
    int a, b, w;

    bool operator<(const seg& o) const{
        return a<o.a;
    }
};

int f[400000]; 
pair<int, int> p[400000];
seg s[400000];

signed main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int k, m, n; cin >> k >> m >> n;
    for (int i=0; i<k; ++i) cin >> p[i].first >> p[i].second;
    for (int i=1; i<=m; ++i) cin >> f[i];
    f[0] = INT_MIN;
    f[m+1] = (long long)INT_MAX*10;

    sort(p, p+k);
    sort(f+1, f+m+1);
    int c = 0;
    for (int i=0; i<k; ++i){
        int l, r;
        while (c+1 <= m+1 && f[c+1] <= p[i].first) ++c;
        l = f[c];
        if (c+1 <= m+1) ++c;
        r = f[c];
        --c;

        if (p[i].first - l < r - p[i].first){
            s[i] = { l, 2*p[i].first - l, p[i].second };
        } else {
            s[i] = { 2*p[i].first - r, r, p[i].second };
        }
    }

    sort(s, s+k);

    vector<long long> v;
    int end = s[0].b;
    long long total = 0;
    for (int i=0; i<k; ++i){
        if (s[i].a < end){
            total += s[i].w;
        } else {
            v.push_back(total);
            end = s[i].b;
            total = s[i].w;
        }
    }
    v.push_back(total);

    sort(v.begin(), v.end(), greater<long long>());
    long long ans = 0;
    for (int i=0; i<min(n, (int)v.size()); ++i){
        ans += v[i];
    }

    cout << ans << '\n';
}
