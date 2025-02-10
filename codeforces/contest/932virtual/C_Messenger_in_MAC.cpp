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
    long long l; cin >> l;

    map<int, vector<int>> g;
    for (int i=0; i<n; ++i){
        int x, y; cin >> x >> y;
        g[y].push_back(x);
    } 
    
    int ans = 0;
    for (auto ti = g.begin(); ti!=g.end(); ++ti){
        multiset<int> s;
        long long t = 0;
        auto p = s.end();
        int d = 0;
        for (auto tj(ti); tj != g.end(); ++tj){
            bool b = false;
            while (t + tj->first-ti->first > l){
                if (p == s.begin()){
                    b = true;
                    break;
                }
                --p;
                --d;
                t -= *p;
            }
            if (b){
                break;
            }
            for (int x : tj->second){
                s.insert(x);
                if (p != s.end() && x == *p){
                    ++p;
                }
                if (p==s.end() || x<=*p){
                    if (t+x + tj->first-ti->first <= l){
                        t += x;
                        ++d;
                    } else {
                        t -= *prev(p);
                        t += x;
                        --p;
                    }
                } 
            }

            debug(*ti, *tj);
            debug(s, d);
            if (p != s.end()){
                debug(*p);
            }

            ans = max(ans, d);

        }
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}