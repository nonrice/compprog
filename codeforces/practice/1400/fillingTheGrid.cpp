#include <iostream>
#include <vector>
#include <numeric>

#define MOD 1000000007 

int main(){
    int h, w; std::cin >> h >> w;
    std::vector<std::vector<int8_t>> g(h, std::vector<int8_t>(w));
    int v;

    for (int i=0; i<h; ++i){
        std::cin >> v;
        for (int col=0; col<v; ++col)
            g[i][col] = 1;
        if (v!=w)
            g[i][v] = -1;
    }
    for (int i=0; i<w; ++i){
        std::cin >> v;
        for (int row=0; row<v; ++row){
            if (g[row][i]==-1){
                std::cout << "0\n";
                return 0;
            }
            g[row][i] = 1;
        }
        if (v!=h){
            if (g[v][i]==1){
                std::cout << "0\n";
                return 0;
            }
            g[v][i] = -1;
        }
    }

    int unlocked = h*w;
    for (auto& row : g){
        for (int cell : row)
            unlocked -= cell!=0;
    }
     
    if (!unlocked){
        std::cout << "1\n";
    } else {
        int ans = 1;
        while (unlocked--)
            ans = (ans%MOD) * 2;
        std::cout << ans%MOD << '\n';
    }
}

