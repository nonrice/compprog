#include <iostream>
#include <vector>

void dsu_init(std::vector<int>& p){
    for (size_t i=0; i<p.size(); ++i)
        p[i] = i;
}

int dsu_find(std::vector<int>& p, int u){
    if (p[u] == u)
        return u;
    return p[u] = dsu_find(p, p[u]);
}

void dsu_union(std::vector<int>& p, int u, int v){
    int p1 = dsu_find(p, u);
    int p2 = dsu_find(p, v);
    if (p1 != p2)
        p[p1] = p2;
}

int main(){
    int n, m; std::cin >> n >> m;
    std::vector<int> p(n+1);

    dsu_init(p);
    int k, first, cur;
    while (m--){
        std::cin >> k;
        if (k != 0){ // Why does the input allow this?
            std::cin >> first;
            while (--k){ // loops k-1 times
                std::cin >> cur;
                dsu_union(p, cur, first);
            }
        }
    }
    
    std::vector<int> ps(n+1); // no need for map
    for (int i=1; i<=n; ++i)
        ++ps[dsu_find(p, i)];
    for (int i=1; i<=n; ++i)
        std::cout << ps[dsu_find(p, i)] << ' ';
    std::cout << '\n';
}
