#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define f first
#define s second

int main(){
    int w, h;
    std::cin >> h >> w;
    bool map[1000][1000];
    std::string row;
    std::pair<int, int> start;
    std::pair<int, int> end;
    for (int r=0; r<h; ++r){
        std::cin >> row;
        for (int c=0; c<w; ++c){
            if (row[c]=='#')
                map[r][c] = true;
            if (row[c]=='A'){
                start = std::make_pair(r, c);
            } else if (row[c]=='B'){
                end = std::make_pair(r, c);
            }
        }
    }

    std::queue<std::pair<int, int>> bfs({start});
    int ds[1000][1000];
    int dirs_r[4] = { 1, -1, 0, 0 };
    int dirs_c[4] = { 0, 0, 1, -1 };
    int nr, nc;
    while (!bfs.empty()){
        std::pair<int, int> p = bfs.front(); bfs.pop();
        for (int i=0; i<4; ++i){
            nr = p.f+dirs_r[i];
            nc = p.s+dirs_c[i];
            if (nr>=0 && nr<h && nc>=0 && nc<w && !map[nr][nc]){
                bfs.emplace(nr, nc);
                ds[nr][nc] = i;
                map[nr][nc] = true;
            }
        }
        if (p.f==end.f && p.s==end.s)
            break;
    }

    char dirs[] = "DURL";
    int d;
    if (map[end.f][end.s]){
        int cr=end.f;
        int cc=end.s;
        std::vector<char> ans;
        while (cr != start.f || cc != start.s){
            d = ds[cr][cc];
            ans.push_back(dirs[d]);
            cr -= dirs_r[d];
            cc -= dirs_c[d];
        }
        std::cout << "YES\n" << ans.size() << '\n';
        for (auto it = ans.rbegin(); it != ans.rend(); ++it)
            std::cout << *it;
        std::cout << '\n';
    } else {
        std::cout << "NO\n";
    }
}
