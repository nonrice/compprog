#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    long long t = 0;
    for (int i=0; i<n; ++i){
        cin >> a[i];
        t += a[i];
    }   

    vector<long long> p(n+1);
    for (int i=0; i<n; ++i){
        p[i+1] += p[i]+a[i];
    }

    auto chk = [&](long long x){
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> t;
        t.emplace(0, 0);
        long long s;
        for (int i=1; i<=n+1; ++i){
            while (!t.empty() && p[i-1]-p[t.top().second] > x){
                t.pop();
            }
            
            if (t.empty()){
                return false;
            }
            debug(t.top(), i);
            s = t.top().first+a[i-1];
            t.emplace(s, i);
        }

        return s<=x;
    };


    debug(p);
    debug(chk(5));



    long long x = t;
    for (long long s=t; s>=1; s/=2){
        while (chk(x-s)){
            x -= s;
        }
    }

    cout << x << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}