#include <iostream>
#include <map>
 
#define f first
#define s second
#define ll long long
 
int main(){
    std::map<int, ll> f;
    int n; std::cin >> n;
    int ai;
    while (n--){
        std::cin >> ai;
        ++f[ai];
    }
    
    auto it = f.begin();
    auto p1 = *it++; // pair<int, ll>
    
    if (p1.s >= 3){
        std::cout << (p1.s)*(p1.s-1)*(p1.s-2) / 6;
    } else if (p1.s == 2){
        auto p2 = *it++;
        std::cout << p2.s;
    } else if (p1.s==1){
        auto p2 = *it++;
        auto p3 = *it++;
        if (p2.s==1){
            std::cout << p3.s;
        } else {
            std::cout << (p2.s)*(p2.s-1)/2;
        }
    }
    std::cout << '\n';
}
