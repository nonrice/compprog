#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n, p, q, r; cin >> n >> p >> q >> r;
    vector<ll> maxpre(n), maxsuf(n), minpre(n), minsuf(n), a(n);
    for (ll& v : a)
        cin >> v;
    
    maxpre.front() = a.front();
    maxsuf.back() = a.back();
    minpre.front() = a.front();
    minsuf.back() = a.back();
    for (int i=1; i<n; ++i){
        maxpre[i] = max(a[i], maxpre[i-1]);
        minpre[i] = min(a[i], minpre[i-1]);
        maxsuf[n-i-1] = max(a[n-i-1], maxsuf[n-i]);
        minsuf[n-i-1] = min(a[n-i-1], minsuf[n-i]);
    }

    vector<ll>& f = (p<0) ? minpre : maxpre;
    vector<ll>& b = (r<0) ? minsuf : maxsuf;
    ll best = numeric_limits<long long>::min();
    for (int i=0; i<n; ++i){
        best = max(best, p*f[i] + q*a[i] + r*b[i]);
    }
    cout << best << '\n';
}

