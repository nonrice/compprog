#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n ; cin >> n;
    vector<int> b(n-2);
    for (int i=0; i<n-2; ++i){
        cin >> b[i];
    }

    for (int i=0; i+2<b.size(); ++i){
        if (b[i] == 1 && b[i+1] == 0 && b[i+2] == 1){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}

