#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

unsigned long long dp[501][500*(500+1)/4 + 100];

int main(){
	int n; cin >> n;

	if (n*(n+1)/2 % 2){
		cout << "0\n";
		return 0;
	}
	
	dp[0][0] = 1;

	const int mx = n*(n+1)/4;
	for (int m=1; m<=n; ++m){
		for (int w=0; w<=mx; ++w){
			dp[m][w] = (dp[m][w] + dp[m-1][w]) % MOD;
			if (w >= m) dp[m][w] = (dp[m][w] + dp[m-1][w-m]) % MOD;
		}
	}

	cout << (dp[n][mx]*500000004 % MOD) << '\n';
}
