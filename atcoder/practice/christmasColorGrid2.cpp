#include <bits/stdc++.h>
#define int long long 
using namespace std;
int h, w;
char m[1000][1001];

struct coord {
	int r, c;

	coord(int r, int c) : r(r), c(c) {}
};
constexpr int dr[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
constexpr int dc[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
bool vis[1000][1000];
queue<coord> bfs;
inline void mark(int r, int c){
	if (m[r][c] == '.'){
		bfs.emplace(r, c);
		vis[r][c] = true;
	}
}

int p[1000][1000];
int cur_p = 1;
void dfs(int r, int c){
	for (int i=0; i<4; ++i){
		int nr = r+dr[i];
		int nc = c+dc[i];
		if (nr >= 0 && nr < h && nc >= 0 && nc < w && m[nr][nc]=='#' && !p[nr][nc]){
			p[nr][nc] = cur_p;
			dfs(nr, nc);
		}
	}
}

constexpr long long M = 998244353;
long long binpow(long long a, long long b, long long m){
	long long ans = 1;
	while (b){
		if (b&1) ans = ans*a%m;
		a = a*a%m;
		b >>= 1;
	}

	return ans;
}

signed main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	cin >> h >> w;
	for (int r=0; r<h; ++r){
		cin >> m[r];

		mark(r, 0);
		mark(r, w-1);
	}

	for (int r=0; r<h; ++r){
		for (int c=0; c<w; ++c){
			if (!p[r][c] && m[r][c] == '#'){
				p[r][c] = cur_p;
				dfs(r, c);
				++cur_p;
			}
		}
	}

	for (int c=0; c<w; ++c){
		mark(0, c);
		mark(h-1, c);
	} 
	while (!bfs.empty()){
		auto [r, c] = bfs.front();
		bfs.pop();

		for (int i=0; i<8; ++i){
			int nr = r+dr[i];
			int nc = c+dc[i];
			if (nr >= 0 && nr < h && nc >= 0 && nc < w && m[nr][nc]=='.' && !vis[nr][nc]){
				vis[nr][nc] = true;
				bfs.emplace(nr, nc);
			}
		}
	}

	long long ans_n = 0;
	int ans_d = 0;
	for (int r=0; r<h; ++r){
		for (int c=0; c<w; ++c) if (m[r][c] == '#') {
			ans_n = (ans_n + cur_p-1) % M;
			++ans_d;
			bool b[4] = {};
			for (int i=4; i<8; ++i){
				int nr = r+dr[i];
				int nc = c+dc[i];
				if (nr >= 0 && nr < h && nc >= 0 && nc < w && ((m[nr][nc]=='.' && !vis[nr][nc]) || m[nr][nc]=='#')){
					b[i-4] = true;
				}
			}
			
			bool ch[4] = {};
			for (int i=0; i<4; ++i){
				int nr = r+dr[i];
				int nc = c+dc[i];
				if (nr >= 0 && nr < h && nc >= 0 && nc < w && m[nr][nc]=='#'){
					ch[i] = true;
				}
			}


			for (int i=0; i<4; ++i){
				if (b[i%4]){
					ch[i%4] = ch[(i+1)%4] = (ch[i%4]|ch[(i+1)%4]);
				}
			}

			int chg = 0;
			for (int i=0; i<4; ++i){
				if ((ch[i] == 0 && ch[(i+1)%4] == 1) || (ch[i] == 1 && !b[i] && ch[(i+1)%4] == 1)){
					++chg;
				}
			}

			if ((ch[0]||ch[1]||ch[2]||ch[3]) == 0){
				--ans_n;
				if (ans_n<0) ans_n += M;
			}

			ans_n = (ans_n + max(0LL, chg-1)) %M;
		}
	}

	cout << ans_n*binpow(ans_d, M-2, M)%M << '\n';
}
