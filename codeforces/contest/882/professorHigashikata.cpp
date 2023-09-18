#include <bits/stdc++.h>
using namespace std;

struct segment {
	int l, r;
};

char s[200001];
segment b[200000];
set<int> ps;
int r[200000];
bool m[200000];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, k, q; cin >> n >> k >> q;

	cin >> s;
	for (int i=0; i<k; ++i){
		cin >> b[i].l >> b[i].r;
		--b[i].l; --b[i].r;
	}

	for (int i=0; i<n; ++i){
		r[i] = -1;
		ps.insert(i);
	}

	int r_no = 0;
	for (int i=0; i<k; ++i){
		while (true){
			auto cur = ps.lower_bound(b[i].l);
			if (cur == ps.end() || *cur > b[i].r){
				break;
			}
			int val = *cur;
			ps.erase(cur);
			r[val] = r_no++;
		}
	}

	int ones = 0;
	for (int i=0; i<n; ++i){
		if (s[i] == '1'){
			if (r[i] >= 0) m[r[i]] = true;
			++ones;
		}
	}

	for (int i=0; i<n; ++i) cout << r[i] << ' ';
	cout << '\n';

	int p = 0;
	while (p<n  && m[p]) ++p;


	while (q--){
		int x; cin >> x; --x;

		if (s[x] == '1'){
			s[x] = '0';
			if (r[x] >= 0) m[r[x]] = false;
			--ones;
			while (p>0 && (!m[p] || !m[p-1])) --p;
		} else {
			s[x] = '1';
			++ones;
			if (r[x] >= 0) m[r[x]] = true;
			while (p<n && m[p]) ++p;
		}

		cout << s<< '\n';
		for (int i=0; i<n; ++i) cout << m[i];
		cout << '\n';

		cout << ones - p << '\n';
	}
}
