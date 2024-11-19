#include <bits/stdc++.h>
using namespace std;

inline uint32_t g(uint32_t x){
	return x ^ (x >> 1);
}

void dbg(uint32_t x){
	for (uint32_t m=(1<<18); m>=1; m>>=1){
		cout << (bool)(x&m);
	}
	cout << '\n';
}

char s[19];
uint32_t a[100000];
bool f[(1<<18) + 1]; // does team defined by i exist?
int ans[(1<<18) + 1]; // answer for team defined by i

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	
	int c, n; cin >> c >> n;
	uint32_t opt = 0;
	for (int i=0; i<n; ++i){
		cin >> s;
		for (int j=0; j<c; ++j){
			if (s[j] == 'H'){
				a[i] |= 1;
			}
			a[i] <<= 1;
		}
		f[a[i]] = true;
		if (__builtin_popcount(a[i]) > __builtin_popcount(opt)){
			opt = a[i];
		}
	}
	
	ans[0] = __builtin_popcount(opt);
	int prev = ans[0];
	for (uint32_t i=1; i<=(1<<c); ++i){
		//dbg(g(i));
		int cur = __builtin_popcount(g(i) ^ opt);

		if (cur < prev){
			for (uint32_t m=1; m<=(1<<c); m<<=1){
				if (f[opt|m] && __builtin_popcount(g(i) ^ (opt|m)) == prev){
					opt |= m;
					cur = prev;
					break;
				}
			}
		}

		cout << cur-prev << '\n';

		ans[g(i)] = cur;
		prev = cur;
	}

	for (int i=0; i<n; ++i){
		cout << ans[a[i]] << '\n';
	}
}
