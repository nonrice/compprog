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
    vector<long long> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    
    int i1=-1;
    for (int i=0; i<n; ++i){
        if (a[i]%2 && (i1==-1 || a[i]>a[i1])){
            i1 = i;
        }
    }
    int i2=-1;
    for (int i=0; i<n; ++i){
        if (a[i]%2==0 && (i2==-1 || a[i]>a[i2])){
            i2 = i;
        }
    }
    
    if (i1==-1){
        cout << a[i2] << '\n';
        return;
    }
    if (i2==-1){
        cout << a[i1] << '\n';
        return;
    }
    
    long long ans = a[i1] + a[i2];
    for (int i=0; i<n; ++i){
        if (i==i1 || i==i2){
            continue;
        }
        if (a[i]%2){
            ans += a[i]-1;
        } else {
            ans += a[i];
        }
    }
    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
