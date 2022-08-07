#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    vector<int> f(n+1);
    for (int& v : a) cin >> v;
    for (int i=n-1; i>=0; --i){
        if (++f[a[i]] == 2){
            cout << i+1 << '\n';
            return;
        }
    }
    cout << "0\n"; 
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
