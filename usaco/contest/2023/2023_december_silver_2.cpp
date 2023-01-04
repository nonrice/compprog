#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[301][301];
ll b[301];

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    for (int i=0; i<n; ++i){
        for (int j=i; j<n; ++j){
            cin >> a[i][j];
        }
    }
    
    vector<int> d({0});
    vector<bool> ns(n);
    for (int i=1; i<n; ++i){
        if (a[i-1][i]){
            d.push_back(i);
        } else {
            ns[i] = 1;
        }
    }
    
    b[d[1]] = a[0][d[1]];
    for (size_t i=2; i<d.size(); ++i){
        if ((a[d[i-2]][d[i]] == a[d[i-2]][d[i-1]] + a[d[i-1]][d[i]]) == abs(b[d[i-1]]) > abs(b[d[i-2]])){
            b[d[i]] = b[d[i-1]] + a[d[i-1]][d[i]];
        } else {
            b[d[i]] = b[d[i-1]] - a[d[i-1]][d[i]];
        }
    }

    for (int i=1; i<n; ++i){
        if (ns[i]){
            b[i] = b[i-1];
        }
    }

    ll mx = *max_element(b, b+n);
    ll mn = *min_element(b, b+n);
    ll del = 0;
    if (mx > 1000000000) del = 1000000000-mx;
    else if (mn < -1000000000) del = -1000000000-mn;
    
    for (int i=0; i<n; ++i){
        cout << b[i]+del;
        if (i != n-1) cout << ' ';
        assert(abs(b[i]+del) <= 1000000000);
    }
    cout << '\n';
}
