#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000;

int a[N];
long long c[N];
vector<int> adj[N];
set<int> r;
bool vis[N];

pair<long long, long long> dfs(int u){
    vis[u] = true;

    long long s1 = 0;
    if (a[u] != u){
        s1 += c[u];
    }

    long long s2 = 0;
    for (auto v : adj[u]){
        if (v != u && !r.count(v)){
            auto [t1, t2] = dfs(v);
            s1 += min(t1, t2);
            s2 += t1;
        }
    }   

    return { s1, s2 };
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n; cin >> n;
    for (int i=0; i<n; ++i){
        cin >> a[i];
        --a[i];
        adj[a[i]].push_back(i);
        if (a[i] == i){
            r.insert(a[i]);
        }
    }
    for (int i=0; i<n; ++i){
        cin >> c[i];
    }

    long long ans = 0;
    for (auto u : r){
        auto [s1, s2] = dfs(u);
        ans += min(s1, s2);
    }

    for (int u=0; u<n; ++u){
        if (!vis[u]){
            int p1 = u;
            int p2 = a[u];
            while (p1 != p2){
                p2 = a[a[p2]];
                p1 = a[p1];
            }

            r.insert(p1);
            long long h1 = dfs(p1).first;
            r.erase(p1);
            r.insert(a[p1]);
            long long h2 = dfs(a[p1]).first;
            r.erase(a[p1]);
            ans += min(h1, h2);
        }
    }

    cout << ans << '\n';
}
