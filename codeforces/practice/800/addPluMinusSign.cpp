#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    bool add = false;
    for (int i=1; i<n; ++i){
        if (s[i] == '0') cout << '+';
        else {
            if (add) cout << '+';
            else cout << '-';
            add ^= 1;
        }
    }

    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
