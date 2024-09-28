#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> a(n);
    for (int i=0; i < n; ++i) {
        ll s, f;
        cin >> s >> f;
        a[i] = {s, f};
    }

    sort(a.begin(), a.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    multiset<ll> end;
    ll total = 0;
    for (int i=0; i < n; ++i) {
        auto min = end.lower_bound(-a[i].first);
        if (min == end.end()) {
            if (end.size() < k) {
                end.insert(-a[i].second-1);
                total++;
            }
        } else {
            end.erase(min);
            end.insert(-a[i].second-1);
            total++;
        }
    }
    cout << total << endl;
    return 0;
}