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
    freopen("output.txt", "r", stdin);

    int t; cin >> t;
    assert(t==1);
    int n; cin >> n;
    assert(n==200000);
    vector<int> a(n);
    for (int i=0; i<n; ++i){
        cin >> a[i];
    }
    assert(a[n-1] != 0);
    cout << a[n-1] << ' ' << a[n-2] << ' ';
}
