#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n; cin >> n;

    ll total = 0;
    ll c1=0, b1=0, c2=0, b2=0;
    int x, y; cin >> y;
    for (int i=0; i<n-1; ++i){
        swap(x, y);
        cin >> y;
        if (i%2){
            c2 = max(0LL, c2+x-y);
            b2 = max(c2, b2);
        } else {
            total += x;
            c1 = max(0LL, c1+y-x);
            b1 = max(c1, b1);
        }
    }
    
    cout << total + (n%2)*y + max(b1, b2) << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
