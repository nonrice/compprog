// batchRURQ 
// batchRURQ: Construct batching RURQ data structure of size n and batch size b
// query: Compute sum on interval [l, r] in O(b)
// add: Add x to interval [l, r] in amortized O(n(q/b)) for q queries
// flush: Internal function to immediately apply changes of batched queries and clear the batch in O(n+b)

struct batchRURQ {
	struct update {
		int l, r;
		long long x;
	};

	int n, b;
	vector<long long> p;
	vector<long long> d;
	vector<update> c;

	batchRURQ(int n, int b) : n(n), b(b){
		p.resize(n+1);
		d.resize(n+2);
	}

	long long query(int l, int r){
		long long ans = p[r+1]-p[l];
		for (auto [ql, qr, x] : c){
			ans += x * max(0, qr-ql+1 + r-l+1 - (max(r, qr)-min(l, ql)+1));
		}
		return ans;
	}

	void add(int l, int r, long long x){
		c.push_back({ l, r, x });
		if (c.size() == b){
			flush();
		}
	}

	void flush(){
		fill(d.begin(), d.end(), 0);
		for (auto [l, r, x] : c){
			d[l+1] += x;
			d[r+2] -= x;
		}
		c.clear();
		for (int i=1; i<=n; ++i){
			d[i] += d[i-1];
		}
		for (int i=1; i<=n; ++i){
			d[i] += d[i-1];
			p[i] += d[i];
		}
	}
};
