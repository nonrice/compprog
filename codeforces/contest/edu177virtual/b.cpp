#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    long long x; cin >> x;
    vector<long long> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    long long s = accumulate(a.begin(), a.end(), 0LL);
    long long t = s*k;

    vector<long long> p(n);
    for (int i=1; i<n; ++i){
        p[i] = p[i-1] + a[i-1];
    }

    long long z = -1;
    for (long long h = 1LL*n*k; h>=1; h/=2){
        while (z+h<n*k && t - s*((z+h)/n) - p[(z+h)%n] >= x){
            z += h;
        }
    }

    cout << z+1 << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
