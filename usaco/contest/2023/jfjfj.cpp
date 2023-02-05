#include <bits/stdc++.h>
using namespace std;

void solve(){
    map<char, char> mp;
    string s, t;

    cin >> s >> t;
    const int n = s.size();

    for (int i=0; i<n; ++i){
        if (!mp.count(s[i])){
            if (s[i]!=t[i]) mp[s[i]] = t[i];
        } else if (mp[s[i]] != t[i]){
            cout << "-1\n";
            return;
        }
    }

    map<char, int> vis;
    int search_no=0;
    int ans = 0;
    for (auto [u, v] : mp){
        //cout << u << ' ' << v << '\n';
        if (!vis.count(u)){
            vis[u] = ++search_no;
            const int head = u;
            char cur = v;
            while (1){
                if (!mp.count(cur)) break;
                if (vis.count(cur)){
                    if (vis[cur] == search_no && cur == head) ++ans;
                    break;
                }
                vis[cur] = search_no;
                cur = mp[cur];
            }
        }
    }
    cout << ans+mp.size() << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}

