// Binary Indexed Tree
// BIT: Construct binary indexed tree for array of size n in O(n).
// sum 1: Compute sum on range [1, r] in O(log(r)).
// sum 2: Compute sum from on range [l, r] in O(log(r)).
// inc: Increment element i of the array by d in O(log(i)).

struct BIT {
	vector<long long> s;
	int n;

	BIT(int n) : n(n) {
		s.resize(n+1);
	}

	long long sum(int r){
		long long ans = 0;
		while (r >= 0){
			ans += s[r];
			r = (r & (r+1)) - 1;
		}
		return ans;
	}

	long long sum(int l, int r){
		return sum(r) - sum(l-1);
	}

	void inc(int i, int d){
		while (i < n){
			s[i] += d;
			i |= i+1;
		}
	}
};
