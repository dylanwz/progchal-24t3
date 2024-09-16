#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

vector<string> words;
unordered_map<string, int> idx;
unordered_map<int, unordered_set<int>> adj;

bool connect() {
    for (const auto& word : adj) {
        if (word.second.size() < 3) return false;
    }
    return true;
}

bool makeGroup(const vector<int> group, int w) {
    if (group.size() == 4) return false;
    for (int i : group) {
        if (adj[w].count(i) == 0) return false;
    }
    return true;
}

bool dfs(vector<vector<int>>& groups) {
    stack<pair<vector<vector<int>>, int>> stack;
    stack.push({groups, 0});

    while (!stack.empty()) {
        auto [curr, w] = stack.top();
        stack.pop();

        if (w == 16) {
            groups = curr;
            return true;
        }

        for (int i = 0; i < 4; ++i) {
            if (makeGroup(curr[i], w)) {
                curr[i].push_back(w);
                stack.push({curr, w+1});
                curr[i].pop_back();
            }
        }
    }

    return false;
}

int main() {
    string line, w;
    for (int i = 0; i < 4; ++i) {
        getline(cin, line);
        stringstream ss(line);
        while (ss >> w) words.push_back(w);
    }

    for (int i = 0; i < 16; ++i) {
        idx[words[i]] = i;
        adj[i];
    }

    int n;
    cin >> n;
    while (n--) {
        string w1, w2;
        cin >> w1 >> w2;
        adj[idx[w1]].insert(idx[w2]);
        adj[idx[w2]].insert(idx[w1]);
    }

    if (!connect()) {
        cout << "Impossible" << endl;
        return 0;
    }

    vector<vector<int>> groups(4);
    if (dfs(groups)) {
        cout << "Possible" << endl;
        for (const auto& group : groups) {
            for (const auto& w: group) {
                cout << words[w] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}