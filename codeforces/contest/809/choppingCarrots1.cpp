#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    int a_mx = 0;
    for (int& v : a){
        cin >> v;
        a_mx = max(a_mx, v);
    }
    
    int bst = INT_MAX;
    for (int t=0; t<=a_mx; ++t){
        int mx=0, mn=INT_MAX;
        for (int v : a){
            int pi = (!t) ? k : max(1, min(k, v/t));
            mx = max(mx, v/pi);
            mn = min(mn, v/pi);
        }
        bst = min(bst, mx-mn);
    }
    
    cout << '\n';
    cout << bst << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
