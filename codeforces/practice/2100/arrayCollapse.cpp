#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

constexpr long long M = 998244353;

inline long long ms(long long a, long long b){
	return (a-b)%M + (b>a ? M : 0);
}

struct SQRTRURQ {
	struct update {
		int l, r;
		long long x;
	};

	int n;
	size_t b;
	vector<long long> p;
	vector<long long> d;
	vector<update> c;

	SQRTRURQ(int n) : n(n) {
		p.resize(n+1);
		d.resize(n+2);
		b = sqrt(n); 
	}

	long long query(int l, int r){
		long long ans = ms(p[r+1], p[l]);
		for (auto [ql, qr, x] : c){
			ans = (ans + x * max(0, qr-ql+1 + r-l+1 - (max(r, qr)-min(l, ql)+1)) % M) % M;
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
			d[l+1] = (d[l+1] + x) % M;
			d[r+2] = ms(d[r+2], x);
		}
		c.clear();
		for (int i=1; i<=n; ++i){
			d[i] = (d[i]+d[i-1]) % M;
		}
		for (int i=1; i<=n; ++i){
			d[i] = (d[i]+d[i-1]) % M;
			p[i] = (p[i]+d[i]) % M;
		}
	}
};

int n;
int a[300002], l[300002], r[300002];

void solve(){
	cin >> n;
	for (int i=1; i<=n; ++i) cin >> a[i];
	a[0] = a[n+1] = INT_MAX;

	{
		stack<pair<int, int>> st;
		st.emplace(0, -1);
		for (int i=0; i<=n+1; ++i){
			while (st.top().first > a[i]){
				st.pop();
			}
			l[i] = st.top().second;
			st.emplace(a[i], i);
		}
	}
	{
		stack<pair<int, int>> st;
		st.emplace(0, n+2);
		for (int i=n+1; i>=0; --i){
			while (st.top().first > a[i]){
				st.pop();
			}
			r[i] = st.top().second;
			st.emplace(a[i], i);
		}
	}

	SQRTRURQ dp(n+2);
	dp.add(0, 0, 1);
	for (int i=1; i<=n+1; ++i){
		if (l[i]+1 != i){
			dp.add(i, i, dp.query(l[i]+1, i-1));
		}
		if (r[i]-1 != i){
			dp.add(i+1, r[i]-1, dp.query(i, i));
		}
	}

	cout << dp.query(n+1, n+1) << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
