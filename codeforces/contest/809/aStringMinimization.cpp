#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int& v : a) cin >> v;

    vector<char> s(m);
    fill(s.begin(), s.end(), 'B');
    for (int i=0; i<n; ++i){
        int good = min(a[i]-1, m-a[i]);
        int bad = max(a[i]-1, m-a[i]);
        if (s[good] != 'A'){
            s[good] = 'A';
        } else {
            s[bad] = 'A';
        }
    }

    for (char ch : s){
        cout << ch;
    }
    cout << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
