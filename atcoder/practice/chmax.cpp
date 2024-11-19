#include <bits/stdc++.h>
using namespace std;

constexpr long long M = 998244353;

int a[200001];
map<int, int> c;
vector<int> T;

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for (int i=1; i<=n; ++i){
		cin >> a[i];
	}

	for (int i=n; i>=1; --i){
		if (a[i] < i || (c.count(a[i]) == 0 && a[i]!=i)){
			cout << "0\n";
			return 0;
		}
		c[a[i]] = i;
	}
	long long ans = 1;
	for (auto [h, t] : c){
		T.push_back(t);
	}
	sort(T.begin(), T.end());
	int p = 0;
	int i = 0;
	for (auto [h, t] : c){
		while (p<T.size() && T[p]<=h){
			++p;
		}
		ans = (ans * (p-i)) % M;
		++i;
	}

	cout << ans << '\n';
}
