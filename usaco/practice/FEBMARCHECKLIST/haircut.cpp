#include <bits/stdc++.h>
using namespace std;

struct BIT {
	vector<int> s;
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

vector<int> p[100001];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
#ifndef LOCAL
	freopen("haircut.in", "r", stdin);
	freopen("haircut.out", "w", stdout);
#endif

	int n; cin >> n;
	for (int i=0; i<n; ++i){
		int h; cin >> h;
		p[h].push_back(i);
	}

	BIT t(n);
	for (int i=0; i<n; ++i){
		t.inc(i, 1);
	}
	long long ans = 0;
	cout << "0\n";
	for (int k=0; k<n-1; ++k){
		for (int i : p[k]){
			t.inc(i, -1);
			ans += t.sum(i);
		}
		cout << ans << '\n';
	}
}
