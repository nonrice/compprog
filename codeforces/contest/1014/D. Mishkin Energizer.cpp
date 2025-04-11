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
    string s; cin >> s;

    list<char> a;
    map<char, int> c;
    for (int i=0; i<n; ++i){
        a.push_back(s[i]);
        ++c[s[i]];
    }
    
    vector<int> ans;
    while (c['L'] != c['I'] || c['I'] != c['T']){
        if (ans.size() > 2*n){
            cout << "-1\n";
            return;
        }

        int i=0;
        bool p = false;
        for (auto it = a.begin(); next(it) != a.end(); ++it, ++i){
            if (*it == *next(it)){
                continue;
            }
            for (auto ch : { 'L', 'I', 'T' }){
                if (ch != *it && ch != *next(it) && c[ch] < max(max(c['L'], c['I']), c['T'])){
                    a.insert(next(it), ch);
                    ans.push_back(i+1);
                    ++c[ch];
                    p = true;
                    break;
                }
            }
            if (p){
                break;
            }
        }
        
        i=0;
        if (!p){
            for (auto it = a.begin(); next(it) != a.end(); ++it, ++i){
                if (*it == *next(it)){
                    continue;
                }
                for (auto ch : { 'L', 'I', 'T' }){
                    if (ch != *it && ch != *next(it)){
                        a.insert(next(it), ch);
                        ans.push_back(i+1);
                        ++c[ch];
                        p = true;
                        break;
                    }
                }
                if (p){
                    break;
                }
            }
        }

        if (!p){
            cout << "-1\n";
            return;
        }
        debug(a);
    }

    cout << ans.size() << '\n';
    for (auto i : ans){
        cout << i << '\n';
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
