struct polyhash {
	long long m, b;
	vector<long long> p;
	
	// Construct prefix hash of s with modulus m and base b
	polyhash(const string& s, long long m, long long b) : m(m), b(b) {
		p = vector<long long>(s.size()+1);
		long long bp = 1;
		for (size_t i=1; i<=s.size(); ++i){
			p[i] = (p[i-1] + (s[i-1]-'a') * bp % m) % m;
			bp = bp*b % m;
		}
	}
	
	// hash substring on [l, r)
	long long substr(int l, int r){
		return ((p[r] - p[l] + m) % m) * binpow(binpow(b, l, m), m-2, m) % m;
	}
};


