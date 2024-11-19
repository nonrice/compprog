#include <bits/stdc++.h>
using namespace std;

long long a[100000], t[100000];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, q; cin >> n >> q;
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}

	while (q--){
		memcpy(t, a, n*sizeof(long long));
		long long k; cin >> k;
		for (int p=60; p>=0; --p){
			long long w = 0;
			for (int i=0; i<n; ++i){
				//cout << bitset<80>(((LLONG_MAX>>p)<<p) & t[i]) << '\n';
				w += max(0LL, (((LLONG_MAX>>p)<<p) & ((t[i]<<(63-p))>>(63-p))) - t[i]);
				cout<<(((LLONG_MAX>>p)<<p) & t[i])-t[i] << '\n';
			}
			cout <<w << '\n';
			if (w <= k){
				k -= w;
				for (int i=0; i<n; ++i){
					t[i] += max(0LL, (((LLONG_MAX>>p)<<p) & t[i]) - t[i]);
				}
			}
		}
		
		cout << k << '\n';
		for (int i=0; i<n; ++i){
			cout << t[i] << ' ';
		}
		cout << '\n';

		long long ans = LLONG_MAX;
		for (int i=0; i<n; ++i){
			ans &= t[i];
		}
		cout << ans << '\n';
	}
}
