#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

string s;
string t;

void solve(ll n, ll k) { // n size, k num strings
    ll ans = 0;
    ll potential = 2; // potential prefixes come in mltpls of 2 since alph = only a,b (e.g. i=0: a,b, i=1: aa, ab, ba, bb)
    for (int i = 0; i < n; i++) { 
        if (s[i] == 'b') potential--; // if lower bound is b, then we lose the aa case as shown above
        if (t[i] == 'a') potential--; // if upper bound is a, then we lose the bb case as shown above
        ans += min(potential, k); // bounded by k
        //if potential became too large, bound to k but then we want to add 2 to 2k in the case where k=1, s=ab and t=ba and we miss options
        // when moving from i=0 to i=1 (accidental potential = 0 edge case)
        if (potential > k) potential = k+2;
        potential *= 2; // mltpls of 2; e.g. a + b + aa + ab + ba + bb = 6 = 2(1) + 2(2)
    }
    cout << ans << "\n";
}

int main() {
    ll n,k;
    cin >> n >> k;
    cin >> s >> t;
    solve(n, k);
}
