#include <iostream>
#include <iomanip>

#define PI 3.14159265358979323846L
#define ld long double
#define ll long long

ld solve(ll r, ll a, ll b){
    ld ans = 0;
    bool div = false;
    while (r != 0){
        ans += r*r;
        if (div){
            r /= b;
        } else {
            r *= a;
        }
        div = !div;
    }
    return ans*PI; 
}

int main(){
    int cases; std::cin >> cases;
    ll r, a, b;
    std::cout << std::setprecision(6) << std::fixed;
    for (int c=1; c<=cases; ++c){
        std::cin >> r >> a >> b;
        std::cout << "Case #" << c << ": " << solve(r, a, b) << '\n';
    }
}


