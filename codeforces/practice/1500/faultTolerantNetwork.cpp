#include <iostream>
#include <algorithm>
#include <cmath>

#define ll long long

int get_nearest(int x, int* arr, int n){
    int min_diff = 1000000001;
    int p = 0;
    for (int i=0; i<n; ++i){
        if (std::abs(x-arr[i]) < min_diff){
            min_diff = std::abs(x-arr[i]);
            p = i;
        }
    }
    return p;
}

int solve(int* a, int* b, int n){
    ll min = 10000000000LL;
    for (int v1:{0, get_nearest(a[0], b, n), n-1}){
        for (int v2:{0, get_nearest(a[n-1], b, n), n-1}){
            ll can = (ll)std::abs(a[0]-b[v1]) + std::abs(a[n-1]-b[v2]);
            if (v1>0 && v2>0)
				can += std::abs(b[0]-a[get_nearest(b[0], a, n)]);
		    if (v1<n-1 && v2<n-1)
				can += std::abs(b[n-1]-a[get_nearest(b[n-1], a, n)]);
			min = std::min(min, can);
        }
    }
    
    return min;
}

int main(){
    int cases, n, a[200000], b[200000];
    std::cin >> cases;
    while (cases--){
        std::cin >> n;
        for (int i=0; i<n; ++i)
            std::cin >> a[i];
        for (int i=0; i<n; ++i)
            std::cin >> b[i];
        std::cout << solve(a, b, n) << '\n';
    }
}
