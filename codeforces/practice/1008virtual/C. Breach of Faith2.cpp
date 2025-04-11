#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
    if (n == 2){
        sort(a.begin(), a.end());
        cout << a[3] << ' ' << a[1] << ' ' << a[0] << ' '<< a[3]-(a[1]-a[0])+a[2] << ' ' << a[2] << '\n';
        return;
    }
 
    auto chk = [&](){
        long long t = 0;
        for (int i=0; i<2*n; ++i){
            if (i%2){
                t -= a[i];
            } else {
                t += a[i];
            }
        }
        if (t >= 1 && !s.count(t)){
            return t;
        }
        return -1LL;
    };
    while (chk() == -1){
        shuffle(a.begin(), a.end(), rng);
    }
 
    cout << chk() << ' ';
    for (int i=0; i<2*n; ++i){
        cout << a[i] << ' ';
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
