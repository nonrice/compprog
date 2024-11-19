// idea:
//
//
// for each element, find a subarray such that:
// - it contains the element
// - the sum of the subarray is maximum
// - the element is the maximum element in the subarray
//
// This way the "worst case" is constructed for each element, so if one fails, the whole array is also invalid.
//
// How to do it?
//
// First for each element, calculate a "region" where if the left and right endpoints are placed on either side of the element, and remanining in the region, the element is always the maximum of the resulting subarray.
//
// You can do this with monotonic stack I guess, but it needs 2 passes for each direction
//
// xxL..?..M.?.Rxx
//
// Now make a prefix sum. Given this and L, M, R, you want to find the minimum prefix between L and M (to subtract from p[m]) and the maximum prefix between R and M (to get p[m] subtracted from). You can do this in a rolling window fashion, whilst calculating the "maximum" regions for each element, one on each pass.
//
// Finally with all the auxilary values computed, iterate each element one last time and compare the sum of the two subarray sums with the selected element. 
//

#include <bits/stdc++.h>
using anm
