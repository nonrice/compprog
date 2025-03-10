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

    vector<int> a(n), b(n);
    int r0=0, r1=0;
    for (int i=0; i<n; ++i){
        cin >> a[i];
        if (a[i]%2){
            ++r1;
        } else {
            ++r0;
        }
    }
    int d0=0, d1=0;
    for (int i=0; i<n; ++i){
        cin >> b[i];
        if (b[i] != a[i]){
            if ((b[i]-a[i])%2){
                ++d1;
            } else {
                ++d0;
            }
        }
    }

    if (d0+d1 == 0){
        cout << "YES\n";
        return;
    }

    if (r0%2 == 0 && r1%2 == 0){
        if (d1==0){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else if (r0%2==1 && r1%2==1){
        if (d1==1){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else if (r0%2==0 && r1%2==1){
        if (d1<=1){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else if (r0%2==1 && r1%2==0){
        cout << "NO\n";
    }

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}