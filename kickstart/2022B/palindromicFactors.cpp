#include <iostream>
#include <cmath>

#define ll long long

bool is_palindrome(ll n){  
    ll div = 1;
    while (n/div >= 10) div *= 10;
 
    while (n != 0){
        int f = n / div;
        int l = n % 10;
        if (f != l) 
            return false;
        n = (n%div) / 10;
        div = div / 100;
    }
    return true;
}

int solve(ll n){
    int max_f = std::sqrt(n);
    int ans = 0;
    for (int f=1; f<=max_f; ++f){
        if (n%f == 0){
            ans += is_palindrome(f);
            if (n/f != f)
                ans += is_palindrome(n/f);
        }
    }
    return ans;
}

int main(){
    int cases; std::cin >> cases;
    ll n;
    for (int c=1; c<=cases; ++c){
        std::cin >> n;
        std::cout << "Case #" << c << ": " << solve(n) << '\n';
    }
}
