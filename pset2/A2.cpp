#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    // ascending finish then start times
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> classes;

    for (long long i = 0; i < n; i++) {
        long long s, f;
        cin >> s >> f;
        classes.push(pair(f, s));
    }

    // descending finish times of classes in session in classrooms
    multiset<long long, greater<long long>> in_session;
    
    long long count = 0;
    while (!classes.empty()) {
        pair<long long, long long> p = classes.top();
        classes.pop();

        long long finish = p.first;
        long long start = p.second;
        
        if (in_session.size() < k) {
            if (in_session.size() > 0 && in_session.lower_bound(start) == in_session.begin()) { // edge case where all activities are done
                in_session.clear();
                in_session.insert(finish);
                count++;
                continue;
            }
            in_session.insert(finish);
            count++;
            continue;
        }
        
        // find the biggest finish time less than this current interval's start time
        auto it = in_session.upper_bound(start);
        if (it != in_session.end()) {
            if (in_session.lower_bound(start) == in_session.begin()) { // edge case where all activities are done
                in_session.clear();
                in_session.insert(finish);
                count++;
                continue;
            }
            in_session.erase(it);
            in_session.insert(finish);
            count++;
        }

    }

    std::cout << count << "\n";
}
