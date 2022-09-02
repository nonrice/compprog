#include <bits/stdc++.h>
using namespace std;

int main(){
    for (int i=1; i<50; ++i){
        for (int j=1; j<50; ++j){
            if (lcm(i,j)/gcd(i, j) <= 3) cout << '#';
            else cout << '.';
        }
        cout << '\n';
    }
}
