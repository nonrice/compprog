#include <bits/stdc++.h>
using namespace std;

bool dp[100001];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	
	vector<int> b;
	for (int i=1; i<=100000; ++i){
		int t = i;
		dp[i] = true;
		while (t != 0){
			if (t%10 > 1){
				dp[i] = false;
				break;
			}
			t /= 10;
		}
		if (dp[i]){
			b.push_back(i);
			continue;
		}

		for (int f : b){
			if (i%f == 0 && dp[i/f]){
				dp[i] = true;
				break;
			}
		}
	}

	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		if (dp[n]){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
