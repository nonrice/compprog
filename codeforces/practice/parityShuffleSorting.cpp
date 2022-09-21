#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;

    vector<int> p[2];
    bool l, f;
    bool set_f = false;
    for (int i=1; i<=n; ++i){
        int v; cin >> v;
        
        p[l = v&1].push_back(i);

        if (!set_f){
            f = l;
            set_f = true;
        }
    }
    
    int fb[2] = { 1, n }; 
    
    if (f == l){
        p[l].resize(p[l].size()-1);
    }

    cout << n - (f==l) << '\n';
    for (int v : p[l]) cout << min(v, fb[l==f]) << ' ' << max(v, fb[l==f]) << '\n';
    for (int v : p[!l]) cout << min(v, fb[l!=f]) << ' ' << max(v, fb[l!=f]) << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
