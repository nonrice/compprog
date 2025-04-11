#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, q; cin >> n >> q;
    string s; cin >> s;

    vector<vector<int>> f(26, vector<int>(n, n));
    f[s[n-1]-'a'][n-1] = n-1;
    for (int i=n-2; i>=0; --i){
        for (int j=0; j<26; ++j){
            f[j][i] = f[j][i+1];
        }
        f[s[i]-'a'][i] = i;
    }
    vector<vector<int>> g(26, vector<int>(n, -1));
    g[s[0]-'a'][0] = 0;
    for (int i=1; i<n; ++i){
        for (int j=0; j<26; ++j){
            g[j][i] = g[j][i-1];
        }
        g[s[i]-'a'][i] = i;
    }
    
    while (q--){
        int l, r; cin >> l >> r;
        --l, --r;
    
        long long ans = -1;
        for (int c1=0; c1<26; ++c1){
            for (int c2=0; c2<26; ++c2){
                if (c1 == c2){
                    continue;
                }

                int i1 = f[c1][l];
                int i2 = g[c2][r];

                if (i1 > r || i2 < l || i2<i1){
                    continue;
                }

                int i3 = f[c2][(i1+i2)/2];
                int i4 = g[c2][(i1+i2)/2];
                if (i3<i2 && i3>i1){
                    ans = max(ans, 1LL*(i2-i3)*(i3-i1));
                }
                if (i4<i2 && i4>i1){
                    ans = max(ans, 1LL*(i2-i4)*(i4-i1));
                }
            }
        }

        cout << ans << '\n';
    }
}
