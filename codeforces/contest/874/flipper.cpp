#include <bits/stdc++.h>
using namespace std;

int a[2000];
int ans[2000];
int lmx[2000], cmx[2000];

void solve(){
	int n; cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];

	int mxi = 1;
	for (int i=1; i<n; ++i){
		if (a[i] > a[mxi]) mxi = i;
	}

	memcpy(ans, a+mxi, (n-mxi)*sizeof(int));
	memcpy(cmx, a, mxi*sizeof(int));
	memcpy(lmx, cmx, mxi*sizeof(int));
	rotate(cmx, cmx+mxi-1, cmx+mxi);

	bool larger = false;
	for (int j=0; j<mxi; ++j){
		if (cmx[j] < lmx[j]) break;
		if (cmx[j] > lmx[j]){
			larger = true;
			break;
		}
	}
	if (larger || mxi!=n-1){
		memcpy(lmx, cmx, mxi*sizeof(int));
	}
//	reverse(cmx, cmx+mxi);


	//3 1 4 2
	//3 1 2 4 
	//3 4 2 1
	/*
	cout << mxi << '\n';
	for (int i=0; i<n; ++i) cout << ans[i] << ' ';
	cout << '\n';
	for (int i=0; i<mxi; ++i) cout << lmx[i] << ' ';
	cout << '\n';
	for (int i=0; i<mxi; ++i) cout << cmx[i] << ' ';
	cout << '\n';
	*/
	
	


	for (int i=1; i<=mxi-1; ++i){
		rotate(cmx+i, cmx+mxi-1, cmx+mxi);

		bool larger = false;
		for (int j=0; j<mxi; ++j){
			if (cmx[j] < lmx[j]) break;
			if (cmx[j] > lmx[j]){
				larger = true;
				break;
			}
		}

		if (larger){
			memcpy(lmx, cmx, mxi*sizeof(int));
		}
	}

	for (int i=mxi; i<n; ++i){
		cout << a[i] << ' ';
	}
	for (int i=0; i<mxi; ++i) cout << lmx[i] << ' ';
	cout << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
