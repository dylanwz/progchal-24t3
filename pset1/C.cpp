#include <bits/stdc++.h>

using namespace std;

int triangular(int n) {
    if (n == 0) return 0;
    if (n == 1) return 2;
    if (n < 0) return -1;
    // we want to solve n = (xC2) for x
    // x = (1 + sqrt(1+8n))/2   
    double x = (1+sqrt(1 + 8*n))/2;
    return floor(x) == x ? x : -1;
}

void solve() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    if (a == 0 and d == 0) {
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

    // determine number of 0s and 1s needed first
    int num_zero = triangular(a);
    int num_one = triangular(d);
    if (num_zero == -1 or num_one == -1) {
        cout << "impossible" << "\n";
        return;
    }
    string ans = "";
    for (int _ = 0; _ < num_one; _++) ans.push_back('1');
    if (a == 0 and b == 0 and c == 0) {
        cout << ans << "\n";
        return;
    }
    for (int _ = 0; _ < num_zero; _++) ans.push_back('0');
    if (b == 0 and c == 0 and d == 0) {
        cout << ans << "\n";
        return;
    }
    
    if (num_zero == 0) {
        ans.push_back('0');
    }
    if (num_one == 0) {
        ans.insert(ans.begin(), '1');
    }

    // so we have smth like 11000 and now push 1s back to make b number of 01
    int last_ind = num_one - 1;
    int initial_last_ind = last_ind; int change_times = 0;
    int rem_b = b;
    while (rem_b > 0) {
        if (last_ind < 0) {
            cout << "impossible" << "\n";
            return;
        }
        if (last_ind == ans.size()) {
            cout << "impossible" << "\n";
            return;
        }
        swap(ans[last_ind], ans[last_ind + 1]);
        last_ind++;
        if (last_ind + 1 >= ans.size() || ans[last_ind+1] == '1') {
            change_times++;
            last_ind = initial_last_ind - change_times;
        }
        rem_b--;
    }
    // finally count number of '10' subsequences
    int cum_zero = 0;
    int count = 0;
    for (int i = ans.size(); i >= 0; i--) {
        if (ans[i] == '0') {
            cum_zero++;
        } else if (ans[i] == '1') {
            count += cum_zero;
        }
    }
    if (count != c) {
        cout << "impossible" << "\n";
        return;
    }

    cout << ans << "\n";
}

int main() {
    solve();
}