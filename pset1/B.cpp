// Solved

#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

pair<long long, long long> sum_signed_seq(vector<long long> arr, bool pos_signed) {
    long long sum = LONG_LONG_MIN; long long length = 0; 
    bool pos = pos_signed ? true : false;
    size_t ind = 0;

    if (pos_signed) {
        while (ind < arr.size()) {
            if (arr[ind] < 0) {
                ind++;
            } else {
                break;
            }
        } // now ind is the index of the first positive number
    } else {
        while (ind < arr.size()) {
            if (arr[ind] >= 0) { // should look for first negative number
                ind++;
            } else {
                break;
            }
        } // now ind is the index of the first negative number
    }

    if (ind < arr.size()) sum = 0;

    // alternate between positive and negative subsequences
    while (ind < arr.size()) {
        long long max_seen = LONG_LONG_MIN;
        if (pos) { // looking for positive numbers
            while (ind < arr.size() && arr[ind] > 0) {
                long long c = arr[ind];
                if (c > max_seen) max_seen = c;
                ind++;
            }
        } else { // looking for negative numbers
            while (ind < arr.size() && arr[ind] < 0) {
                long long c = arr[ind];
                if (c > max_seen) max_seen = c;
                ind++;
            }
        }
        if (max_seen != LONG_LONG_MIN) {
            sum += max_seen;
            length++;
        }
        pos = !pos; // switch
    }

    return pair(sum, length);
}


void solve() {
    vector<long long> ans;
    long long n; 
    cin >> n; 

    for (size_t i = 0; i < n; i++) {
        long long m; 
        cin >> m;
        vector<long long> arr(m);

        for (size_t j = 0; j < m; j++) {
            cin >> arr[j];
        }

        pair<long long, long long> pos = sum_signed_seq(arr, true);
        pair<long long, long long> neg = sum_signed_seq(arr, false);
        if (pos.second == neg.second) {
            long long max_sum = pos.first > neg.first ? pos.first : neg.first; 
            ans.push_back(max_sum);
        }
        else {
            if (pos.second > neg.second) {
                ans.push_back(pos.first);
            } else {
                ans.push_back(neg.first);
            }
        }
    }

    for (auto e : ans) {
        cout << e << "\n";
    }
}


int main() {
    solve();
}