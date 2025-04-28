long long isqrt(long long n){
    long long y = 0;
    for (int s=n; s>=1; s/=2){
        while ((y+s)*(y+s) <= n){
            y += s;
        }
    }
    return y;
}
