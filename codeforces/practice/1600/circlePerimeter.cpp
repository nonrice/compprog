#include <bits/stdc++.h>
using namespace std;

void solve(){
	long long r; cin >> r;
	
	long long ans = 0;
	for (long long x=0; x<=r; ++x){
		long long y1 = r;
		long long y2 = 0;
		for (int s = r; s>=1; s/=2){
			while (y1-s >= 0 && x*x + (y1-s)*(y1-s) >= r*r){
				y1 -= s;
			}
			while (x*x + (y2+s)*(y2+s) < (r+1)*(r+1)){
				y2 += s;
			}
		}
		ans += y2-y1+1;
	}
	ans = ans*4 - 4;
	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
