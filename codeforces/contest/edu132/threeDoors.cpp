#include <bits/stdc++.h>
using namespace std;

void solve(){
    array<int, 4> keys;
    for (int& v : keys) cin >> v;
    
    int cur = keys[0];
    for (int i=0; i<3; ++i){
        if (keys[cur] == 0){
            if (i == 2){
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            return;
        }
        cur = keys[cur];
    }

    cout << "NO\n";
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
