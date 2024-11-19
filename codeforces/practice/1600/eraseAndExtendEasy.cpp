#include <bits/stdc++.h>
using namespace std;

char c[5000][5001];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, k; cin >> n >> k;
	cin >> c[0];
	c[0][k] = '\0';

	int ans = 0;
	for (int i=0; i<n; ++i){
		memcpy(c[i], c[0], n);
		for (int j=0; j<k; ++j){
			c[i][j] = c[0][j%(n-i)];
		}
		if (strcmp(c[i], c[ans]) < 0) ans = i;
	}

	cout << c[ans] << '\n';
}
