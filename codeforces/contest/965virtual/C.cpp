#include <bits/stdc++.h>
using namespace std;

bool check(long long l, vector<long long>& a, long long m, const long long k){
	for (auto v : a){
		if (v >= m){
			
		}
	}
}

void solve(){
	int n, k; cin >> n >> k;
	vector<long long> a(n);
	vector<bool> b(a);
	for (auto& v : a){
		cin >> v;
		v *= 2;
	}
	for (auto& v : b){
		cin >> v;
	}
	
	long long mx_i = 0;
	for (int i=0; i<n; ++i){
		if (b[i] == 1 && a[i] > a[mx_i]){
			mx_i = i;
		}
	}
	
	long long med;
	if (n % 2){
		med = (a[n/2] + a[n/2])/2;
	} else {
		med = a[n/2];
	}

	long long ans1 = -INT_MAX;
	if (a[mx_i] > med){
		ans1 = med + a[mx_i];
	}

	for (i)
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
