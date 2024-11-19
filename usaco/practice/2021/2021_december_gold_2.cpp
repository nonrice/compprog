#include <bits/stdc++.h>
using namespace std;

int n;
int a[200000];
int p[200001];

int cnt(int t, int x){
	int l=0, r=n+1;

	int ans = 0;
	bool hi = false;
	for (int i=0; i<t; ++i){
		if (a[i] <= x && a[i] > l){
			l = a[i];
			if (hi){
				++ans;
			}
			hi = false;
		} else if (a[i] > x && a[i] < r){
			r = a[i];
			hi = true;
		}
	}

	return ans;
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i=0; i<n; ++i){
		cin >> a[i];
		p[a[i]] = i;
	}

	cout << "0\n";
	for (int x=1; x<n; ++x){
		cout << cnt(n, x) << '\n';
	}
	cout << "0\n";
}
