#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,lzcnt,popcnt,bmi,bmi2")

#include <bits/stdc++.h>
using namespace std;

long long h[2000];
struct frac {
	long long a, b;

	frac(long long a=0, long long b=1) : a(a), b(b) {}

	bool operator>=(const frac& o) const {
		return a*o.b >= o.a*b;
	}

	bool operator>(const frac& o) const {
		return a*o.b > o.a*b;
	}
};
map<int, frac> m[2000];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for (int i=0; i<n; ++i){
		cin >> h[i];
	}

	int ans = 0;
	for (int i=0; i<n; ++i){
		frac mx;
		for (int j=i+1; j<n; ++j){
			frac cur = frac(h[j]-h[i], j-i);
			if (j==i+1 || cur >= mx){
				++ans;
				mx = cur;
				m[i][j] = cur;
			}
		}
	}

	int q; cin >> q;
	while (q--){
		int i, y; cin >> i >> y; --i;

		h[i] += y;
		ans -= m[i].size();
		m[i].clear();

		frac mx;
		for (int j=i+1; j<n; ++j){
			frac cur = frac(h[j]-h[i], j-i);
			if (j==i+1 || cur >= mx){
				++ans;
				mx = cur;
				m[i][j] = cur;
			}
		}

		for (int j=0; j<i; ++j){
			auto it = m[j].upper_bound(i);
			frac cur = frac(h[i]-h[j], i-j);
			bool v = false;
			if (it == m[j].begin()){
				m[j][i] = cur;
				++ans;
				v = true;
			} else if (cur >= (--it)->second){
				if (i==it->first){
					if (cur>it->second){
						it->second = cur;
						v = true;
					}
				} else {
					m[j][i] = cur;
					++ans;
					v = true;
				}
			}
			if (v){
				it = m[j].upper_bound(i);
				while (it != m[j].end() && m[j][i]>it->second){
					it = m[j].erase(it);
					--ans;
				}
			}
		}

		cout << ans << '\n';
	}
}
