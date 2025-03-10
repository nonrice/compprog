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

    pair<int, int> a({ 5, 6 });

    vector<int> r(26, -1);
    for (int i=n-1; i>=0; --i){
        if (r[s[i]-'a'] == -1){
            r[s[i]-'a'] = i;
        }
    }

    int c = 25;
    vector<int> u;
    for (int i=0; i<n; ++i){
        while (c>=0 && i>r[c]){
            --c;
        }
        if (c == -1){
            break;
        }
        if (s[i] == 'a'+c){
            u.push_back(i);
        }
    }

    int p = 0;
    while (p<u.size() && s[u[p]]==s[u[0]]){
        ++p;
    }

    for (int i=0; u.size()-i-1>i; ++i){
        swap(s[u[i]], s[u[u.size()-1-i]]);
    }

    for (int i=1; i<n; ++i){
        if (s[i] < s[i-1]){
            cout << "-1\n";
            return;
        }
    }


    cout << u.size()-p << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
