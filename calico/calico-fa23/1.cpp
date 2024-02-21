#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	if (n == 0){
		cout << "haha good one\n";
	} else if (n>=10 && n<=170){
		for (; n>=1; n-=10){
			cout << "berkeley";
		}
		cout << "time\n";
	} else {
		cout << "canceled\n";
	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
