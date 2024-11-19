#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a;
    vector<int> b;
    int x = 0;
    for (int i=0; i<n; ++i){
        int v; cin >> v;
        if (v < i+1){
            ++x;
            a.push_back(i+1);
            b.push_back(v);
        }
    }
    sort(a.begin(), a.end());

    long long ans = 0;
    for (int v : b){
        ans += lower_bound(a.begin(), a.end(), v) - a.begin();
    }

    cout << ans << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
