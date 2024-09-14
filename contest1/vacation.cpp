#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    long long ans = ((2*n+3) - sqrt(8*n+8*k+9))/2;
    cout << ans << "\n";

}

int main() {
    solve();
}
