#include <bits/stdc++.h>
using namespace std;

int c[1<<17];

bool cmp(int a, int b){
    cout << "? " << a << ' ' << b << endl;
    int r; cin >> r;
    if (r == -1) exit(1);
    return r==1;
}

void solve(){
    int n; cin >> n;

    n = 1<<n;
    
    iota(c, c+n, 1);
    sort(c, c+n, cmp); // needs merge-insertion sort to AC
    cout << "! " << c[0] << endl;
}

int main(){
    //cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}

