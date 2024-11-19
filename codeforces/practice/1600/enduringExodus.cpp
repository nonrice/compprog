#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    ++k;
    vector<int> open;
    for (int i=0; i<n; ++i) if (s[i] == '0'){
        open.push_back(i);
    }
    
    int best = numeric_limits<int>::max();
    for (int i=0; i < (int)open.size()-k+1; ++i){
        int avg = (open[i] + open[i+k-1])/2;
        auto r = lower_bound(open.begin(), open.end(), avg);
        auto l = r - (r!=open.begin());
        int closest_avg = (avg-*l < *r-avg) ? *l : *r;

        best = min(
            best,
            max (
                closest_avg - open[i],
                open[i+k-1] - closest_avg
            )
        );
    }
    cout << best << '\n';
}

