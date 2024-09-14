#include <bits/stdc++.h>

using namespace std;

void solve () {
    int n, m;
    cin >> n >> m;

    vector<int> collection(m+1, 0);
    // max of four sets
    for (int _ = 0; _ < n; _++) {
        int s;
        cin >> s;
        for (int ind = 0; ind < s; ind++) {
            int c;
            cin >> c;
            collection[c]++;
        }
    }

    // return global minimum
    int inf = INT_MAX;
    for (int i = 1; i < m+1; i++) {
        if (collection[i] < inf) {
            inf = collection[i];
        }
    }
    cout << inf << "\n";
}

int main() {
    solve();
}
