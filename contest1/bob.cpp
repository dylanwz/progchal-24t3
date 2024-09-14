#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<pair<long long, long long>> jobs(n);
    for (int _ = 0; _ < n; _++) {
        long long a,b;
        cin >> a >> b;
        jobs.push_back(pair(a,b));
    }
    sort(jobs.begin(), jobs.end());

    long long cum_t = 0;
    long long cum_m = 0;
    for (int i = 0; i < jobs.size(); i++) {
        cum_m += jobs[i].second - jobs[i].first - cum_t;
        cum_t += jobs[i].first;
    }
    cout << cum_m << "\n";
}

int main() {
    solve();
}
