#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll check(vector<int>& h, int t){
    ll e=0, o=0;
    for (int v : h){
        e += (t-v) / 2;
        o += (t-v) % 2;
    }
    
    ll x = max(0LL, (e-o)/3 + ((e-o)%3 > 1));
    e -= x;
    o += 2*x;

    return max(e, o)*2 - (o>e);
}

void solve(){
    int n; cin >> n;
    vector<int> h(n);
    int gre = 0;
    for (int& v : h){
        cin >> v;
        gre = max(gre, v);
    }

    cout << min(check(h, gre), check(h, gre+1)) << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
