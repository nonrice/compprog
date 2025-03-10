#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    long long a, b, c, d; cin >> a >> b >> c >> d;

    long long ans = 0;
    while (min(c, d) > 0){

        if (c == a){
            if (b > d){
                cout << "-1\n";
                return;
            } else if () {
                
            }
        }

    }

    cout << "-1\n";

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}