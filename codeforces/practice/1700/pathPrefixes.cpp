#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
void dfs(ll A, vector<ll>& B, int cur, vector<int>& ans, vector<vector<tuple<int, ll, ll>>>& adj){
    for (auto [v, a, b] : adj[cur]){
        B.push_back(B.back()+b);
        dfs(A+a, B, v, ans, adj);
        B.pop_back();
    }
    ans[cur] = upper_bound(B.begin(), B.end(), A) - B.begin() - 1; 
}
 
void solve(){
    int n; cin >> n;
    vector<vector<tuple<int, ll, ll>>> adj(n);
    for (int i=1; i<n; ++i){
        int p; cin >> p; --p;
        ll a, b; cin >> a >> b;
        adj[p].emplace_back(i, a, b);
    }
 
    vector<int> ans(n);
    vector<ll> B = { 0 };
    dfs(0, B, 0, ans, adj);
   
    for (int i=1; i<n; ++i) cout << ans[i] << ' ';
    cout << '\n';
}
 
int main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
