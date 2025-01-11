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
    vector<int> p(n);
    for (int i=0; i<n; ++i){
        cin >> p[i];
        --p[i];
    }

    vector<int> q(n);
    for (int i=0; i<n; ++i){
        q[p[i]] = i;
    }

    for (int i=0; i<n; ++i){
        if (q[i] == i){
            continue;
        } else if (q[i] == i+1){
            if (abs(p[i]-p[i+1]) == 1){
                swap(q[p[i]], q[p[i+1]]);
                swap(p[i], p[i+1]);
            } else {
                cout << "NO\n";
                return;
            }
        } else if (q[i] == i+2){
            if (abs(p[i]-p[i+2]) == 1 && abs(p[i+1]-p[i+2]) == 1){
                swap(q[p[i+1]], q[p[i+2]]);
                swap(p[i+1], p[i+2]);
                swap(q[p[i]], q[p[i+1]]);
                swap(p[i], p[i+1]);
            } else {
                cout << "NO\n";
                return;
            }
        } else {
            cout << "NO\n";
            return;
        }
    }
    debug(p);
    debug(q);
    cout << "YES\n";

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}