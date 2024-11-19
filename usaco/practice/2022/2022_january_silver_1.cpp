#include <bits/stdc++.h>
using namespace std;

inline long long f(long long a, long long b){
    long long k = 0;
    while ((a<<1) <= b){
        a <<= 1;
        ++k;
    }
    long long r = b - a;
    return k + r/(1<<k) + ((k>0) ? __builtin_popcount(r%(1<<k)) : 0);
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    while (n--){
        long long a, b; cin >> a >> b;

        int d = 0;
        long long ans = LLONG_MAX;
        while (1){
            if (a <= b) ans = min(ans, d + f(a, b));

            if (a == 1) break;
            if (a&1) ++a, ++d;
            a >>= 1;
            ++d;
        }

        cout << ans << '\n';
    }
}
