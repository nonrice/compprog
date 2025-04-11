#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, d; cin >> n >> d;

    cout << "1 ";

    if (d%3==0 || n>=3){
        cout << "3 ";
    }

    if (d == 5){
        cout << "5 ";
    }

    if (n>=3 || d==7){
        cout << "7 ";
    }

    if ((d==9) || (n>=3 && d%3==0) || (n>=6)){
        cout << "9 ";
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
