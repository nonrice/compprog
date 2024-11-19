#include <iostream>
#include <string>
#include <numeric>

int rgb_toi(char ch){
    if (ch=='R'){
        return 0;
    } else if (ch=='G'){
        return 1;
    } else if (ch=='B'){
        return 2;
    }
    return -1;
}

int match_rgb(int n, int k, std::string& s, int shift){
    int expect = shift;
    int best = 0;
    for (int i=0; i<k; ++i){
        if (rgb_toi(s[i]) != expect)
            ++best;
        expect = (expect+1)%3;
    }

    int cur = best;
    int expect1 = shift;
    int expect2 = (shift+k)%3;
    for (int p2=k; p2<n; ++p2){
        cur -= (rgb_toi(s[p2-k]) != expect1) - (rgb_toi(s[p2]) != expect2);
        best = std::min(best, cur);
        expect1 = (expect1+1)%3;
        expect2 = (expect2+1)%3;
    }

    return best;
}

void solve(){
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;
    int best = 200000;
    for (int shift:{0, 1, 2}){
        best = std::min(best, match_rgb(n, k, s, shift));
    }
    std::cout << best << '\n';
}

int main(){
    int cases; std::cin >> cases;
    while (cases--){
        solve();
    }
}

