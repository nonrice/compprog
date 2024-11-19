#include <bits/stdc++.h>
using namespace std;

int f[100000];
int a[100000];
vector<int> c;
vector<int> t;
bool vis[100000];

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

#ifndef LOCAL
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
#endif
    
    int n, m, k; cin >> n >> m >> k;
    iota(f, f+n, 0);
    iota(a, a+n, 0);
    for (int i=0; i<m; ++i){
        int l, r; cin >> l >> r;
        reverse(f+l-1, f+r);
    }

    for (int i=0; i<n; ++i){
        if (!vis[i]){
            int len = 1;
            int cur = i;
            c.push_back(cur);
            vis[cur] = true;
            const int bgn = cur;
            while (f[cur] != bgn){
                cur = f[cur];
                c.push_back(cur);
                vis[cur] = true;
                ++len;
            }

            int rot = k%len;
            t.resize(c.size());
            for (int j=0; j<len; ++j) t[j] = a[c[j]];
            rotate(t.begin(), t.begin()+rot, t.end());
            for (int j=0; j<len; ++j) a[c[j]] = t[j];

            c.clear();
            t.clear();
        }
    }
    
    for (int i=0; i<n; ++i) cout << a[i]+1 << '\n';
}
