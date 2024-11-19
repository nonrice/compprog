#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(2*n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
        a[i+n] = a[i];
    }
    
    int d = find(a.begin(), a.end(), 1) - a.begin();
    if (d == 2*n || count(a.begin(), a.end(), 1) > 2){
        cout << "NO\n";
        return;
    }

    for (int i=1; i<n; ++i){
        if (a[i+d]-1 > a[i+d-1]){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
