#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

#ifndef LOCAL
    freopen("moop.in", "r", stdin);
    freopen("moop.out", "w", stdout);
#endif

    int n; cin >> n;
    map<int, pair<int, int>> r;
    for (int i=0; i<n; ++i){
        int x, y; cin >> x >> y;
        if (!r.count(x)) r[x] = {INT_MIN, INT_MAX};
        r[x].first = max(r[x].first, y);
        r[x].second= min(r[x].second, y);
    }

    int ans1=0, ans2=0;
    int mx=INT_MIN, mn=INT_MAX;
    for (auto [x, p] : r){
        if (p.first >= mx){
            mx = p.first;
            ++ans1;
        }
    }
    for (auto it=r.rbegin(); it!=r.rend(); ++it){
        if (it->second.second <= mn){
            mn = it->second.second;
            ++ans2;
        }
    }

    cout << abs(ans1-ans2)+1 << '\n';
}
