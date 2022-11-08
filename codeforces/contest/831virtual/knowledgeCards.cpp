#include <bits/stdc++.h>
using namespace std;

int a[100000];
int p[100001];


void solve(){
    int n, m, k; cin >> n >> m >> k;
    for (int i=0; i<k; ++i) cin >> a[i];

    for (int i=0; i<k; ++i){
        p[a[i]] = i+1;
    }

    for (int i=k, rp=n*m-3; i>=1; --i, ++rp){
        if (p[i] > rp){
            cout << "TIDAK\n";
            return;
        }
    }

    cout << "YA\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
