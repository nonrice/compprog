#include <iostream>
#include <vector>
#include <numeric>

//heeheeheehaw

int main(){
    int n; std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> pref(n+1); // prefix sums because i am a pro
    for (int i=0; i<n; ++i){
        std::cin >> a[i];
        pref[i+1] = pref[i]+a[i];
    }
    
    int best = 0;
    int cand;
    for (int i=0; i<n; ++i){
        for (int j=i; j<n; ++j){
            cand = pref[i]+pref[n]-pref[j+1];
            for (int k=i; k<=j; ++k)
                cand += a[k]==0;
            best = std::max(best, cand);
        }
    }
     
    std::cout << best << '\n';
}

