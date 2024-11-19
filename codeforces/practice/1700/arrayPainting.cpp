#include <bits/stdc++.h>
using namespace std;

int a[200000];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n; cin >> n;
	int b = n;
	for (int i=0; i<n; ++i) cin >> a[i];

	int c = 0;
	for (int i=0; i<n; ++i){
		if (a[i] > 0){
			++c;
			int r = n;
			int s = 1;
			for (int j=i; j<n; ++j){
				if (a[j] == 2){
					s = 2;
				} else if (a[j] == 0){
					r = j;
					break;
				}
			}
			
			b -= r-i;
			if (i>0 && a[i-1]==0){
				--s;
				--b;
			}
			if (r<n && s>0){
				a[r] = 1;
				--b;
			}
			
			i = r;
		}
	}

	cout << b+c << '\n';
}
