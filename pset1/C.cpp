#include <iostream>
#include <math.h>

using namespace std;

long long triangular(long long n, long long b, long long c) {
    if (n == 0 && (b > 0 || c > 0)) return 1;
    if (n == 0) return 0;
    if (n == 1) return 2;
    // we want to solve n = (xC2) for x
    // x = (1 + sqrt(1+8n))/2   
    double x = (1+sqrt(1 + 8*n))/2;
    return floor(x) == x ? x : -1;
}

void solve() {
    long long a,b,c,d;
    cin >> a >> b >> c >> d;

    if ((a < 0 || b < 0 || c < 0 || d < 0) || (a == 0 and d == 0)) { // either 0 or 1 of each
        if (b == 0 and c == 0) {
            cout << "0" << "\n";
        } else if (b == 1 and c == 0) {
            cout << "01" << "\n";
        } else if (b == 0 and c == 1) {
            cout << "10" << "\n";
        } else {
            cout << "impossible" << "\n";
        }
        return;
    }

    // determine concretely the number of 0s and 1s needed first
    long long num_zero = triangular(a, b, c);
    long long num_one = triangular(d, b, c);
    // cout << num_zero << " " << num_one << "\n";
    if (num_zero == -1 or num_one == -1 or (num_zero*num_one != b+c)) {
        cout << "impossible" << "\n";
        return;
    }

    // swapping chars too slow so let's just assume it will end up in this form:
    //                                f1 f0 m1 b0 b1
    //                                 1..0..1..0..1                  
    // for every front one we gain num_zero times '10' 
    long long front_one = num_zero == 0 ? 0 : c / num_zero;

    // we have c % num_zero remaining '10's to fill
    long long back_zero = num_zero == 0 ? 0 : c % num_zero;
    
    // we don't want anymore '10's so just shove the remaining zeros to the front now
    long long front_zero = num_zero - back_zero;
    
    // now the '01's are mathematically guaranteed; (given num_one*num_zero=b+c)
    // if there are no b0s then we don't need any 1s in the middle and we can just set b1 to what we need
    // otherwise we need to put in a 1 to preserve the number of planned '10's
    long long mid_one = back_zero > 0 ? 1 : 0;
    
    // the remaining b1s MUST be the total ones minus f1 and m1
    long long back_one = num_one - front_one - mid_one;

    while (front_one > 0) { cout << "1"; front_one--; }
    while (front_zero > 0) { cout << "0"; front_zero--; }
    while (mid_one > 0) { cout << "1"; mid_one--; }
    while (back_zero > 0) { cout << "0"; back_zero--; }
    while (back_one > 0) { cout << "1"; back_one--; }
    cout << "\n";
}

int main() {
    solve();
}