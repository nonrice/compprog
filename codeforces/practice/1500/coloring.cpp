#include <bits/stdc++.h>
using namespace std;

int a[100000];

void solve(){
    int n, m, k; cin >> n >> m >> k;

    int limit = (n+k-1)/k;
    int rem = n%k;

    for (int i=0; i<m; ++i) cin >> a[i];

    for (int i=0; i<m; ++i){
        if (a[i] > limit){
            if (rem >= 2 && a[i]-1 == limit){
                rem -= 2;
            } else {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
