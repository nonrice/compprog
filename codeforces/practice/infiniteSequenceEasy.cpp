#include <bits/stdc++.h>
using namespace std;

vector<bool> a;
int n;
bool s;
bool f(long long x){
    if (x <= n){
        return a[x];
    }

    if (x/2 <= n){
        bool t = 0;
        for (int i=1; i<=x/2; ++i){
            t ^= a[i];
        }
        return t;
    }   

    if (x/2 > n && x/2%2){
        return s;
    }

    return f(x/2)^s;
}

void solve(){
    cin >> n;
    long long l, r; cin >> l >> r;
    a = vector<bool>(n+1);
    s = 0;
    for (int i=1; i<=n; ++i){
        char c; cin >> c;
        a[i] = (c == '1');
        s ^= a[i];
    }

    if (n%2==0){
        bool t = 0;
        for (int i=1; i<=(n+1)/2; ++i){
            t ^= a[i];
        }
        s ^= t;
        a.push_back(t);
        ++n;
    }

    cout << f(l) << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
