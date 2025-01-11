#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n, m; cin >> n >> m;
    long long v; cin >> v;

    vector<long long> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    vector<pair<int, long long>> p(n+1);
    for (int i=1; i<=n; ++i){
        if (a[i-1] + p[i-1].second >= v){
            p[i].first = p[i-1].first+1;
        } else {
            p[i].first = p[i-1].first;
            p[i].second = p[i-1].second + a[i-1];
        }
    }
    vector<pair<int, long long>> s(n+1);
    for (int i=n-1; i>=0; --i){
        if (a[i] + s[i+1].second >= v){
            s[i].first = s[i+1].first+1;
        } else {
            s[i].first = s[i+1].first;
            s[i].second = s[i+1].second + a[i];
        }
    }

    vector<long long> pp(n+1);
    for (int i=1; i<=n; ++i){
        pp[i] = pp[i-1] + a[i-1];
    }

    long long ans = -1;
    for (int i=0; i<n; ++i){
        long long t = 0;


        int j=i;
        for (int st=n-i; st>=1; st/=2){
            while (j+st<=n && p[i].first + s[j+st].first >= m){
                j += st;
            }
        }

        if (p[i].first + s[j].first >= m){
            ans = max(ans, pp[j]-pp[i]);
        }

    }

    debug(p);
    debug(s);

    cout << ans << '\n';

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}