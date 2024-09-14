#include <bits/stdc++.h>

using namespace std;

map<string, string> parent;
map<string, int> sizes;

string find(string s) {
    if (parent[s] == s) {
        return s;
    } else {
        return find(parent[s]);
    }
}

void join(string s1, string s2) {
    string rep1 = find(s1);
    string rep2 = find(s2);
    if (rep1 == rep2) return;
    if (sizes[s1] > sizes[s2]) { // s2 into s1
        parent[rep2] = rep1;
        sizes[rep1] += sizes[rep2];
    } else {
        parent[rep1] = rep2;
        sizes[rep2] += sizes[rep1];
    }
}

void solve() {
    
    for (int _ = 0; _ < 16; ++_) {
        string s;
        cin >> s;
        parent[s] = s;
    }
    
    int n;
    cin >> n;
    for (int _ = 0; _ < n; ++_) {
        string s1, s2;
        cin >> s1 >> s2;
        join(s1, s2);
    }
    
    map<string, vector<string>> components;
    for (const auto& p : parent) {
        string leader = find(p.first);
        components[leader].push_back(p.first);
    }

    for (const auto& c : components) {
        if (c.second.size() != 4) {
            cout << "Impossible" << "\n";
            return;
        }
    }

    cout << "Possible" << "\n";

    for (const auto& c : components) {
        if (c.second.size() == 4) {
            for (const string& s : c.second) {
                cout << s << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    solve();
}
