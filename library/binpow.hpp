// REQUIRES: M

long long binpow(long long a, long long b){
	long long ans = 1;
	while (b){
		if (b&1) ans = ans*a%M;
		a = a*a%M;
		b >>= 1;
	}
	return ans;
}

