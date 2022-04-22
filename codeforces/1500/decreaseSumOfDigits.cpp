#include <iostream>

#define ull unsigned long long

int sum_digits(ull n){
    int sum = 0;
    while (n != 0){
        sum += n%10;
        n /= 10;
    }
    return sum;
}

ull solve(ull n, int s){
    if (sum_digits(n) <= s)
        return 0ULL;
    for (ull p=10; p<n*10; p*=10){
        if (sum_digits(n+p-n%p) <= s)
            return p-n%p;
    }
    return 0Ull;
}

int main(){
    int cases; std::cin >> cases;
    ull n;
    int s; 
    while (cases--){
        std::cin >> n >> s;
        std::cout << solve(n, s) << '\n';
    }
}
