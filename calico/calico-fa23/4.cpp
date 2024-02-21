#include <bits/stdc++.h>
using namespace std;

#define INTERACTIVE

string response;

void solve(){
	cout << "feed 1" << endl;
	cin >> response;
	cout << "feed 100" << endl;
	cin >> response;
	cout << "feed 50" << endl;
	cin >> response;
	cout << "poop" << endl;
	cin >> response;

	if (response == "1") cout << "guess queueon" << endl;
	else if (response == "100") cout << "guess heapeon" << endl;
	else cout << "guess stackeon" << endl;

	cin >> response;
	assert(response == "CORRECT");
}

int main(){
	int t; cin >> t;
	while (t--) solve();
}
