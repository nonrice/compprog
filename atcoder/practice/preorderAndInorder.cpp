#include <bits/stdc++.h>
using namespace std;

int b[200000];
int mp[200001], rmp[200001];
int p[200001];
int ans[200000][2];

bool gen(int l, int m, int r){
    //cout << "g(" << l << ", " << m << ", " << r << ")\n";

    int p1 = p[b[m]+1], p2 = p[b[m] + m-l + 1];
    if (p1<l || p1>m-1) p1 = -1;
    if (p2<m+1 || p2>r) p2 = -1;
    //cout << "p1=" << p1 << " p2=" << p2 << '\n';

    if ((l != m && p1 == -1) || (r != m && p2 == -1)) return false;

    ans[b[m]][0] = (p1 != -1) ? b[p1] : 0; 
    ans[b[m]][1] = (p2 != -1) ? b[p2] : 0; 
    
    bool res = true;
    if (l != m) res = res && gen(l, p1, m-1);
    if (r != m) res = res && gen(m+1, p2, r);
    return res;
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    for (int i=0; i<n; ++i){
        int v; cin >> v;
        mp[v] = i + 1;
        rmp[i + 1] = v;
    }
    for (int i=0; i<n; ++i){
        cin >> b[i];
        b[i] = mp[b[i]];
        p[b[i]] = i;
    }

    if (!gen(0, find(b, b+n, mp[1])-b, n-1)){
        cout << "-1\n";
    } else {
        for (int i=1; i<=n; ++i) cout << rmp[ans[mp[i]][0]] << ' ' << rmp[ans[mp[i]][1]] << '\n';
    }
}
