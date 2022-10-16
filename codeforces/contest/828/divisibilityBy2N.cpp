#include <bits/stdc++.h>
using namespace std;

int get2s(int x){
    int ans = 0;
    while (!(x&1)){
        x >>= 1;
        ++ans;
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int& v : a) cin >> v;
    
    int twos = 0;
    for (int v : a){
        twos += get2s(v);
    }
    if (twos >= n){
        cout << "0\n";
        return;
    }
    
    vector<int> evn(n);
    for (int i=1; i<=n; ++i){
        evn[i-1] = get2s(i);
    }
    sort(evn.begin(), evn.end(), greater<int>());
    
    int ans = 0;
    for (int v : evn){
        ++ans;
        if (twos + v >= n){
            cout << ans << '\n';
            return;
        }
        twos += v;
    }

    cout << "-1\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
