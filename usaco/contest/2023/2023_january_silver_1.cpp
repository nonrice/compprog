#include <bits/stdc++.h>
using namespace std;

char s[100002], t[100002];

map<char, char> mp;

char vis[100002];

void solve(){
    mp.clear();
    memset(vis, 0, sizeof(vis));

    cin >> s >> t;
    const int n = strlen(s);

    for (int i=0; i<n; ++i){
        if (!mp.count(s[i])) mp[s[i]] = t[i];
        else if (mp[s[i]] != t[i]){
            cout << "-1\n";
            return;
        }
    }

    int cycles=0;
    int bad = 0;
    for (auto [u, v] : mp){
        if (u != v) ++bad;

        if (!vis[u] && u!=v){
            vis[u] = u;
            char cur = mp[u];
            while (!vis[cur]){
                if (!mp.count(cur)) break;
                vis[cur] = u;
                cur = mp[cur];
            }

            if (vis[cur] == u && mp.count(cur) && mp[cur]!=cur) ++cycles;
        }
    }

    cout << cycles+bad << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}

