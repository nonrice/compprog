#include <iostream>

#define ll long long

int main(){
    ll a;
    std::cin >> a;
    while (a != 1LL){
        std::cout << a << ' ';
        if (a%2){
            a = 3LL*a + 1LL;
        } else {
            a /= 2LL;
        }
    }
    std::cout << 1 << '\n';
}
