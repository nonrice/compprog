#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll p[1001][1001];
pair<int, int> a[100000];

void solve(){
    int n, q; cin >> n >> q;

    int mx_h=0, mx_w=0;
    for (int i=0; i<n; ++i){
        cin >> a[i].first >> a[i].second;
        mx_h = max(a[i].first, mx_h);
        mx_w = max(a[i].second, mx_w);
    }

    sort(a, a+n);
    int cur = 0;
    for (int r=0; r<=mx_h; ++r){
        for (int c=0; c<=mx_w; ++c){
            if (r && c){
                p[r][c] = p[r-1][c] + p[r][c-1] - p[r-1][c-1];
                while (cur<n && a[cur].first==r && a[cur].second==c){
                    p[r][c] += a[cur].first * a[cur].second;
                    ++cur;
                }
            } else p[r][c] = 0;
        }
    }
    
    while (q--){
        int hn, wn, hx, wx; cin >> hn >> wn >> hx >> wx;
        hx = min(--hx, mx_h);
        wx = min(--wx, mx_w);
        hn = min(hn, mx_h);
        wn = min(wn, mx_w);
        cout << p[hx][wx] - p[hn][wx] - p[hx][wn] + p[hn][wn] << '\n';
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
