#include <bits/stdc++.h>
using namespace std;

struct op {
    int t, y;
};

op a[200000] = { { 1, 0 } };

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    
    int n, k; cin >> n >> k;
    for (int i=1; i<=n; ++i) cin >> a[i].t >> a[i].y;

    long long ans = LLONG_MIN;
    long long sum = 0;
    multiset<int> g;
    for (int i=n; i>=0; --i){
        if (a[i].t == 1){
            ans = max(ans, a[i].y+sum);
            if (k == 0) break;
            --k;
            if (g.size() > k){
                sum += *g.rbegin();
                g.erase(--g.end());
            }
        } else {
            sum += a[i].y;
            if (k != 0 && a[i].y < 0){
                if (g.size() < k || a[i].y < *g.rbegin()){
                    if (g.size() == k){
                        sum += *g.rbegin();
                        g.erase(--g.end());
                    }
                    g.insert(a[i].y);
                    sum -= a[i].y;
                }
            }
        }
    }

    cout << ans << '\n';
}
