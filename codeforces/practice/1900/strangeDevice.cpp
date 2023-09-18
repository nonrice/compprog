// idea:
//
// Make initial query [1, k] and let u be the result
// Remove u from the initial query, and substitute it with each number in [k+1, n]. Let v be the smallest result that's greater than u
// Based on this definition, v is the immediate larger element of u in a.
// 
// Here we can eliminate a special case:
// If there does not exist a v, then u is the largest element in a. Thus the answer is k.
//
// Now we will continue.
// We will construct a query, which will be modified and asked several times.
// Initially it is just [1:k], with u replaced with v.
// Now we can test an element by replacing it with u:
// - If the answer is still v, it means that element was less than v
// - If the answer becomes u, it means that element was more or equal to v
// By using this method to count the number of elements less than v, we can easily figure out what m is.
//
// Finding v takes n-k queries. Testing each element in [1:k] takes k queries. So we have spent exactly n queries, which is the exact constraint outlined in the problem.
//

#include <bits/stdc++.h>
using namespace std;

#define INTERACTIVE

int n, k;
int q[500];

// response
int p, ap;

inline void ask(){
	cout << "? ";
	for (int i=0; i<k; ++i) cout << q[i] << ' ';
	cout << endl;
	cin >> p >> ap;
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	
	cin >> n >> k;
	iota(q, q+k, 1);
	
	ask();
	int up = p;
	int uap = ap;
	int vp = up, vap = INT_MAX;
	for (int i=k+1; i<=n; ++i){
		q[up-1] = i;
		ask();
		if (abs(uap - ap) < abs(uap - vap)){
			vap = ap;
			vp = p;
		}
	}
	q[up-1] = up;

	int avoid = up-1;
	bool swapped = false;
	if (vap < uap){
		swap(vp, up);
		swapped = true;
	}
	q[up-1] = vp;
	int l = 0;
	for (int i=0; i<k; ++i){
		if (i != avoid){
			q[i] = up;
			ask();
			if (p == vp) ++l;
			q[i] = i+1;
		}
	}

	cout << "! " << l+1 + swapped << '\n';
}
