#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector<long long> h(n+1);
	for (int i=1; i<=n; ++i){
		cin >> h[i];
	}

	h[0] = INT_MAX;
	vector<long long> dp(n+1);
	stack<int> s({ 0 });
	for (int i=1; i<=n; ++i){
		while (h[s.top()] < h[i]){
			s.pop();
		}
		dp[i] = dp[s.top()] + h[i]*(i-s.top());
		s.push(i);
		cout << dp[i]+1 << ' ';
	}
	cout << '\n';
}
