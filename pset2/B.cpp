#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    string s;
    cin >> s;
    stack<char> t;
    string u;
    
    vector<int> rem(26, 0);

    for (ll i = 0; i < s.size(); i++) {
        rem[s[i] - 97]++;
    }

    ll it = 0;
    while (rem[it] == 0 && it < 26) {
        it++;
    }

    ll i = 0;
    while (i < s.size()) {
        
        char cur = s[i];

        rem[cur - 97]--;

        if (cur == 'a'+it) {
            u.push_back(cur);
            
            while (rem[it] == 0 && it < 25) {
                it++;
                // !! in case the next best isn't in the remaining array / is alr in the stack
                while (!t.empty() && t.top() <= 'a' + it) {
                    u.push_back(t.top());
                    t.pop();
                }
            }

        } else {
            t.push(cur);
        }

        i++;
    }

    while (!t.empty()) {
        u.push_back(t.top());
        t.pop();
    }

    cout << u << "\n";
}
