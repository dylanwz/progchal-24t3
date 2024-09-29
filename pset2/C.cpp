#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N,M,S;
vector<pair<ll, ll>> bugs; // first=complexity, second=index, descending in complexities; bounded by M
vector<tuple<ll, ll, ll>> students; // first=ability, second=cost, third=index; descending in abilities; bounded by N

bool is_possible(ll num_days, vector<ll> &ans) {
    
    // for every bug, we want to push all those who can do that bug (non-decreasing over bugs)
    // and rank them based on cost, taking the cheapest and assigning them the next n days

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> candidates; // first=cost, second=index; ascending

    ll total_cost = 0;
    vector<ll> temp_ans(M);

    ll it1 = 0, it2 = 0 ;
    while (it1 < M) { // for each bug

        // add all students who can do this task to costs pq; iterator2 ends up on next student who cannot
        while (it2 < N && get<0>(students[it2]) >= get<0>(bugs[it1])) { //
            candidates.push(pair(get<1>(students[it2]), get<2>(students[it2])));
            it2++;
        }
        if (candidates.empty()) {
            return false;
        }
        auto t = candidates.top();
        candidates.pop();

        total_cost += get<0>(t); // add the cost of this cheapest student
        // cout << "total cost: " << total_cost << "\n";

        ll greedy = it1 + num_days - 1;
        while (it1 <= greedy && it1 < M) { // choose this student for next num_days - 1 days and update answer            
            // cout << it1 << ", bug at ind " << get<1>(bugs[it1]) << " of compl. " << get<0>(bugs[it1]) << "...  student of compl " << get<0>(t) << " of id " << get<1>(t) << "\n";   
            temp_ans[get<1>(bugs[it1])] = get<1>(t);
            it1++;
        }
        // cout << it1 << " hey!\n";
    }

    // cout << "hi!\n";
    if (total_cost <= S) {
        // cout << "updating answer to: ";
        for (auto &e : temp_ans) {
            // cout << e << ", ";
        }
        // cout << "\n";
        ans = temp_ans;
        return true;
    } else {
        // cout << "uh oh\n";
        return false;
    }
}

bool binary_search(ll low, ll high, vector<ll> &ans) {

    while (low <= high) {

        ll mid = low + (high - low)/2;
        // cout << "low: " << low << ", mid: " << mid << ", high: " << high << "\n";
        if (is_possible(mid, ans)) { // we can do it in x days, so let's try to make it more optimal; make the high ball lower
            high = mid - 1;
            // cout << "... works\n";
        } else { // too ambitious; make the low ball higher
            low = mid + 1;
            // cout << "... doesn't work\n";
        }
        
    }
    // cout << "low: " << low << ", high: " << high << "\n";
    if (ans[0] != 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> N >> M >> S;

    bugs.resize(M);
    vector<ll> abilities(N);
    vector<ll> passes(N);

    for (int i = 0; i < M; i++) {
        ll b;
        cin >> b;
        bugs[i] = pair(b, i);
    }
    for (int i = 0; i < N; i++) {
        cin >> abilities[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> passes[i];
    }
    for (ll i = 0; i < N; i++) {
        students.push_back(tuple(abilities[i], passes[i], i+1));
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