#include <bits/stdc++.h>
using namespace std;

#define int __int128_t 

constexpr int M = 264575131106459;
constexpr int B = 43;
int binpow(int a, int b){
	int ans = 1;
	while (b){
		if (b&1) ans = ans*a%M;
		a = a*a%M;
		b >>= 1;
	}
	return ans;
}



char s[1001];
char p[1001];

int ph[1001];
int sstr(int i, int j){
	return (ph[j+1] - ph[i]+M)%M * binpow(binpow(B, i), M-2) % M;
}

map<int32_t, pair<int32_t, int32_t>> l;

void solve(){
	cin >> s >> p;
	int n = strlen(s), m = strlen(p);

	//prefix hash of s into ph
	int pw = 1;
	for (int i=1; i<=n; ++i){
		ph[i] = (ph[i-1] + pw*(s[i-1]-96)%M) % M;
		pw = pw*B%M;
	}
	
	//hash of p as t
	int t = 0;
	pw = 1;
	for (int i=0; i<m; ++i){
		t = (t + pw*(p[i]-96)%M) % M;
		pw = pw*B%M;
	}

	for (int i=n-1; i>=0; --i){
		for (int j=i; j>=0; --j){
			l[sstr(j, i)] = { j, i };
		}
	}
//0123456789101112131415
//surgeryonas t r i n g
//surgerystri n g
//
//
//
/*

	cout << sstr(0, 6) << ' ' << sstr(10, 15) << '\n';

	cout << (sstr(0, 6) + sstr(10, 15)*binpow(B, 7)%M) % M << '\n';
	cout << t << '\n';
	cout << (t-sstr(10, 15)*binpow(B, 7)%M+M) % M << ' ' << sstr(0, 6) << '\n';
	*/


	for (int32_t i=0; i<n; ++i){
		for (int32_t j=i; j<n; ++j){
			if (m-(j-i+1) >= 0){
				int c = (t - sstr(i, j)*binpow(B, m-(j-i+1))%M + M) % M;
				if (l.count(c) && l[c].second < i){
					cout << l[c].first << ' ' << l[c].second-l[c].first+1 << ' ' << i << ' ' << j-i+1 << '\n';
					return;
				}
				c = (t - sstr(i, j) + M) % M;
				c = c*binpow(binpow(B, j-i+1), M-2)%M;
				if (l.count(c) && l[c].second < i){
					cout << i << ' ' << j-i+1 << ' ' << l[c].first << ' ' << l[c].second-l[c].first+1 << '\n';
					return;
				}
			}
		}
	}
	cout << "IMPOSSIBLE\n";
}

signed main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int32_t t; cin >> t;
	while (t--) solve();
}
