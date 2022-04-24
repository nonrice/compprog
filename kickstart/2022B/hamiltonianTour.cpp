#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <numeric>
#include <stack>

#define f first
#define s second

int dirs_r[4] = { -1, 0, 1, 0 };
int dirs_c[4] = { 0, 1, 0, -1 };

struct tree_node{
    std::vector<int> dirs;
};

char dir_to_ch(int dir){
    dir %= 4;
    if (dir==0){
        return 'N';
    } else if (dir==1){
        return 'E';
    } else if (dir==2){
        return 'S';
    } else if (dir==3){
        return 'W';
    }
}

void dfs_tree(tree_node[200][200] t, std::pair<int, int> cur, int cur_dir){
    if (t[cur.f][cur.s].dirs.empty())
        std::cout << dir_to_ch(dir+1);
    for (int dir:t[cur.f][cur.s].dirs){
        std::cout << dir_to_ch(dir);
        dfs_tree(t, std::make_pair(dirs_r[dir], dirs_c[dir]), dir);
        std::cout << dir_to_ch(dir+2);
    }
}

void solve(int case){
    std::cout << "Case #" << case << ':';
    
    int h, w; std::cin >> h >> w;
    bool map[200][200];
    std::string row;
    for (int r=0; r<h; ++r){
        for (int c=0; c<w; ++c){
            std::cin >> row;
            for (char ch:row)
                map[r][c] = ch=='#';
        }
    }
    
    std::queue<std::pair<int, int>> bfs({0, 0});
    tree_node t[200][200];
    int nr, nc;
    while (!bfs.empty()){
        std::pair<int, int> p = bfs.front(); bfs.pop();
        for (int i=0; i<4; ++i){
            nr = p.f+dirs_r[i];
            nc = p.s+dirs_c[i];
            if (nr>=0 && nr<h && nc>=0 && nc<w && !map[nr][nc]){
                bfs.emplace(nr, nc);
                t[r][c].dirs.push_back(i);
                map[nr][nc] = true;
            }
        }
        if (p.f==end.f && p.s==end.s)
            break;
    }
    
    // check if bfs covered all
    int sum = 0;
    for (int r=0; r<h; ++r)
        sum += std::accumulate(map[r], map[r]+w, 0);
    if (sum < h*w){
        std::cout << "IMPOSSIBLE\n";
        return;
    }

    dfs_tree(t, std::make_pair(0, 0), 1);
    std::cout << '\n';
}



