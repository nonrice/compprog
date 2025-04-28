#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int q; cin >> q;

    long long y = 0;
    bool r = false;
    deque<int> a;
    int m = 0;
    long long t = 0;
    while (q--){
        int s; cin >> s;
        if (s == 1){
            if (!r){
                y += t - 1LL*a.back()*m;
                a.push_front(a.back());
                a.pop_back();
            } else {
                y += t - 1LL*a.front()*m;
                a.push_back(a.front());
                a.pop_front();
            }
        } else if (s == 2){
            y = t*(m+1) - y;
            r ^= true;
        } else {
            int k; cin >> k;
            ++m;
            y += 1LL*k*m;
            t += k;
            if (!r){
                a.push_back(k);
            } else {
                a.push_front(k);
            }
        }
        cout << y << '\n';
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
