#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    set<string> a;
    for (int i=0; i<n; ++i){
        string s; cin >> s;
        a.insert(s);
    }

    for (int i=0; i<m; ++i){
        string s; cin >> s;
        if (a.count(s)){
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
}
