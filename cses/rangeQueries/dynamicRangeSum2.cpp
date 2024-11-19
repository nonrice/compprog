#include <bits/stdc++.h>
using namespace std;

long long t[200001];

template<typename T>
struct BIT {
	T* t;
	int n;
	
	BIT(T* t, int n) : t(t), n(n) {}

	T pref(int i){
		T ans = t[0];
		while (i != 0){
			ans = comb(ans, t[i]);
			i -= (i & -i);
		}
		return ans;
	}

	void add(int i, T d){
		if (i == 0){
			t[0] = comb(t[0], d);
			return;
		}
		while (i < n){
			t[i] = comb(t[i], d);
			i += (i & -i);
		}
	}

	virtual inline T comb(T a, T b) {
		return a + b;
	}
};

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, q; cin >> n >> q;

	BIT bit(t, 200001);

	for (int i=0; i<n; ++i){
		int x; cin >> x;
		bit.add(i+1, x);
	}

	while (q--){
		int a; cin >> a;
		if (a == 1){
			int k, u; cin >> k >> u;
			bit.add(k, u-(bit.pref(k)-bit.pref(k-1)));
		} else {
			int x, y; cin >> x >> y;
			cout << bit.pref(y) - bit.pref(x-1) << '\n';
		}
	}
}
