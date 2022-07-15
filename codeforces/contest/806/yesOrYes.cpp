#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    for (char& ch : s) ch = tolower(ch);

    if (s == "yes") {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
