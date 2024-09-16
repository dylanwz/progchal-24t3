#include <bits/stdc++.h>

using namespace std;

const int N = 16;
map<string, set<string>> adj;
set<vector<vector<string>>> parts;

bool is_fc(const vector<string>& vv) {
    for (int i = 0; i < vv.size(); i++) {
        for (int j = i+1; j < vv.size(); ++j) {
            if (adj[vv[i]].find(vv[j]) == adj[vv[i]].end()) {
                return false;
            }
        }
    }
    return true;
}

void gen_combs(const vector<string>& words, vector<vector<string>>& combs) {
    int size = words.size();
    for (int i = 0; i < size - 3; i++) {
        for (int j = i + 1; j < size - 2; ++j) {
            for (int k = j + 1; k < size - 1; ++k) {
                for (int l = k + 1; l < size; ++l) {
                    vector<string> build = {words[i], words[j], words[k], words[l]};
                    combs.push_back(build);
                }
            }
        }
    }
}

void solve() {
    vector<string> words(16);
    for (int i = 0; i < 16; i++) {
        cin >> words[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        adj[s1].insert(s2);
        adj[s2].insert(s1);
    }

    vector<vector<string>> all_combs;
    set<vector<vector<string>>> seen;
    gen_combs(words, all_combs);

    for (int i = 0; i < all_combs.size(); i++) {
        vector<string> g1 = all_combs[i];
        set<string> g1_set(g1.begin(), g1.end());

        vector<string> rem;
        for (const auto& word : words) {
            if (g1_set.find(word) == g1_set.end()) {
                rem.push_back(word);
            }
        }

        vector<vector<string>> all_combs2;
        gen_combs(rem, all_combs2);

        for (int j = 0; j < all_combs2.size(); j++) {
            vector<string> g2 = all_combs2[j];
            set<string> g2_set(g2.begin(), g2.end());

            vector<string> rem2;
            for (const auto& word : rem) {
                if (g2_set.find(word) == g2_set.end()) {
                    rem2.push_back(word);
                }
            }

            vector<vector<string>> all_combs3;
            gen_combs(rem2, all_combs3);

            for (int k = 0; k < all_combs3.size(); k++) {
                vector<string> g3 = all_combs3[k];
                set<string> g3_set(g3.begin(), g3.end());

                vector<string> g4;
                for (const auto& word : rem2) {
                    if (g3_set.find(word) == g3_set.end()) {
                        g4.push_back(word);
                    }
                }

                if (g4.size() != 4) {
                    continue; // Ensure g4 has exactly 4 elements
                }
                cout << i << " " << j << " " << k << "\n";
                vector<vector<string>> part = {g1, g2, g3, g4};
                seen.insert(part);
            }
        }
    }

    cout << "here?\n";
    for (const auto& part : seen) {
        int c = 0;
        vector<vector<string>> valids;
        for (const auto& g : part) {
            if (is_fc(g)) {
                c++;
                valids.push_back(g);
            }
        }
        if (c == 4) {
            cout << "Possible" << "\n";
            for (const auto& m : valids) {
                for (const auto& e : m) {
                    cout << e << " ";
                }
                cout << "\n";
            }
            return;
        }
    }
    cout << "Impossible" << "\n";
}

int main() {
    solve();
}
