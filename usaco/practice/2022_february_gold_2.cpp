#include <bits/stdc++.h>
using namespace std;

long double binpow(long double a, int b){
	long double ans = 1;
	while (b){
		if (b&1) ans = ans*a;
		a = a*a;
		b >>= 1;
	}
	return ans;
}

long double P_a[1001];
long double b[1001][1001] = { { 1 } };
long double b_c[1001];

bool P_m(int t, int k){
	if (t == 0) return true;
	return 1-binpow(b_c[t], k) > 0.49;
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int T, K; cin >> T >> K;
	T -= 1;

	for (int n=1; n<=T; ++n){
		b[n][0] = b[n-1][0]/2;
		for (int k=1; k<=T; ++k){
			b[n][k] = (b[n-1][k-1] + b[n-1][k])/2;
		}
	}

	b_c[0] = b[T][0];
	P_a[0] = b[T][0];
	for (int t=1; t<=T; ++t){
		b_c[t] = b_c[t-1] + b[T][t];
		P_a[t] = b[T][t];
	}

	long double ans = 0;
	for (int k = K-1; k>=0; --k){
		long double P_mo = accumulate(P_a, P_a+T+1, (long double)(0));
		for (int t=0; t<=T; ++t){
			if (!P_m(t, k)){
				P_mo -= P_a[t];
				ans += P_a[t]*t;
			}
		}
		for (int t=0; t<=T; ++t){
			P_a[t] = P_mo*b[T][t];
		}
	}

	cout << ans+1 << '\n';
}
