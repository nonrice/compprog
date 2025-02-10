#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

#define INTERACTIVE

int ask(int x){
    cout << "- " << x << endl;
    int h; cin >> h;
    if (h == -1){
        exit(0);
    }
    return h;
}

void solve(){
    int h; cin >> h;

    int ans = 0;
    int i=0;
    while (h > i){

        int h2 = ask(1<<i);
        if (h2 < h){
            ans += 1<<i;
            h = h2;
            if (h <= i){
                break;
            }
            h2 = ask(1<<i);
        }
        i += h2 - h + 1;
        h = h2;
        ans += 1<<i;
    }

    cout << "! " << ans << endl;
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}