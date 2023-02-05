#include <bits/stdc++.h>
using namespace std;

int a[250][250];
int n;

pair<int, int> d[] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
bool vis[250][250];
unordered_map<int, int> sz;
int isz;

void dfs1(int r, int c, int c1, int c2){
    for (auto [dr, dc] : d){
        int nr = r+dr;
        int nc = c+dc;
        if (nr<n && nr>=0 && nc<n && nc>=0 && !vis[nr][nc]){
            if (a[nr][nc] == c1 || a[nr][nc] == c2){
                ++sz[a[nr][nc]];
                vis[nr][nc] = true;
                dfs1(nr, nc, c1, c2);
            } else if (c2 == -1){
                ++sz[a[nr][nc]];
                vis[nr][nc] = true;
                dfs1(nr, nc, c1, a[nr][nc]);
            }
        }
    }
}

void dfs2(int r, int c, int c1){
    for (auto [dr, dc] : d){
        int nr = r+dr;
        int nc = c+dc;
        if (nr<n && nr>=0 && nc<n && nc>=0 && !vis[nr][nc] && a[nr][nc] == c1){
            ++isz;
            vis[nr][nc] = true;
            dfs2(nr, nc, c1);
        }
    }
}

int main(){
#ifndef LOCAL
    freopen("multimoo.in", "r", stdin);
    freopen("multimoo.out", "w", stdout);
#endif
    cin.tie(0)->ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) cin >> a[i][j];

    int ans1=0, ans2=0;
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            memset(vis, 0, sizeof(vis));
            sz.clear();
            ++sz[a[i][j]];
            vis[i][j] = true;
            dfs1(i, j, a[i][j], -1);

            memset(vis, 0, sizeof(vis));
            isz = 1;
            vis[i][j] = true;
            dfs2(i, j, a[i][j]);

            ans1 = max(ans1, isz);
            for (auto [k, v] : sz) if (k != a[i][j]) ans2 = max(ans2, sz[a[i][j]] + v);
        }
    }

    cout << ans1 << '\n' << ans2 << '\n';
}
