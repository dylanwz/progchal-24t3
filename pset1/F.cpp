// helped by van + collab w john s
#include <bits/stdc++.h>

using namespace std;

int arr[1001];

// tried a lot of things...
// iterate thru the invs (trying to iterate thru the array could not guarantee all inversions were used)
// so now we to make sure we use all the invs we gen
class Compare {
    public:
        bool operator()(pair<int, int> inv1, pair<int, int> inv2) {
    
            int inv1_i = arr[inv1.first];
            int inv1_j = arr[inv1.second];
            int inv2_i = arr[inv2.first];
            int inv2_j = arr[inv2.second];
            
            if (inv1_i == inv2_i) {
                if (inv1.first == inv2.first) {
                    if (inv1.second == inv2.second) return inv1_j < inv2_j; // fourth sort desc. in upper index VALUE
                    else return inv1.second < inv2.second; // third sort desc. in upper index
                }
                else return inv1.first > inv2.first; // second sort asc. in lower index
            }
            else return inv1_i > inv2_i; // first sort asc. in lower index VALUE

        }
};

int main() {
    int n;
    cin >> n;

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> invs;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[i]) invs.push(pair(i, j));
        }
    }

    cout << invs.size() << "\n";
    while (!invs.empty()) {
        pair<int, int> inv = invs.top();
        cout << (inv.first+1) << " " << (inv.second+1) << "\n";
        invs.pop();
    }

}
