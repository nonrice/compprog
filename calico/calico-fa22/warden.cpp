#include <bits/stdc++.h>
using namespace std;

#define INTERACTIVE

double ask(double x, double y){
    cout << "P " << x << ' ' << y << endl;
    cout.flush();
    double ret; cin >> ret;
    return ret;
}

bool ans(double x, double y){
    cout << "B " << x << ' ' << y << endl;
    cout.flush();
    string s; cin >> s;
    if (s == "WRONG_ANSWER") return true;
    return false;
}

// x,y is mystery point....
//
// (0, mx)
// (mx, 0)
// (-mx, -mx)
// three points
// triangulate (x,y)
//
//

bool solve(){
    double x1=100000, y1=0;
    double x2=0, y2=100000;
    double x3=-100000, y3=0;
    double r1 = ask(x1, y1)-x1;
    double r2 = ask(x2, y2)-y2;
    double r3 = ask(x3, y3)-100000;
    double a = 2*x2 - 2*x1;
    double b = 2*y2 - 2*y1;
    double c = r1*r1 - r2*r2 - x1*x1 + x2*x2 - y1*y1 + y2*y2;
    double d = 2*x3 - 2*x2;
    double e = 2*y3 - 2*y2;
    double f = r2*r2 - r3*r3 - x2*x2 + x3*x3 - y2*y2 + y3*y3;

    return ans((c*e-f*b)/(e*a-b*d), (c*d-a*f)/(b*d-a*e));
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) if (solve()) return 0;
}
