#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, H, M; cin >> n >> H >> M;
    vector<pair<int, int>> t(n);
    for (auto& v : t){
        cin >> v.first >> v.second;
    }
    sort(t.rbegin(), t.rend());
        
    int bh=INT_MAX, bm=INT_MAX; 
    for (auto [h, m] : t){
        int nh, nm;
        if (h > H || (h==H && m >= M)){
            nh = h-H-(M>m);
            nm = abs((m-M+60)%60);
        } else {
            nh = 24-(H-h)-(M>m);
            nm = abs(m-M+60)%60;
        }
        if (nh < bh || (nh==bh && nm<bm)) {
            bh = nh;
            bm = nm;
        }
    }
    cout << bh << ' ' << bm << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
