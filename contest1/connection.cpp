#include <bits/stdc++.h>

using namespace std;

map<string, set<string>> adj;
map<string, int> deg;

void dfs(string node, set<string>& vis, vector<string>& build) {
    vis.insert(node);
    build.push_back(node);
    
    for (string neighbour : adj[node]) {
        if (vis.find(neighbour) == vis.end()) {
            dfs(neighbour, vis, build);
        }
    }
}

// the crux of this prob is to find all fully connected components
// (because for SOME reason pairing isn't transitive)
bool is_ful_con(vector<string> component) {
    
    // each other node j needs to be in each i's adj list 
    for (int i = 0; i < component.size(); i++) {
        for (int j = i + 1; j < component.size(); j++) {
            if (adj[component[i]].find(component[j]) == adj[component[i]].end()) {
                return false;
            }
        }
    }
    return true;
}

void solve() {

    vector<string> words(16);
    for (int i = 0; i < 16; ++i) {
        cin >> words[i];
    }

    int n;
    cin >> n;
    
    // make adj list
    for (int i = 0; i < n; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        adj[s1].insert(s2);
        deg[s1]++;
        adj[s2].insert(s1);
        deg[s2]++;
    }

    set<string> vis;
    vector<vector<string>> groups;

    for (string w : words) {
        if (vis.find(w) == vis.end()) {
            vector<string> comp;
            dfs(w, vis, comp);

            // for (int i = 0; i < comp.size(); ++i) {
            //     cout << "PLS: " << comp[i] << ", ";
            // }
            // cout << "\n";

            if (is_ful_con(comp) && comp.size() == 4) {
                groups.push_back(comp);
            }
        }
    }

    if (groups.size() == 4) {
        cout << "Possible" << "\n";
    } else {
        cout << "Impossible" << "\n";
        return;
    }

    for (auto component : groups) {
        for (string word : component) {
            cout << word << " ";
        }
        cout << "\n";
    }
}

int main() {
    solve();
}
