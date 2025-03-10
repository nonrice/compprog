#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int p=0, z=0, g=0;
    for (int i=0; i<n; ++i){
        cin >> a[i];
        if (a[i] > 0){
            ++p;
        } else if (a[i] == 0){
            ++z;
        } else {
            ++g;
        }
    }

    if (z >= 1 || g%2){
        cout << "0\n";
        return;
    }

    cout << "1\n1 0\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}