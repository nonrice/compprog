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
    vector<long long> a(2*n);
    set<long long> s;
    for (int i=0; i<2*n; ++i){
        cin >> a[i];
        s.insert(a[i]);
    }

    if (n == 1){
        cout << a[1] << ' ' << a[1]+a[0] << ' ' << a[0] << '\n';
        return;
    }

    sort(a.begin(), a.end());
    long long t = 0;
    for (int i=0; i<2*n; i+=2){
        t += a[i+1]-a[i];
    }

    if (s.count(t)){
        for (int r=0; r<3; ++r){
            for (int i=r; i+1+r<n; ++i){
                if (i%2){
                    t -= abs(a[i]-a[i-1]);
                    t -= abs(a[i+1]-a[i]);
                }
                swap(a[i], a[i+1]);
                if (i%2){
                    t += abs(a[i]-a[i-1]);
                    t += abs(a[i+1]-a[i]);
                }

                if (!s.count(t)){
                    break;
                }
            }
        }
    }
    reverse(a.begin(), a.end());
    
    cout << t << ' ';
    for (int i=0; i<2*n; ++i){
        cout  << a[i] << ' ';
    }
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
