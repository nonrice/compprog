#include <bits/stdc++.h>
using namespace std;
 
struct op {
	int t;
	unsigned long long v;
};
 
op o[100000];
unsigned long long c[100000];
 
void solve(){
	int n, q; cin >> n >> q;
	for (int i=0; i<n; ++i) cin >> o[i].t >> o[i].v;
	
	for (int i=0; i<n; ++i){
		if (o[i].t == 1){
			c[i] = (i==0) ? 1 : c[i-1]+1;
		} else {
			c[i] = c[i-1]*(o[i].v+1);
			if (c[i] / c[i-1] != o[i].v+1){
				cerr << "wee woo\n";
				n = i;
				break;
			}
		}
	}
 
	while (q--){
		long long k; cin >> k;
		int i = lower_bound(c, c+n, k) - c;
 
		while (o[i].t == 2){
			k = (k-1) % c[i-1] + 1;
			i = lower_bound(c, c+n, k) - c;
		}
 
		cout << o[i].v << ' ';
	}
	cout << '\n';
}
 
int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
