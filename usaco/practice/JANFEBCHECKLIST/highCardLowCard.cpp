#include <bits/stdc++.h>
using namespace std;

char A[100000];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
#ifndef LOCAL
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);
#endif

	int n; cin >> n;
	fill(A, A+2*n, 'U');
	for (int i=0; 2*i<n; ++i){
		int a; cin >> a;
		A[a-1] = 'R';
	}
	priority_queue<int, vector<int>, greater<>> l;
	for (int i=0; 2*i<n; ++i){
		int a; cin >> a;
		l.push(a-1);
		A[a-1] = 'L';
	}

	int ans = 0;
	int r = 0;
	for (int i=0; i<2*n; ++i){
		if (A[i] == 'U'){
			if (!l.empty()){
				A[l.top()] = 'X';
				l.pop();
				++ans;
			} else if (r > 0){
				++ans;
				--r;
			}
		} else if (A[i] == 'L'){
			l.pop();
		} else if (A[i] == 'R'){
			++r;
		}
	}

	cout << ans << '\n';
}
