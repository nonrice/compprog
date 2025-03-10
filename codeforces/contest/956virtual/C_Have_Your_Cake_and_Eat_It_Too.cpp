#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    int n; cin >> n;
    vector<long long> a(n), b(n), c(n);
    long long t = 0;
    for (int i=0; i<n; ++i){
        cin >> a[i];
        t += a[i];
    }
    for (int i=0; i<n; ++i){
        cin >> b[i];
    }
    for (int i=0; i<n; ++i){
        cin >> c[i];
    }

    int a1=0, a2=n-1, b1=0, b2=n-1, c1=0, c2=n-1;
    {
        long long s = 0;
        while (a1<n && s*3 < t){
            s += a[a1];
            ++a1;
        }
        if (s*3<t){
            cout << "-1\n";
            return;
        }
        --a1;
    }
    {
        long long s = 0;
        while (a2>=0 && s*3 < t){
            s += a[a2];
            --a2;
        }
        if (s*3<t){
            cout << "-1\n";
            return;
        }
        ++a2;
    }
    {
        long long s = 0;
        while (b1<n && s*3 < t){
            s += b[b1];
            ++b1;
        }
        if (s*3<t){
            cout << "-1\n";
            return;
        }
        --b1;
    }
    {
        long long s = 0;
        while (b2>=0 && s*3 < t){
            s += b[b2];
            --b2;
        }
        if (s*3<t){
            cout << "-1\n";
            return;
        }
        ++b2;
    }
    {
        long long s = 0;
        while (c1<n && s*3 < t){
            s += c[c1];
            ++c1;
        }
        if (s*3<t){
            cout << "-1\n";
            return;
        }
        --c1;
    }
    {
        long long s = 0;
        while (c2>=0 && s*3 < t){
            s += c[c2];
            --c2;
        }
        if (s*3<t){
            cout << "-1\n";
            return;
        }
        ++c2;
    }
    debug(a1, a2, b1, b2, c1, c2);

    long long sa=0, sb=0, sc=0;
    int la = 0, lb = 0, lc = 0;
    for (int r=0; r<n; ++r){
        sa += a[r];
        while ((sa - a[la])*3 >= t){
            sa -= a[la];
            ++la;
        }
        sb += b[r];
        while ((sb - b[lb])*3 >= t){
            sb -= b[lb];
            ++lb;
        }
        sc += c[r];
        while ((sc - c[lc])*3 >= t){
            sc -= c[lc];
            ++lc;
        }
        
        if (la > b1 && r < c2 && b1 < c2 && (sa*3>=t)){
            cout << la+1 << ' ' << r+1 << ' ' << 1 << ' ' << b1+1 << ' ' << c2+1 << ' ' << n << '\n';
            debug("here");
            return;
        } else if (la > c1 && r < b2 && c1 < b2 && (sa*3>=t)){
            cout << la+1 << ' ' << r+1 << ' ' << b2+1 << ' ' << n << ' ' << 1 << ' ' << c1+1 << '\n';
            return;
        } else if (lb > a1 && r < c2 && a1 < c2 && (sb*3>=t)){
            cout << 1 << ' ' << a1+1 << ' ' << lb+1 << ' ' << r+1 << ' ' << c2+1 << ' ' << n << '\n';
            return;
        } else if (lb > c1 && r < a2 && c1 < a2 && (sb*3>=t)){
            cout << a2+1 << ' ' << n << ' ' << lb+1 << ' ' << r+1 << ' ' << 1 << ' ' << c1+1 << '\n';
            return;
        } else if (lc > a1 && r < b2 && a1 < b2 && (sc*3>=t)) {
            cout << 1 << ' ' << a1+1 << ' ' << b2+1 << ' ' << n << ' ' << lc+1 << ' ' << r+1 << '\n';
            return;
        } else if (lc > b1 && r < a2 && b1 < a2 && (sc*3>=t)){
            cout << a2+1 << ' ' << n << ' ' << 1 << ' ' << b1+1 << ' ' << lc+1 << ' ' << r+1 << '\n';
            return;
        }
    }

    cout << "-1\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}