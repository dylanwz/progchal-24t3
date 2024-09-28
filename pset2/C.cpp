#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

ll N,M,S;
vector<pair<ll, ll>> bugs; // first=complexity second=index, descending in complexities; bounded by M
vector<tuple<ll, ll, ll>> students; // first=ability, second=cost, third=index; descending in abilities; bounded by N

bool is_possible(ll num_days, vector<ll> &ans) {
    
    

    priority_queue<pair<ll, ll>> costs; // first=cost, second=index; ascending

    ll total_cost = 0;

    ll it1, it2 = 0 ;
    cout << it1 << " " << M;
    while (it1 < M) {
        
        // add all students who can do this task to costs pq
        while (it2 < N && get<0>(students[it2]) >= get<0>(bugs[it1])) {
            costs.push(pair(get<1>(students[it2]), get<2>(students[it2])));
        }

        auto t = costs.top();
        
        total_cost += get<0>(t);
        costs.pop();
        for (int ind = 0; ind < num_days - 1; ind++) {
            ans[get<1>(bugs[it1])] = get<1>(t); 
        }
        it1 += (num_days - 1);
    }

    return total_cost <= S;
}

bool binary_search(ll low, ll high, vector<ll> &ans) {
    
    while (low <= high) {

        if (low == high) {
            return true;
        }

        ll mid = low + (high - low)/2;
        if (is_possible(mid, ans)) { // we can do it in x days, so let's try to make it more optimal; make the high ball lower
            high = mid;
        } else { // too ambitious; make the low ball higher
            low = mid;
        }
    }

    return false;
}

int main() {
    cin >> N >> M >> S;

    bugs.resize(M);
    vector<ll> abilities(N);
    vector<ll> passes(N);

    for (int i = 0; i < M; i++) {
        ll b;
        cin >> b;
        bugs.push_back(pair(b, i));
    }
    for (int i = 0; i < N; i++) {
        cin >> abilities[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> passes[i];
    }

    for (ll i = 0; i < N; i++) {
        students.push_back(tuple(abilities[i], passes[i], i));
    }
    
    sort(students.begin(), students.end(), greater<tuple<ll, ll, ll>>());

    sort(bugs.begin(), bugs.end(), greater<pair<ll, ll>>());

    vector<ll> ans(M);
    ll opt = binary_search(1, M, ans);

    if (!opt) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
        for (auto &e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
}