#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

int solve(int w, int h){
    std::vector<std::vector<bool>> mat(h, std::vector<bool>(w));
    std::string row;
    for (int r=0; r<h; ++r){
        std::cin >> row;
        for (int c=0; c<w; ++c){
            if (row[c] == '*')
                mat[r][c] = true;
        }
    }

    std::vector<std::vector<int>> dp(h, std::vector<int>(w));
    for (int c=0; c<w; ++c){
        if (mat[h-1][c])
            dp[h-1][c] = 1;
    }
    
    for (int r=h-2; r>=0; --r){
        dp[r][0] = mat[r][0];
        dp[r][w-1] = mat[r][w-1];
        for (int c=1; c<w-1; ++c){
            if (mat[r][c])
                dp[r][c] = std::min({dp[r+1][c-1], dp[r+1][c], dp[r+1][c+1]})+1;
        }
    }
    
    int result = 0;
    for (auto& row : dp)
        result = std::accumulate(row.begin(), row.end(), result);

    return result;
}

int main(){
    int cases, w, h;

    std::cin >> cases;
    while (cases--){
        std::cin >> h >> w;
        std::cout << solve(w, h) << '\n';
    }
}

