#include <bits/stdc++.h>
using namespace std;

void solve(){
    bool has[26] = {};
    char v;
    cin >> v; has[v-'a'] = true;
    cin >> v; has[v-'a'] = true;
    cin >> v; has[v-'a'] = true;
    cin >> v; has[v-'a'] = true;
    
    int uniq = 0;
    for (bool b : has) uniq += b;

    cout << uniq-1 << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
