#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n; std::cin >> n;
    std::vector<std::vector<int>> adj(n, std::vector<int>());
    for (int i=0; i<n-1; ++i){
        int u, v; std::cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(i);
        adj[v].push_back(i);
        
        int t = -1;
        if (adj[u].size() == 3) t=u;
        else if (adj[v].size() == 3) t=v;
        if (t != -1){
            //found answer
            int f3 = 0;
            int c = 3;
            for (int i=0; i<n-1; ++i){
                if (std::find(adj[t].begin(), adj[t].end(), i) != adj[t].end()){
                    std::cout << f3 << '\n';
                    ++f3;
                } else {
                    std::cout << c << '\n';
                    ++c;
                }
            }
            return 0;
        }
    }

    //no answer
    for (int i=0; i<n-1; ++i){
        std::cout << i << '\n';
    }
}
