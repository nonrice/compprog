#include <bits/stdc++.h>
using namespace std;

// Wikipedia
int isqrt(unsigned int y){
	unsigned int L = 0;
	unsigned int M;
	unsigned int R = y + 1;

    while (L != R - 1)
    {
        M = (L + R) / 2;

		if (M * M <= y)
			L = M;
		else
			R = M;
	}

    return L;
}

map<int, int, greater<int>> f;

void solve(){
	f.clear();

	int n; cin >> n;
	for (int i=0; i<n*(n-1)/2; ++i){
		for (int j=i+1; j<n; ++j){
			int x; cin >> x;
			++f[x];
		}
	}

	f.erase(f.begin()->first);
	for (int cnt=1; cnt<=n; ++cnt){
		int pref = cnt;
		bool good = true;
		for (auto [k, v] : f){
			int sqrt_part = isqrt(pref*pref + 8*v);
			cout << sqrt_part << ' ';
			if (sqrt_part*sqrt_part != pref*pref + 8*v){
				good = false;
				break;
			}
			
			pref += (sqrt_part+pref)/2;
			cout << pref << '\n';
		}

		if (!good){
			cout << "nig";
			continue;
		}

		if (pref == n){
			for (int i=0; i<cnt; ++i) cout << f.begin()->second << ' ';
			for (auto [k, v] : f){
				int sqrt_part = isqrt(pref*pref + 8*v);
				for (int i=0; i<(pref-sqrt_part)/2; ++i){
					cout << k << ' ';
				}
			}
		}
	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
