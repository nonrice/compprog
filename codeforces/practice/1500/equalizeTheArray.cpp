#include <bits/stdc++.h>
using namespace std;

// lesson: map is much faster than unordered map (wtf?)

void solve(){
    int n; cin >> n;
    map<int, int> f;
    for (int i=0; i<n; ++i){
        int v; cin >> v;
        ++f[v];
    }

    map<int, int> fs;
    for (auto v : f){
        ++fs[v.second];
    }
    
    int l=0, r=n;
    int bst = r;
    int rem = f.size();
    for (auto v : fs){
        bst = min(bst, l + r - rem*v.first);
        l += v.second * v.first;
        r -= v.second * v.first;
        rem -= v.second;
    }

    cout << bst << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}

