#include <bits/stdc++.h>
using namespace std;

// idea: dfs from the end to good/bad to check reacheability

pair<int, int> d[] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
char g[50][50];
bool vis[50][50];
int h, w;

void dfs(int r, int c){
    for (auto [dr, dc] : d){
        int nr = r+dr, nc = c+dc;
        if (nr>=0 && nr<h && nc>=0 && nc<w && (g[nr][nc] == '.' || g[nr][nc] == 'G' || g[nr][nc] == 'B') && !vis[nr][nc]){
            vis[nr][nc] = true;
            dfs(nr, nc);
        }
    }
}

void flood(){
    memset(vis, false, sizeof(vis));
    if (g[h-1][w-1] == '#') return;
    dfs(h-1, w-1);
}

void solve(){
    scanf("%d%d", &h, &w);

    vector<pair<int, int>> good, bad;
    for (int r=0; r<h; ++r){
        scanf("%s", g[r]);
        for (int c=0; c<w; ++c){
            char cell = g[r][c];
            if (cell == 'G') good.emplace_back(r, c);
            else if (cell == 'B') bad.emplace_back(r, c);
        }
    }
    
    for (auto [cr, cc] : bad){
        for (auto [dr, dc] : d){
            int nr = cr+dr, nc = cc+dc;
            if (nr>=0 && nr<h && nc>=0 && nc<w && (g[nr][nc] == '.' || g[nr][nc] == 'G')){
                if (g[nr][nc] == 'G'){
                    printf("NO\n");
                    return;
                }
                g[nr][nc] = '#';
            }
        }
    }
    
    flood();
    for (auto [cr, cc] : bad){
        if (vis[cr][cc]){
            printf("NO\n");
            return;
        }
    }

    for (auto [cr, cc] : good){
        if (!vis[cr][cc]){
            printf("NO\n");
            return;
        }
    }

    printf("YES\n");
}

int main(){
    int cases; scanf("%d", &cases);
    while (cases--) solve();
}
