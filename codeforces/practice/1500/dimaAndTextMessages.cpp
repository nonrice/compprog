#include <iostream>
#include <string>

// how is this a 1500??

int main(){
    int n; std::cin >> n;
    std::string s="<3", w;
    while (n--){
        std::cin >> w;
        s += w + "<3";
    }
    std::string t; std::cin >> t;

    size_t p1 = 0;
    for (size_t p2=0; p2<t.size(); ++p2){
        if (s[p1]==t[p2] && ++p1==s.length()){
            std::cout << "yes\n";
            return 0;
        }
    }

    std::cout << "no\n";
}
