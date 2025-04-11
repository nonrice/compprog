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

    int p=0;
    while (p+1<n && abs(a[p]) < 2){
        ++p;
    }

    auto max_subarr = [&](int l, int r){
        int cur = 0;
        int ans = 0;
        for (int i=l; i<=r; ++i){
            cur = max(0, cur+a[i]);
            ans = max(ans, cur);
        }
        return ans;
    };

    auto min_subarr = [&](int l, int r){
        int cur = 0;
        int ans = 0;
        for (int i=l; i<=r; ++i){
            cur = min(0, cur+a[i]);
            ans = min(ans, cur);
        }
        return ans;
    };

    set<int> ans;
    int ub1 = max_subarr(0, p-1);
    for (int x=min_subarr(0, p-1); x<=ub1; ++x){
        ans.insert(x);
    }
    int ub2 = max_subarr(p+1, n-1);
    for (int x=min_subarr(p+1, n-1); x<=ub2; ++x){
        ans.insert(x);
    }

    int mxr=0, mnr=0;
    int curr = 0;
    for (int i=p+1; i<n; ++i){
        curr += a[i];
        mxr = max(mxr, curr);
        mnr = min(mnr, curr);
    }
    int mxl=0, mnl=0;
    int curl = 0;
    for (int i=p-1; i>=0; --i){
        curl += a[i];
        mxl = max(mxl, curl);
        mnl = min(mnl, curl);
    }

    for (int x=mnl+mnr+a[p]; x<=mxl+mxr+a[p]; ++x){
        ans.insert(x);
    }

    cout << ans.size() << '\n';
    for (auto x : ans){
        cout << x << ' ';
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
