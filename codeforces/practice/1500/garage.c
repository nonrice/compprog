#include <stdio.h>

int main(){
    long long n; scanf("%lld", &n);

    if (--n) printf("%lld", (n % 3) ? 3+2*(n-n/3) : 4 + n/3*4);
    else printf("3\n");
}
