#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; scanf("%d", &t);
    while (t--){
        int n, a, b; scanf("%d%d%d", &n, &a, &b);
        if (b < a) printf("1\n");
        else printf("%d\n", (n+a-1)/a);
    }
}
