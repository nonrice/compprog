// fast computation of a^b mod m
long long binpow(long long a, long long b, long long m){
    long long ans = 1;
    while (b){
        if (b&1) ans = ans*a%m;
        a = a*a%m;
        b >>= 1;
    }
    return ans;
}

constexpr int NCR_MAX = 1e6;
long long f[NCR_MAX+1] = { 1 }, fi[NCR_MAX+1] = { 1 };

// precompute factorials and inverse factorials modulo m up to NCR_MAX
void NCR_precomp(long long m){
    for (int i=1; i<=NCR_MAX; ++i){
        f[i] = f[i-1]*i%m;
        fi[i] = binpow(f[i], m-2, m);
    }
}

// compute n choose k modulo m
long long NCR(int n, int k, long long m){
    if (n<k){
        return 0;
    }
    return f[n]*fi[n-k]%m*fi[k]%m;
}
