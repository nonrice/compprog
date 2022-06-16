#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a, b; cin >> a >> b;

    int ans = INT_MAX;
    for (int i=0; i<=b; ++i){
        int diff = abs(b - ((a+i) | b));
        ans = min(
            ans,
            i + diff + (a+i != b) 
        );
    }
    
    int lim = b;
    int count = 0;
    while (lim){
        lim >>= 1;
        ++count;
    }
    lim = (1 << count) + a;
    //cout << "lim: " << lim << '\n';
    
    for (int i=0; i<=lim-b; ++i){
        int diff = abs((b+i) - (a | (b+i)));
        ans = min(
            ans,
            i + diff + 1 
        );
    }

    cout << ans << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
