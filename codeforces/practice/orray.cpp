#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    map<int, int> a;
    for (int i=0; i<n; ++i){
        int v; cin >> v;
        ++a[v];
    }
    
    int cur = (--a.end())->first;
    cout << cur << ' ';
    --a[cur];
    while (!a.empty()){
        int bst = cur;
        int bst_k;
        for (auto& [k, v] : a){
            if (v && (cur|k) > bst){
                bst = cur|k;
                bst_k = k;
            }
        }

        if (bst > cur){
            cur = bst;
            if (--a[bst_k] == 0) a.erase(bst_k);
            cout << bst_k << ' ';
        } else {
            break;
        }
    }

    for (auto [k, v] : a){
        while (v--){
            cout << k << ' ';
        }
    }
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
