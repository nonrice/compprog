#include <bits/stdc++.h>
using namespace std;

int n;
long long a[500000];
int p[500000];
long long d[500001];

void dfs(int i, int t){
	if (i != p[i]){
		t += (p[i]-i+n)%n;
		d[t] += -(a[i]-a[p[i]]);
		dfs(p[i], t);
	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	cin >> n;
	int r = 0;
	for (int i=0; i<n; ++i){
		cin >> a[i];
		if (a[i] <= a[r]){
			r = i;
		}
	}

	p[r] = r;
	stack<int> s({ r });
	for (int i=r-1; i!=r; i = (i-1+n)%n){
		while (a[s.top()] > a[i]){
			s.pop();
		}
		p[i] = s.top();
		s.push(i);
	}
	
	for (int i=0; i<n; ++i){
		dfs(i, 0);
	}

	long long m = accumulate(a, a+n, 0LL);
	for (int i=1; i<=n; ++i){
		m += d[i];
		cout << m << '\n';
	}
}
