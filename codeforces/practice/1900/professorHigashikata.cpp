#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200000;

char s[N+1];
int p[N];
set<int> t;
bitset<N> b;

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, m, q; cin >> n >> m >> q >> s;
	for (int i=0; i<n; ++i){
		t.insert(i);
	}
	int cur = 0;
	for (int i=0; i<m; ++i){
		int l, r; cin >> l >> r; --l, --r;
		auto it_l = t.lower_bound(l), it_r = t.upper_bound(r);
		for (auto it = it_l; it != it_r; ++it){
			p[*it] = cur++;
		}
		t.erase(it_l, it_r);
	}
	int e = cur;
	while (!t.empty()){
		int i = *t.begin();
		p[i] = cur++;
		t.erase(t.begin());
	}

	for (int i=0; i<n; ++i){
		b[p[i]] = (s[i]=='1');
	}
	int cnt = b.count();
	while (q--){
		int x; cin >> x; --x;
		cnt += 1-(2*b[p[x]]);
		b.flip(p[x]);
		cout << min(e, cnt)-(b<<(N-min(e, cnt))).count() << '\n';
	}
}
