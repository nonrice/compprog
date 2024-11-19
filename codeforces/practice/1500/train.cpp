#include <iostream>
#include <string>
#include <numeric>

int main(){
    int n, m, k; std::cin >> n >> m >> k;
    std::string dir;
    std::cin.ignore(3); // "to "
    std::cin >> dir;
    bool d = dir=="head";
    std::string s; std::cin >> s;

    for (size_t i=0; i<s.length(); ++i){
        if (s[i] == '0'){
            if (m > k)
                m = std::min(m+1, n);
            else
                m = std::max(m-1, 1);
            if (m == k){
                std::cout << "Controller " << i+1 << '\n';
                return 0;
            }
        } else {
            if (k==n) m = n;
            else if (k==1) m = 1;
            else m = (d) ? n : 1;
        }

        if ((d && k==1) || (!d && k==n))
            d = !d;
        k += 1-2*d;
        if (m == k){
            std::cout << "Controller " << i+1 << '\n';
            return 0;
        }
    }
    std::cout << "Stowaway\n";
}

