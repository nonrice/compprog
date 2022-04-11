#include <iostream>
#include <algorithm>
#include <cmath>

#define ll long long

int calc_nearest(int x, int* arr, int n){
    int min_diff = 1000000001;
    int val = arr[0];
    for (int i=0; i<n; ++i){
        if (std::abs(x-arr[i]) < min_diff){
            min_diff = std::abs(x-arr[i]);
            val = arr[i];
        }
    }
    return val;
}

int solve(int* a, int* b, int n){
    ll sa=a[0], ea=a[n-1], sb=b[0], eb=b[n-1];
    std::sort(a, a+n);
    std::sort(b, b+n);
    ll nsa = calc_nearest(sa, b, n);
    ll nea = calc_nearest(ea, b, n);
    ll nsb = calc_nearest(sb, a, n);
    ll neb = calc_nearest(eb, a, n);
    ll cost = 0;
    if (nsa == sb || nsb == sa){
        cost += std::abs(sa-sb);
    } else {
        cost += std::abs(sa-nsa) + std::abs(sb-nsb);
    }

    if (nea == eb || neb == ea){
        cost += std::abs(ea-eb);
    } else {
        cost += std::abs(ea-nea) + std::abs(eb-neb);
    }
    return cost;
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
