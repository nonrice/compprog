#include <bits/stdc++.h>
using namespace std;

#define int long long

int a[200], b[200], c[200];
int tc[200];

int n, ct, mt;

bool bad = false;

int extra(int try_ct){
	int ans = 0;
	for (int i=0; i<n; ++i){
		int cur = try_ct*a[i] + mt*b[i];
		int req = (cur - c[i] + (b[i]-1))/b[i];
		if (req >= mt){
			bad = true;
			return INT_MAX - (ct-try_ct);
		}
		ans = max(ans, req);
	}

	bad = false;
	return ans + (ct - try_ct);
}

void solve(){
	cin >> n >> ct >> mt;
	for (int i=0; i<n; ++i) cin >> a[i] >> b[i] >> c[i];

	srand(time(NULL));

	int len = (int)sqrt(ct-1.0) + 1;
	vector<int> b(len);
	for (int i=1; i<=ct; i+=len){
		b[i / len] = extra(i + rand()%len);	
	}

	int mn = 0;

	for (int i=0; i<len; ++i){
		if (b[i] < b[mn]){
			mn = i;
		}
	}

	vector<int> to_search;
	for (int i=0; i<len; ++i){
		if (b[i] == b[mn]) to_search.push_back(i);
	}

	int ans = INT_MAX;
	for (int search : to_search){
		for (int i=0; i<len; ++i){
			ans = min(ans, extra(search*len + i));
		}
	}

	cout << ans << '\n';
}

signed main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
