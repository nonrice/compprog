#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int& v : a) cin >> v;

    ll sum = accumulate(a.begin(), a.end()-1, 0LL);

    vector<int>::iterator start = a.end()-1;
    for (auto it=a.begin(); it!=a.end(); ++it){
        if (*it) {
            start = it;
            break;
        }
    }

    cout << sum + count(start, a.end()-1, 0) << '\n';

}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
