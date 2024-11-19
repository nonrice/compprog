#include <bits/stdc++.h>
using namespace std;

int a[100000];

int r[100001];

bool v[100001];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
#ifndef LOCAL
	freopen("art2.in", "r", stdin);
	freopen("art2.out", "w", stdout);
#endif

	int n; cin >> n;
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}

	for (int i=0; i<n; ++i){
		r[a[i]] = i;
	}

	int ans = 0;
	stack<int> s;
	for (int i=0; i<n; ++i){
		if (a[i] != 0){
			if (!v[a[i]]){
				s.push(a[i]);
				ans = max(ans, (int)s.size());
				v[a[i]] = true;
			}
			if (i == r[a[i]]){
				if (s.top() != a[i]){
					cout << "-1\n";
					return 0;
				}
				s.pop();
			}
		}
	}

	cout << ans << '\n';
}
