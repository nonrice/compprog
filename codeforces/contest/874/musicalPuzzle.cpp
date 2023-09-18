#include <bits/stdc++.h>
using namespace std;

// abcd 
//
// ab bc cd
//

char a[51];

void solve(){
	int n; cin >> n;
	cin >> a;


	set<int> ms;
	for (int i=0; i<n-1; ++i){
		if (ms.count(a[i] + a[i+1]*257) == 0){
			ms.insert(a[i] + a[i+1]*257);
		}
	}

	cout << ms.size() << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
