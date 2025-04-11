template <typename T>
struct BIT {
	vector<T> s;
	int n;
 
	// construct empty tree for array of size n
	BIT(int n) : n(n) {
		s.resize(n+1);
	}
 
	// compute sum on range [0, r)
	T query(int r){
		T ans = 0;
		while (r >= 0){
			ans += s[r];
			r = (r & (r+1)) - 1;
		}
		return ans;
	}
	
	// compute sum on range [l, r)
	T query(int l, int r){
		return query(r) - query(l);
	}
 
	// increment index i by d
	void inc(int i, T d){
		i += 1;
		while (i <= n){
			s[i] += d;
			i |= i+1;
		}
	}
};
 
