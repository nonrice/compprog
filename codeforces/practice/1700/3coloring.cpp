// idea:
// once a lattice of the same color covers the grid as such, Bob can win:
// 1.1
// .1.
// 1.1
//
// Because each remaining cell will always have 2 colors availible.
// 
// For each grid, there are two ways to cover it with the lattice. The above way, and the inverted way, with another color:
// .2.
// 2.2
// .2.
//
// If two colors are availible for the lattice, then it is guaranteed one lattice can be completed, because Alice can't limit 2 colors.
//
// As stated above, once a lattice is completed, the remaining empty cells can be filled trivially.
// The other unfinished lattice can be thought of to already fill in some of the remaining cells.

#include <bits/stdc++.h>
using namespace std;

#define INTERACTIVE

int n;

inline short get(){
    int v; cin >> v;
    return v;
}

// put c at p (converted to 2d) and increment p to the next lattice cell 
inline void put(int c, int& p){
    cout << c << ' ' << p/n + 1 << ' ' << p%n + 1 << endl;
    if (n%2) p += 2;
    else {
        if (n-p%n == 1) p += 1;
        else if (n-p%n == 2) p += 3;
        else p += 2;
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    cin >> n;

    int p1=0, p2=1;

    int c1 = 1+get()%3;
    put(c1, p1);
    int c2 = 1;
    {
        int c = get()%3;
        while (c2 == c1 || c2 == c) ++c2;
    }
    put(c2, p2);

    while (p1 < n*n && p2 < n*n){
        int c = get();
        if (c == c1){
            put(c2, p2);
        } else {
            put(c1, p1);
        }
    }

    if (p2 < p1){
        swap(p1, p2);
        swap(c1, c2);
    }
    int c3 = 1;
    while (c3 == c1 || c3 == c2) ++c3;
    while (p1 < n*n){
        int c = get();
        if (c == c1) put(c3, p1);
        else put(c1, p1);
    }
}
