#include <iostream>
#include <string>
#include <stack>
 
int main(){
    std::string s; std::cin >> s;
    std::stack<int> st;
    for (char ch : s){
        if (!st.empty() && st.top() == ch){
            st.pop();
        } else {
            st.push(ch);
        }
    }
    std::cout << ((st.empty()) ? "Yes\n" : "No\n");
}
