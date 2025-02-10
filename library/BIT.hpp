template <typename T>
struct BIT {
	vector<T> s;
	int n;

	// construct empty tree for array of size n
	BIT(int n) : n(n) {
		s.resize(n+1);
	}

	// compute sum on range [0, r)
	T sum(int r){
		T ans = 0;
		while (r >= 0){
			ans += s[r];
			r = (r & (r+1)) - 1;
		}
		return ans;
	}
	
	// compute sum on range [l, r)
	T sum(int l, int r){
		return sum(r) - sum(l);
	}

	// increment index i by d
	void inc(int i, T d){
		while (i < n){
			s[i] += d;
			i |= i+1;
		}
	}
};
