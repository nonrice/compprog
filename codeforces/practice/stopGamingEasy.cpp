#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    
    vector<int> a(n*m), b(n*m);
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            cin >> a[i*m + j];
        }
    }
    for (int i=0; i<n; ++i){
        for (int j=0; j<m; ++j){
            cin >> b[i*m + j];
        }
    }

    map<int, int> p;
    for (int i=0; i<n*m; ++i){
        p[b[i]] = i;
    }

    int s = 0;
    int r = 0;
    int c = 0;
    for (int i=0; i<n*m; ++i){
        if (i+s >= n*m){
            break;
        }
        if ((i+s)/m != r){
            r = (i+s)/m;
            c = 0;
        }
        if (!p.count(a[i]) || p[a[i]] < i+s || (i%m!=0 && i/m == (s+i)/m && p[a[i]] != i+s)){
            if (i%m==0 || i/m != (s+i)/m){
                s += n*m - (i+s);
            } else {
                s += n*m - (i+s)/m*m - c; 
            }
            break;
        } else {
            int d = p[a[i]] - (i+s);
            s += d;
            c += d;
        }
        //cout << s << ' ' << '|';
    }
    //cout << '\n';

    cout << s << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}
