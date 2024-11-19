#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<bool> c(n+1);
    
    cout << "2\n";
    for (int i=1; i<=n; ++i){
        int t = i;
        while (t <= n){
            if (!c[t]){
                cout << t << ' ';
                c[t] = true;
            }
            t *= 2;
        }
    }
    
    for (int i=1; i<=n; ++i){
        if (!c[i]) cout << i << ' ';
    }

    cout << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
