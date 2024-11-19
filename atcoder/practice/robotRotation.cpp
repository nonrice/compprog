#include <bits/stdc++.h>
using namespace std;

long long ax[40], ay[40];

unsigned long long s(long long* a, long long x, int n){
	map<long long, unsigned long long> m;
	for (unsigned long long b = 0; b < (1ULL<<(n/2)); ++b){
		long long t = 0;
		for (int i=0; i<n/2; ++i){
			if ((1ULL<<i) & b){
				t += a[i];
			} else {
				t -= a[i];
			}
		}
		m[t] = b;
	}

	for (unsigned long long b = 0; b < (1ULL<<(n - n/2)); ++b){
		long long t = 0;
		for (int i=0; i<(n - n/2); ++i){
			if ((1ULL<<i) & b){
				t += a[i+n/2];
			} else {
				t -= a[i+n/2];
			}
		}
		if (m.count(x - t)){
			return m[x-t] | (b<<(n/2));
		}
	}

	return ULLONG_MAX;
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	long long n, x, y; cin >> n >> x >> y;
	for (int i=0; i<n; ++i){
		if (i % 2) cin >> ax[i/2];
		else cin >> ay[i/2];
	}

	unsigned long long ans_x = s(ax, x, n/2);
	unsigned long long ans_y = s(ay, y, (n+1)/2);

	if (ans_x == ULLONG_MAX || ans_y == ULLONG_MAX){
		cout << "No\n";
		return 0;
	}
	
	cout << "Yes\n";
	int d = 0;
	long long tx = 0, ty = 0;
	for (int i=0; i<n; ++i){
		if (i % 2){
			if (ans_x & (1ULL<<(i/2))){
				cout << (d == 1 ? 'R' : 'L');
				d = 0;
			} else {
				cout << (d == 3 ? 'R' : 'L');
				d = 2;
			}
		} else {
			if (ans_y & (1ULL<<(i/2))){
				cout << (d == 2 ? 'R' : 'L');
				d = 1;
			} else {
				cout << (d == 0 ? 'R' : 'L');
				d = 3;
			}
		}
	}
	cout << '\n';
}
