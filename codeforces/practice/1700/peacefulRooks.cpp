#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n, -1);
    for (int i=0; i<m; ++i){
        int r, c; cin >> r >> c;
        a[--r] = --c;
    }

    vector<bool> vis(n);
    int ans=0;
    for (int i=0; i<n; ++i){
        if (a[i] != -1 && a[i] != i){
            ++ans;
        } else {
            vis[i] = true;
        }
    }

    for (int i=0; i<n; ++i){
        if (!vis[i]){
            for (int v=a[a[i]]; v!=-1 && !vis[v]; v=a[v]){
                vis[v] = true;
                if (v == a[i]){
                    ++ans;
                    break;
                }
            }
        }
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
