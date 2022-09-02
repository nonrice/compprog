#include <bits/stdc++.h>
using namespace std;

const int mx = 60;

bool check_triangle(int a, int b, int c){
    return a + b <= c || a + c <= b || b + c <= a;
}

int main(){
    for (int i=1; i<=mx; ++i){
        for (int j=1; j<=mx; ++j){
            int cm = gcd(i, j);
            if (check_triangle(cm, i/cm, j/cm)) cout << '.';
            else cout << '#';
        }
        cout << '\n';
    }
}
