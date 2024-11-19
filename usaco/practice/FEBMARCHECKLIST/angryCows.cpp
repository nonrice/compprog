#include <bits/stdc++.h>
using namespace std;

int dp_r[50000], dp_l[50000];
int a[50000];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
#ifndef LOCAL
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
#endif

	int n; cin >> n;
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}

	sort(a, a+n);
	int o = n-1;
	for (int i=n-2; i>=0; --i){
		int r_1 = max(a[i+1]-a[i], dp_r[i+1]+1);
		int r_2 = max(a[o]-a[i], dp_r[o]+1);
		if (r_1 <= r_2){
			o = i+1;
			dp_r[i] = r_1;
		} else {
			dp_r[i] = r_2;
		}
	}
	o = 0;
	for (int i=1; i<n; ++i){
		int r_1 = max(a[i]-a[i-1], dp_l[i-1]+1);
		int r_2 = max(a[i]-a[o], dp_l[o]+1);
		if (r_1 <= r_2){
			o = i-1;
			dp_l[i] = r_1;
		} else {
			dp_l[i] = r_2;
		}
	}

	int p = INT_MAX;
	for (int i=0; i<n; ++i){
		for (int j=i; j<n; ++j){
			p = min(p, max(a[j]-a[i], 2*max(dp_l[i]+1, dp_r[j]+1)));
		}
	}
	cout << (p/2) << '.' << (p%2 ? '5' : '0') << '\n';
}
