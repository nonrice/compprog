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

    int n, h; cin >> n >> h;
    int a, b; cin >> a >> b;
    vector<int> m(n);
    for (int i=0; i<n; ++i){
        cin >> m[i];
    }
    
    sort(m.begin(), m.end());
    debug(m);
    vector<int> d(n-1);
    for (int i=0; i+1<n; ++i){
        d[i] = m[i+1]-m[i];
    }
    //debug(m);
    debug(d);

    while (h--){
        for (int i=n-b-1; i>=n-a; --i){
            ++m[i];
        }
        sort(m.begin(), m.end());
        vector<int> d(n-1);
        for (int i=0; i+1<n; ++i){
            d[i] = m[i+1]-m[i];
        }
        //debug(m);
        debug(d);
    }


    
}
