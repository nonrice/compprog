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
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }

    vector<pair<int, int>> p(n);
    for (int i=0; i<n; ++i){
        p[i].first = a[i];
        p[i].second = i;
    }
    sort(p.rbegin(), p.rend());

    vector<int> s({ n });
    for (int i=0; i<n; ++i){
        if (p[i].second > s.back()){
            continue;
        }
        s.push_back(p[i].second);
    }
    reverse(s.begin(), s.end());
    debug(s);

    int p2 = s.size()-2;
    int mn = INT_MAX;
    vector<int> ms(s.size()-1);
    for (int i=n-1; i>=0; --i){
        mn = min(mn, a[i]);
        if (i == s[p2]){
            ms[p2] = mn;
            --p2;
        }
    }

    vector<int> t(s.size()-1);
    for (int i=0; i<t.size(); ++i){
        t[i] = a[s[i]];
    }

    for (int i=t.size()-1; i>=0; --i){
        auto it = lower_bound(ms.begin()+i, ms.end(), a[s[i]]);

        if (it == ms.begin()+i){
            continue;
        } else {
            t[i] = t[it-ms.begin()-1];
        }
    }

    p2 = 0;
    for (int i=0; i<n; ++i){
        if (i == s[p2+1]){
            ++p2;
        }
        cout << t[p2] << ' ';
    }
    cout << '\n';

    debug(ms);
    debug(t);

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}