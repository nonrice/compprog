#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    const int n = s.size();

    int ans = 0;
    int z = 0;
    bool in_seg = (s[0] == '0');
    for (int i=0; i<n; ++i){
        if (s[i] == '0') {
            ++z;
            ans += !in_seg;
            in_seg = true;
        } else if (s[i] == '1' && in_seg) {
            int total = 0;
            for (int j=i; j<n && total <= j-i+1+z; ++j){
                total = (total<<1) + (s[j]=='1');
                if (total != 2)
                    ans += (total <= j-i+1+z);
            }
            z = 0;
            in_seg = false;
        } else if (s[i] == '1' && !in_seg) {
            ++ans;
        }
    }

    cout << ans << '\n';
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
