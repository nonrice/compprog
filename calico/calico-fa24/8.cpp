#include <bits/stdc++.h>
using namespace std;

// row column remaining dash hair
//
//

constexpr pair<int, int> dd[] = { { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1} };

struct vert {
	int r, c, e;
	int p;
	bool h;


	vert(int r, int c, int e, int p, bool h) : r(r), c(c), e(e), p(p), h(h) {}
};

void solve(){
	int n, m, k; cin >> n >> m >> k;
	vector<string> g(n);

	int sr, sc, er, ec;
	for (int r=0; r<n; ++r){
		cin >> g[r];
		for (int c=0; c<m; ++c){
			if (g[r][c] == 'S'){
				sr = r;
				sc = c;
			} else if (g[r][c] == 'E'){
				er = r;
				ec = c;
			}
		}
	}
	g[sr][sc] = '.';
	g[er][ec] = '.';



	deque<vert> bfs;
	vector<vector<vector<vector<vector<int>>>>> d(n, vector<vector<vector<vector<int>>>>(m, vector<vector<vector<int>>>(k+1, vector<vector<int>>(4, vector<int>(2, INT_MAX)))));
	vector<vector<vector<vector<vector<int>>>>> vis(n, vector<vector<vector<vector<int>>>>(m, vector<vector<vector<int>>>(k+1, vector<vector<int>>(4, vector<int>(2, false)))));
	bfs.push_front({ sr, sc, k, 0, true });
	d[sr][sc][k][0][true] = 0;

	auto relax = [&](vert u, vert v, int w){
		if (d[u.r][u.c][u.e][u.p][u.h]+w<d[v.r][v.c][v.e][v.p][v.h]){
			d[v.r][v.c][v.e][v.p][v.h] = d[u.r][u.c][u.e][u.p][u.h]+w;
			if (w == 1){
				bfs.push_back(v);
			} else {
				bfs.push_front(v);
			}
		}
	};

	while (!bfs.empty()){
		vert u = bfs.front(); bfs.pop_front();
		if (vis[u.r][u.c][u.e][u.p][u.h]){
			continue;
		}
		vis[u.r][u.c][u.e][u.p][u.h] = true;


		//cout << u.r << ' ' << u.c << ' ' << u.e << ' ' << u.p << '\n';

		// not dashing
		if (u.e == 0 || (u.h && u.e==k)){
			for (int i=0; i<4; ++i){
				int dr = dd[i].first;
				int dc = dd[i].second;

				if (u.r+dr<n && u.r+dr>=0 && u.c+dc<m && u.c+dc>=0 && g[u.r+dr][u.c+dc] != '#'){
					// walk 1 tile
					vert v(u.r+dr, u.c+dc, u.e, u.p, u.h);
					if (g[u.r+dr][u.c+dc] == '*'){
						v.e = k;
						v.h = true;
					}
					relax(u, v, 1);

					if (u.h && u.e==k){
						// start dash
						vert v(u.r+dr, u.c+dc, u.e-1, i, false);
						if (g[u.r+dr][u.c+dc] == '*'){
							v.h = true;
						}
						relax(u, v, 1);

					}
				}
			}
		}

		//continue a dash
		if (u.e != k && u.e != 0){
			int dr = dd[u.p].first;
			int dc = dd[u.p].second;
			

			if (g[u.r+dr][u.c+dc] == '.'){
				if (u.e != 1){
					// continue normally
					vert v(u.r+dr, u.c+dc, u.e-1, u.p, u.h);
					relax(u, v, 0);
				} else {
					// stop normally
					vert v(u.r+dr, u.c+dc, u.h ? k : 0, 0, u.h);
					relax(u, v, 0);
				}

			} else if (g[u.r+dr][u.c+dc] == '*'){
				if (u.e != 1){
					// continue thru the crystal
					vert v(u.r+dr, u.c+dc, u.e-1, u.p, true);
					relax(u, v, 0);
				} else {
					// stop on crystal
					vert v(u.r+dr, u.c+dc, k, 0, true);
					relax(u, v, 0);
				}
			} else if (g[u.r+dr][u.c+dc] == '#'){
				// stop at the wall
				vert v(u.r, u.c, (u.h) ? k : 0, 0, u.h);
				relax(u, v, 0);
			}

		}
	}

	int ans = min(d[er][ec][0][0][false], d[er][ec][k][0][true]);
	if (ans == INT_MAX){
		cout << "-1\n";
	} else {
		cout << ans << '\n';
	}

	/*
	for (int c=1; c<=7; ++c){
		if (!d.count(vert(1, c, 0, 0))){
			cout << "-1 ";
		} else {
			cout << d[vert(1, c, 0, 0)] << ' ';
		}
	}
	*/
	
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
