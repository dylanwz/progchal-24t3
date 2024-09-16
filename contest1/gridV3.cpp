#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

const int N = 16;
map<string, set<string>> adj;

// Function to check if a given set of 4 nodes forms a fully connected clique
bool isFullyConnected(const vector<string>& component) {
    for (size_t i = 0; i < component.size(); ++i) {
        for (size_t j = i + 1; j < component.size(); ++j) {
            if (adj[component[i]].find(component[j]) == adj[component[i]].end()) {
                return false;
            }
        }
    }
    return true;
}

// Function to generate all 4-combinations of nodes and check if they are fully connected
void generateCliques(vector<string>& nodes, vector<vector<string>>& cliques) {
    int n = nodes.size();
    // Iterate over all combinations of 4 nodes
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                for (int l = k + 1; l < n; ++l) {
                    vector<string> clique = {nodes[i], nodes[j], nodes[k], nodes[l]};
                    if (isFullyConnected(clique)) {
                        cliques.push_back(clique);
                    }
                }
            }
        }
    }
}

void solve() {
    vector<string> words(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }

    int edgeCount;
    cin >> edgeCount;

    // Initialize the adjacency list
    for (int i = 0; i < edgeCount; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        adj[s1].insert(s2);
        adj[s2].insert(s1);
    }

    vector<vector<string>> cliques;
    generateCliques(words, cliques);

    // Check if exactly four distinct 4-cliques were found
    if (cliques.size() < 4) {
        cout << "Impossible\n";
    } else {
        set<set<string>> uniqueCliques;
        for (const auto& clique : cliques) {
            set<string> cliqueSet(clique.begin(), clique.end());
            uniqueCliques.insert(cliqueSet);
        }

        if (uniqueCliques.size() == 4) {
            cout << "Possible\n";
            for (const auto& cliqueSet : uniqueCliques) {
                for (const auto& node : cliqueSet) {
                    cout << node << " ";
                }
                cout << "\n";
            }
        } else {
            cout << "Impossible\n";
        }
    }
}

int main() {
    solve();
    return 0;
}
