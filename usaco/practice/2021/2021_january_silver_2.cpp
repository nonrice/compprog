#include <bits/stdc++.h>
using namespace std;

int l[100001], r[100001];
char s[100001];

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, q; cin >> n >> q;
    cin >> s;

    bool p[26] = {};
    int cur = 0;
    for (int i=0; i<n; ++i){
        fill(p+s[i]-'A'+1, p+26, false);
        if (!p[s[i]-'A']){
            ++cur;
            p[s[i]-'A'] = true;
        }
        l[i+1] = cur;
    }

    cur = 0;
    memset(p, false, 26);
    for (int i=n-1; i>=0; --i){
        // I hate how this is repetitive but making this a function would involve juggling around pointers
        fill(p+s[i]-'A'+1, p+26, false);
        if (!p[s[i]-'A']){
            ++cur;
            p[s[i]-'A'] = true;
        }
        r[i] = cur;
    }
    
    /*
    for (int i=0; i<=n; ++i)cout << l[i] << ' ';
    cout << '\n';
    for (int i=0; i<=n; ++i) cout << r[i] << ' ';
    cout << '\n';
    */

    while (q--){
        int u, v; cin >> u >> v;
        cout << l[u-1] + r[v] << '\n';
    }
}
