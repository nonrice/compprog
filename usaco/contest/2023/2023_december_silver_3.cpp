#include <bits/stdc++.h>
using namespace std;

int a[100000];

void solve(){
    int n; cin >> n;
    for (int i=0; i<n; ++i) cin >> a[i];

    if (n%2 == 0){
        int mn1=INT_MAX, mn2=INT_MAX;
        int mnp1, mnp2;
        for (int i=0; i<n; ++i){
            if (i&1){
                if (a[i] < mn2){
                    mn2 = a[i];
                    mnp2 = i;
                }
            } else {
                if (a[i] < mn1){
                    mn1 = a[i];
                    mnp1 = i;
                }
            }
        }

        if (mn1 == mn2){
            if (mnp1 < mnp2) cout << "Farmer Nhoj\n";
            else cout << "Farmer John\n";
        } else {
            if (mn1 < mn2) cout << "Farmer Nhoj\n";
            else cout << "Farmer John\n";
        }
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    
    int cases; cin>> cases;
    while (cases--) solve();
}
