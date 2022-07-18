#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> lst(n);
    fill(lst.begin(), lst.end(), -1);
    vector<int> ans(n);

    for (int i=0; i<n; ++i) {
        int v; cin >> v; --v;
        if ((lst[v]-i-1)%2 == 0 || lst[v]==-1){
            ++ans[v];
            lst[v] = i;
        }
    }

    for (int v : ans){
        cout << v << ' ';
    }
    cout << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
