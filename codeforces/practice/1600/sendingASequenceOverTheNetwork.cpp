#include <bits/stdc++.h>
using namespace std;

#define INTERACTIVE

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int& v : a) cin >> v;

    vector<vector<int>> end(n, vector<int>());
    for (int i=0; i<n; ++i){
        if (i+a[i] < n) end[i+a[i]].push_back(i);
        if (i-a[i] >= 0) end[i].push_back(i-a[i]);
    }

    vector<bool> dp(n);
    for (int i=0; i<n; ++i){
        for (int p : end[i]){
            if (p==0 || dp[p-1]){
                dp[i] = true;
                break;
            }
        }
    }

    if (dp.back()) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
