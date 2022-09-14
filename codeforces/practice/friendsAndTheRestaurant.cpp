#include <bits/stdc++.h>
using namespace std;

int xy[2][100000];
int p[100000], m[100000];

void solve(){
    int n; cin >> n;
    for (int i=0; i<n; ++i) cin >> xy[0][i];
    for (int i=0; i<n; ++i) cin >> xy[1][i];
    
    int neg=0, pos=0;
    for (int i=0; i<n; ++i){
        int dif = xy[1][i] - xy[0][i];
        if (dif < 0) m[neg++] = dif;
        else p[pos++] = dif;
    }
    
    sort(p, p+pos);
    sort(m, m+neg, greater<int>());
    
    // for (int i=0; i<pos; ++i) cout << p[i] << ' ';
    // cout << '\n';
    // for (int i=0; i<neg; ++i) cout << m[i] << ' ';
    // cout << '\n';
    
    int ans = 0;
    --neg, --pos;
    while (neg>=0 && pos>=0){
        if (m[neg] + p[pos] < 0) --neg;
        else {
            --neg, --pos;
            ++ans;
        }
    }
    
    ans += (pos+1)/2;
    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
