#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

struct cell {
    long long v;
    int i, j;

    cell(long long v, int i, int j) : i(i), j(j), v(v) {}

    bool operator<(const cell& o) const {
        return v < o.v;
    }
};

constexpr pair<int, int> dd[] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<cell> c;
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            cin >> a[i][j];
            c.emplace_back(a[i][j], i, j);
        }
    }

    long long x = 0;
    sort(c.begin(), c.end());
    for (auto [v, i, j] : c){
        int f = -1;
        for (auto [di, dj] : dd){
            int ni = i+di;
            int nj = j+dj;
            if (ni>=0 && ni<n && nj>=0 && nj<m){
                if (a[ni][nj] < a[i][j]){
                    f = max(f, a[ni][nj]);
                }
            }
        }
        x += a[i][j] - f - 1;
        a[i][j] = f+1;
    }

    debug(x);

    if (x % 2 != 0){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}