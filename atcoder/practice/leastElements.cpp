#include <bits/stdc++.h>
using namespace std;

// idea
// calc answer with sliding window. Updating sliding window needs 2 operations:
//
// ds:
// multiset of all elements in the window
// iterator of the last element in the sum
//
// add element: 
// past the itr=not in the sum=do nothing
// else, put it in and decrement the iterator
//
// remove element:
// past the itr=not in the sum=do nothing
// else, remove it and increment the iterator

int a[200000];

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, m, k; cin >> n >> m >> k;
    for (int i=0; i<n; ++i) cin >> a[i];

    multiset<int> win(a, a+m);
    multiset<int>::iterator lst(next(win.begin(), k+1));
    long long sum = accumulate(win.begin(), lst, 0LL);
    for (int i=0; i<n-m; ++i){
        win.insert(a[i+m]);
        if (a[i+m] < *lst) --lst;
        if (a[i] > *lst) ++lst;

    }
}
