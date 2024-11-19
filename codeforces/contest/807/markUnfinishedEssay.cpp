#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct seg {
    ll b;
    ll e;
    ll d;

    seg(ll b, ll e, ll d){
        this->b = b;
        this->e = e;
        this->d = d;
    }
};

void solve(){
    int n, c, q; cin >> n >> c >> q;
    string s; cin >> s;
    
    ll end = n-1;
    vector<seg> segs;
    while (c--){
        ll b, e; cin >> b >> e;
        --b; --e;
        segs.emplace_back(end+1, end+e-b+1, end+1-b);
        end += e-b+1;
    }

    while (q--){
        ll i; cin >> i; --i;
        while (i >= n){
            for (auto [b, e, d] : segs){
                if (i>=b && i<=e){
                    i -= d;
                    break;
                }
            }
        }

        cout << s[i] << '\n';
    }
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
