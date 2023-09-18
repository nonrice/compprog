#include <bits/stdc++.h>
using namespace std;

bool ans[1000001];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	
	for (int b=2; b<1000; ++b){
		long long bp = b*b*b;
		while ((bp-1) / (b-1) <= 1000000){
			ans[(bp-1) / (b-1)] = true;
			bp *= b;
		}
	}

	int n; cin >> n;
	while (n--){
		int x; cin >>x;
		if (ans[x]) cout << "YES\n";
		else cout<< "NO\n";
	}

}
