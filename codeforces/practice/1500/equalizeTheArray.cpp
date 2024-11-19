#include <bits/stdc++.h>
using namespace std;

// til map is faster than unordered_map

void solve(){
    int n; cin >> n;
    map<int, int> f;
    for (int i=0; i<n; ++i){
        int v; cin >> v;
        ++f[v];
    }

    const int sz = f.size();
    vector<int> fs(sz);
    int l=0, r=0;
    int p = 0;
    for (auto& v : f){
        r += v.second;
        fs[p] = v.second;
        ++p;
    }
    sort(fs.begin(), fs.end());
    
    int bst = r;
    for (int i=0; i<sz; ++i){
        r -= fs[i];
        bst = min(bst, l + r - (sz-i-1)*fs[i]);
        l += fs[i];
    }

    cout << bst << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
