#include <iostream>
#include <vector>
#include <utility>

void init_dsu(std::vector<int>& p){
    const int n = p.size();
    for (int i=0; i<n; ++i)
        p[i] = i;
}

int find(std::vector<int>& p, int u){
    if (u == p[u])
        return u;
    return p[u] = find(p, p[u]);
}

void union_sets(std::vector<int>& p, int u, int v){
    int p1 = find(p, u);
    int p2 = find(p, v);
    if (p1 != p2)
        p[p1] = p2;
}

void stdin_init_dsu(std::vector<int>& p, int n){
    init_dsu(p);
    int u, v;
    while (n--){
        std::cin >> u >> v;
        union_sets(p, u, v);
    }
}

int main(){
    int n, m1, m2;
    std::cin >> n >> m1 >> m2;
    std::vector<int> pm(n+1);
    std::vector<int> pd(n+1);
    stdin_init_dsu(pm, m1);
    stdin_init_dsu(pd, m2);
    
    std::vector<std::pair<int, int>> ans;
    for (int u=1; u<=n; ++u){
        for (int v=u+1; v<=n; ++v){
            if (!(find(pm, u)==find(pm, v) || find(pd, u)==find(pd, v))){
                union_sets(pm, u, v);
                union_sets(pd, u, v);
                ans.emplace_back(u, v);
            }
        }
    }

    std::cout << ans.size() << '\n';
    for (std::pair<int, int>& edge:ans)
        std::cout << edge.first << ' ' << edge.second << '\n';
}
