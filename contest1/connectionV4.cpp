#include <bits/stdc++.h>

using namespace std;

const int N = 16;
map<string, set<string>> adj;

// debug
void print_s(vector<string> s) {
    for (auto &c : s) {
        cout << c << " ";
    }
    cout << "\n";
}

bool is_ful_con(const vector<string>& c) {
    for (size_t i = 0; i < c.size(); i++) {
        for (size_t j = i + 1; j < c.size(); ++j) {
            if (adj[c[i]].find(c[j]) == adj[c[i]].end()) {
                return false;
            }
        }
    }
    return true;
}
// explore everyth u can and then classic backtrack to explore other options (semi brute)
void go(vector<string>& nodes, set<string>& non_vis, set<vector<string>>& res, vector<string>& cur_group, int d) {
    if (d == 4) { // found 4 nodes
        if (is_ful_con(cur_group)) { // is a clique; should add
            sort(cur_group.begin(), cur_group.end());
            res.insert(cur_group);
        }
        return;
    }

    if (non_vis.empty()) return;

    auto it = non_vis.begin();
    while (it != non_vis.end()) {
        string new_s = *it;
        non_vis.erase(it++);
        
        cur_group.push_back(new_s);
        go(nodes, non_vis, res, cur_group, d + 1);
        cur_group.pop_back(); // explored as far as can so backtrack and go try other opts

        non_vis.insert(new_s);
    }
}

bool is_uniq(const vector<vector<string>>& sets) {
    set<string> u;
    for (const auto& ws : sets) {
        for (const auto& word : ws) {
            if (!u.insert(word).second) {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    vector<string> words(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }

    int edgeCount;
    cin >> edgeCount;

    set<string> nonVis;
    for (int i = 0; i < edgeCount; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        adj[s1].insert(s2);
        adj[s2].insert(s1);
        nonVis.insert(s1);
        nonVis.insert(s2);
    }

    set<vector<string>> cliques;
    vector<string> currentClique;
    
    go(words, nonVis, cliques, currentClique, 0);

    if (cliques.size() < 4) {
        cout << "Impossible\n";
        return;
    }

    vector<vector<string>> clique = vector(cliques.begin(), cliques.end());
    vector<vector<string>> ans;
    for (int i = 0; i < cliques.size() - 3; ++i) {
        for (int j = i + 1; j < cliques.size() - 2; ++j) {
            for (int k = j + 1; k < cliques.size() - 1; ++k) {
                for (int l = k + 1; l < cliques.size(); ++l) {
                    vector<vector<string>> selectedSets = { clique[i], clique[j], clique[k], clique[l] };
                    if (is_uniq(selectedSets)) {
                        ans = selectedSets;
                        cout << "Possible" << "\n";
                        for (auto &e : ans) {
                            for (auto &f : e) {
                                cout << f << " ";
                            }
                            cout << "\n";
                        }
                        return;
                    }
                }
            }
        }
    }
    cout << "Impossible\n";
}

int main() {
    solve();
}
