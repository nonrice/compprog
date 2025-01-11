#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

constexpr char ch[] = "aeiou";

void solve(){
    int n; cin >> n;

    for (int r=0; r<5; ++r){
        for (int i=1; i<=(n/5)+(r < n%5); ++i){
            cout << ch[r];
        }
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