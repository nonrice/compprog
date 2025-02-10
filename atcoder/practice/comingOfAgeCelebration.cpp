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

    priority_queue<int, vector<int>, greater<int>> w;
    for (int i=0; i<n; ++i){
        while (!w.empty() && w.top() < i){
            w.pop();
        }
        cout << max(0, a[i]+(int)w.size()-(n-i-1)) << ' ';
        w.push(i+a[i]+w.size());
    }
    cout << '\n';

}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t=1;
    while (t--){
        solve();
    }
}