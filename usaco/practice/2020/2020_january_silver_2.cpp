#include <bits/stdc++.h>
using namespace std;

long long n, m, k;

long long check(long long r, long long x){
	long long y = r/x;
	if (y <= m){
		return (r + m-1)/m;
	}
	long long d = 1 + (r-y*x)/y;
	return d + check(r - y*d, x);
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
#ifndef LOCAL
	freopen("loan.in", "r", stdin);
	freopen("loan.out", "w", stdout);
#endif

	cin >> n >> k >> m;
	long long cur = 1;
	for (long long s = n; s >= 1; s/=2){
		while (check(n, cur + s) <= k){
			cur += s;
		}
	}
	cout << cur << '\n';
}
