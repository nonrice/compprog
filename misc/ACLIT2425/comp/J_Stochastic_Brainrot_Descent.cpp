#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,avx,sse4,sse2,sse,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAXN 2000069
long long taha[MAXN];
long long tahap[MAXN];
long long tahapinv[MAXN];
long long inv(long long base) {
    long long ans = 1;
    long long exp = MOD-2;
    while (exp) {
        if (exp & 1) {
            ans = ans*base%MOD;
        }
        base = base*base%MOD;

        exp >>= 1;
    }
    return ans;
}

int main() {
    cin.tie(0)->ios_base::sync_with_stdio(false);
    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            taha[j] += i;
            taha[j] %= MOD;
        }
    }
    tahap[1] = 1;
    tahapinv[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        tahap[i] = taha[i]*tahap[i-1];
        tahap[i] %= MOD;
        tahapinv[i] = inv(tahap[i]);
    }
    long long q;
    cin >> q;
    for (int i=0; i<q; ++i){
        long long l, r;
        cin >> l >> r;
        cout << tahap[r]*tahapinv[l-1]%MOD << '\n';
    }
}