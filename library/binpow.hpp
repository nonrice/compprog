// Binary Exponentation
// binpow: Computes a^b (mod m) in O(log(b)).

long long binpow(long long a, long long b, long long m){
	long long ans = 1;
	while (b){
		if (b&1) ans = ans*a%m;
		a = a*a%m;
		b >>= 1;
	}
	return ans;
}

