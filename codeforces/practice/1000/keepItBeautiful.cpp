#include <bits/stdc++.h>
using namespace std;

// a is beautiful if and only if there exists a prefix suffix partition of a such that the suffix is sorted and the final element of a is smaller than or equal to the smallest element of the prefix
// 
// Let x be the last point at which a[n] < min(a[1:x])
// Let y be the first point at which a[y:n] is sorted
//
// The array is beautiful if x<=y, because then there exists a point at which both of the qualities are satisfied.
//
// To make this algorithm online when a is appended to, x may be binary searched and y can easily be updated
