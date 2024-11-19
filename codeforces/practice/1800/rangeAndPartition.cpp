#include <bits/stdc++.h>
using namespace std;

int p[200001];

void solve(){
    int n, k; cin >> n >> k;
    for (int i=0; i<n; ++i){
        int ai; cin >> ai;
        ++p[ai];
    }

    for (int i=1; i<=n; ++i) p[i] += p[i-1];
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
