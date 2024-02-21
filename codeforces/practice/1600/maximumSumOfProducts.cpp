#include <bits/stdc++.h>
using namespace std;

long long a[5000], b[5000];
long long p[5001][5001];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n; cin >> n;
	long long cur = 0;
	for (int i=0; i<n; ++i) cin >> a[i];
	for (int i=0; i<n; ++i){
		cin >> b[i];
		cur += a[i] * b[i];
	}

	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			p[i][j] = a[i] * b[j];
		}
	}

	long long d = 0;

	for (int i=0; i<n; ++i){
		long long o = 0, e = 0;
		for (int j=0; i+j<n && i-j>=0; ++j){
			o += p[i-j][i+j] + p[i+j][i-j] - p[i+j][i+j] - p[i-j][i-j];
			// trick :)
			e += p[i-j][i+j+1] + p[i+j+1][i-j] - p[i+j+1][i+j+1] - p[i-j][i-j];
			d = max(d, max(o, e));
		}
	}

	cout << cur + d << '\n';
}
