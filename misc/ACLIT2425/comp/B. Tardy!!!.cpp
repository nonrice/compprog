#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    
    int k; cin >> k;
    int a, b, c, d; cin >> a >> b >> c >> d;

    int t = (a>k) + (b>k) + (c>k) + (d>k);

    if (t >= 2){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
