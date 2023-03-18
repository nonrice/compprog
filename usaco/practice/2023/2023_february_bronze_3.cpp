#include <bits/stdc++.h>
using namespace std;

long long gaps[99999];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	
	int n, k; cin >> n >> k;
	long long prev; cin >> prev;
	const long long first = prev;
	for (int i=1; i<n; ++i){
		long long cur; cin >> cur;
		gaps[i-1] = cur - prev - 1;
		prev = cur;
	}

	sort(gaps, gaps+n-1, greater<long long>());
	long long ans = prev - first + k + 1;
	for (int i=0; i<n-1; ++i){
		if (gaps[i] <= k) break;
		ans += k - gaps[i];
	}

	cout << ans << '\n';
}

