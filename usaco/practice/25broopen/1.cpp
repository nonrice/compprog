#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<string> t(n);
    for (int i=0; i<n; ++i){
        cin >> t[i];
    }

    while (m--){
        int l, r; cin >> l >> r;
        --l, --r;

        int w = 0;
        for (int i=0; i<n; ++i){
            bool bl = (i<l && t[l][i]=='L') || (i>l && t[i][l]=='W');
            bool br = (i<r && t[r][i]=='L') || (i>r && t[i][r]=='W');
            if (bl && br){
                ++w;
            }
        }

        cout << 2*w*n - w*w << '\n';
    }
}
