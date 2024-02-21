#include <bits/stdc++.h>
using namespace std;

int n;
long long x[200001];
long long p[200001], s[200002];

struct query {
	int i;
	long long a, b;
	long long ans = LLONG_MAX;
	int ans_i = 1234;

	bool operator<(const query& o) const {
		return b*o.a < o.b*a;
	}

	void comp_ans(int l, int r){
		for (int i=l; i<=r; ++i){
			long long cur = a*(i*x[i] - p[i]) + b*(s[i] - (n-i+1)*x[i]);
			if (cur < ans){
				ans = cur;
				ans_i = i;
			}
		}
	}
};

query q[200000];

void qans(int l, int r){
	if (r-l <= 1){
		return;
	}
	int m = (r+l)/2;
	//cout << m << ' ';
	q[m].comp_ans(q[l].ans_i, q[r].ans_i);
	//cout << q[l].ans_i << ' ' << l << ' ' << q[r].ans_i << ' ' << r << ' ' << q[m].ans_i << '\n';
	qans(l, m);
	qans(m, r);
}

long long ans[200000];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i=1; i<=n; ++i) cin >> x[i];
	sort(x+1, x+n+1);

	for (int i=1; i<=n; ++i) p[i] = p[i-1] + x[i];
	for (int i=n; i>=1; --i) s[i] = s[i+1] + x[i];

	int no_q; cin >> no_q;
	for (int i=0; i<no_q; ++i){
		q[i].i = i;
		cin >> q[i].a >> q[i].b;
	}
	sort(q, q+no_q);

	q[0].comp_ans(1, n);
	q[no_q-1].comp_ans(1, n);
	qans(0, no_q-1);
	for (int i=0; i<no_q; ++i){
		ans[q[i].i] = q[i].ans;
	}

	for (int i=0; i<no_q; ++i) cout << ans[i] << '\n';
}
