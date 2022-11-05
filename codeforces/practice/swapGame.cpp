#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;

    int f=0, mn1=INT_MAX, mn2=INT_MAX;
    while (n--){
        int v; cin >> v;
        if (!f) f = v;

        if (v <= mn1){
            mn2 = mn1;
            mn1 = v;
        } else if (v < mn2){
            mn2 = v;
        }
    }

    if (f != mn1 && f >= mn2) cout << "ALICE\n";
    else cout << "BOB\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
