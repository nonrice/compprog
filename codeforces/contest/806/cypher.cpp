#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int& v : a) cin >> v;

    for (int i=0; i<n; ++i){
        int m; cin >> m;
        string s; cin >> s;
        for (int j=m-1; j>=0; --j){
            if (s[j] == 'U'){
                --a[i];
            } else {
                ++a[i];
            }
            if (a[i] == 10) a[i] = 0;
            else if (a[i] == -1) a[i] = 9;
        }
    }

    for (int v : a) cout << v << ' ';
    cout << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
