#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int& v : a) cin >> v;
    
    int ans = 0;
    vector<bool> done(n+1);
    int start = -1;
    for (int i=n-2; i>=0; --i){
        if (done[a[i]]) a[i] = 0;
        if (a[i] > a[i+1]){
            if (start == -1) start = i+1;
            done[a[i]] = true;
            a[i] = 0;
            ++ans;
        }
    }
    
    if (start >= 0){
        for (; start<n; ++start){
            if (a[start] == 0 || done[a[start]]){
                for (int i=start-1; a[i]!=0; --i){
                    ans += !done[a[i]];
                    done[a[i]] = true;
                }
            }

        }
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
