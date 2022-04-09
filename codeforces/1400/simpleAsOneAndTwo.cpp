#include <iostream>
#include <string>
#include <vector>

int main(){
    int cases;
    std::string s;
    std::vector<int> ans;

    std::cin >> cases;
    while(cases--){
        std::cin >> s;
        for (std::string t: {"twone", "one", "two"}) {
            for (size_t i=0; (i=s.find(t, i))!=std::string::npos;) {
                s[i + t.length()/2] = '-';
                ans.push_back(i + t.length()/2);
            }
        }
        
        std::cout << ans.size() << '\n';
        for (int a:ans)
            std::cout << a+1 << ' ';
        std::cout << '\n';
        ans.clear();
    }
}

