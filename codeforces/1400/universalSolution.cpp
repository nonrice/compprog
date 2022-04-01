#include <iostream>
#include <string>
#include <algorithm>

int main(){
    int cases;
    int r, p, s, max;
    std::string moves;
    char ans;

    std::cin >> cases;
    while (cases--){
        std::cin >> moves;
        r = std::count(moves.begin(), moves.end(), 'R');
        p = std::count(moves.begin(), moves.end(), 'P');
        s = std::count(moves.begin(), moves.end(), 'S');
        max = std::max({r, p, s});
        if (max == s){
            ans = 'R';
        } else if (max == r){
            ans = 'P';
        } else if (max == p){
            ans = 'S';
        }
        for (int i=0; i<moves.length(); ++i){
            std::cout << ans;
        }
        std::cout << '\n';
    }
}
