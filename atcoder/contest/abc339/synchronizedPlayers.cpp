#include <bits/stdc++.h>
using namespace std;

struct pos {
	int r1, c1, r2, c2, d;
};

char g[60][61];

pair<int, int> dc[] = { { -1, 0 }, { 0, 1 },  { 1, 0 }, { 0, -1 } };

bool vis[60][60][60][60];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n; cin >> n;
	pos p = { -1, -1, -1, -1, 0 };
	for (int r=0; r<n; ++r){
		cin >> g[r];
		for (int c=0; c<n; ++c){
			if (g[r][c] == 'P'){
				if (p.r1 == -1){
					p.r1 = r;
					p.c1 = c;
				} else {
					p.r2 = r;
					p.c2 = c;
				}
			}
		}
	}
	
	queue<pos> q;
	q.push(p);
	vis[p.r1][p.c1][p.r2][p.c2] = true;
	while (!q.empty()){
		auto [r1, c1, r2, c2, d] = q.front();
		q.pop();
		for (auto [dr, dc] : dc){
			int nr1=r1+dr, nc1=c1+dc, nr2=r2+dr, nc2=c2+dc;
			if (nr1<0 || nr1>=n){
				nr1 = r1;
			}
			if (nc1<0 || nc1>=n){
				nc1 = c1;
			}
			if (nr2<0 || nr2>=n){
				nr2 = r2;
			}
			if (nc2<0 || nc2>=n){
				nc2 = c2;
			}
			if (g[nr1][nc1] == '#'){
				nr1 = r1;
				nc1 = c1;
			}
			if (g[nr2][nc2] == '#'){
				nr2 = r2;
				nc2 = c2;
			}
			if (nr1==nr2 && nc1==nc2){
				cout << d+1 << '\n';
				return 0;
			}
			if (vis[nr1][nc1][nr2][nc2]){
				continue;
			}
			vis[nr1][nc1][nr2][nc2] = true;
			q.push({nr1, nc1, nr2, nc2, d+1});
		}
	}

	cout << "-1\n";
}
