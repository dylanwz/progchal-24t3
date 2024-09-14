#include <bits/stdc++.h>

using namespace std;

void solve() {
    
    int r; string s;
    cin >> r >> s;

    if (r == 1) {
        cout << s << "\n";
        return;
    }

    // reconstruct
    vector<string> each_r(r);
    int cy = r + (r-1) - 1;
    int ind = 0;
    for (int i = 0; i < r; i++) {
        for (int j = i; j < s.size(); j += cy) {
            each_r[i].push_back(s[ind]);
            ind++;
            if (i != 0 && i != r - 1 && (j+2*(r-1-i)) < s.size()) { // mid rows factor in extra char, i->bot->i (symmetric)
                each_r[i].push_back(s[ind]);
                ind++;
            }
        }
    }

    // simulate
    string ans;
    int row = 0, step = 1;
    for (int i = 0; i < s.size(); i++) {
        ans += each_r[row][0];
        each_r[row].erase(each_r[row].begin());

        if (row == 0) {
            step = 1;
        } else if (row == r - 1) {
            step = -1;
        }
        row += step;
    }

    cout << ans << "\n";
}

int main() {
    solve();
}