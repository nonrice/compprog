#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

constexpr int X = 1000000;
constexpr int XC = 15630;
constexpr int P = 10000;

struct BS {
	uint64_t a[XC] = {};

	void set(){
		for (int i=0; i<XC; ++i){
			a[i] = ULLONG_MAX;
		}
	}

	void assign(BS& o){
		for (int i=0; i<XC; ++i){
			a[i] = o.a[i];
		}
	}

	void intersect(BS& o){
		for (int i=0; i<XC; ++i){
			a[i] &= o.a[i];
		}
	}
	
	void unset(uint32_t x){
		a[x>>6] &= (~(1ULL<<(x & 0b111111)));
	}

	void set(uint32_t x){
		a[x>>6] |= (1ULL<<(x & 0b111111));
	}

	bool get(uint32_t x){
		return a[x>>6] & (1ULL<<(x & 0b111111));
	}

	int MSB(){
		for (int i=XC-1; i>=0; --i){
			if (a[i] != 0){
				return 64*i + (64-__builtin_clzll(a[i]));
			}
		}
		return 1;
	}
};


set<int> pf[X+1];
int pm[X+1];
BS m[P];
BS s;

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int p = 0;
	for (int i=2; i<=X; ++i){
		if (pf[i].empty()){
			pm[i] = p++;
			for (int x=i; x<=X; x+=i){
				pf[x].insert(i);
			}
		}
	}

	for (int i=0; i<P; ++i){
		m[i].set();
	}
	int ans = 0;
	int n; cin >> n;
	while (n--){
		int t, x; cin >> t >> x;
		if (t == 1){
			s.set(x);
			for (int f : pf[x]){
				m[pm[f]].unset(x);
			}
		} else {
			BS c;
			c.assign(s);
			for (int f : pf[x]){
				c.intersect(m[pm[f]]);
			}
			ans ^= c.MSB()-1;
		}
	}

	cout << ans << '\n';
}

