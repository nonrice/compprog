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
    long long k; cin >> k;
    --k;

    deque<int> p({ n });
    for (int i=n-1; i>=1; --i){
        if (k&1){
            p.push_back(i);
        } else {
            p.push_front(i);
        }
        k >>= 1;
    }
    
    if (k){
        cout << "-1\n";
        return;
    }

    while (!p.empty()){
        cout << p.front() << ' ';
        p.pop_front();
    }
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}